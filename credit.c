#include <stdio.h>
#include <cs50.h>
long get_number(void);
void alg();
int main(void)
{
    alg();
}
long get_number()
{
    long numb ;
    do
    {
        numb = get_long("enter credit number: ") ;
    }
    while (numb <= 0) ;
    return numb ;
}
void alg()
{
    long num = get_number();
    long n = num ;
    int c1 = 0, c2 = 0, s1 = 0, s2 = 0, s, k1, k2, k3, k4, len = 0, h, n1, n2, m ;
    while (n > 0) //checks if credit number follows Luhn’s Algorithm
    {
        k1 = n % 10 ;
        c1++;
        if (c1 % 2 == 0)
        {
            h = k1 * 2 ;
            while (h > 0) // adds the sum of all the digits multiplied by 2
            {
                k4 = h % 10 ;
                s1 = s1 + k4 ;
                h = h / 10 ;
            }
        }
        else
        {
            s2 = s2 + k1 ; //adds the sum of the remaining digits
        }
        n = n / 10 ;
    }
    
    s = s1 + s2 ; //adds the sum of all digits multiplied by 2 and the remaining ones
    n = num ;
    
    while (n > 0) // finds length of credit number
    {
        k2 = n % 10 ;
        len++ ;
        n = n / 10 ;
    }
    
    n = num ;
     
    while (n > 0) // extracts the first two digits of the credit number
    {
        k3 = n % 10 ;
        c2++;
        if (c2 == len)
        {
            n1 = k3 ; // extrats first digit
        }
        if (c2 == (len - 1))
        {
            n2 = k3 ;//extracts second digit
        }
        n = n / 10 ;
    }
     
    n = num ;
    m = (n1 * 10) + n2 ; // finds the first two digit number from the original credit number
     
    if (s % 10 == 0) //checks if the credit number is AMEX or MASTERCARD or VISA
    {
        if (len == 15 && (m == 34 || m == 37))
        {
            printf("AMEX\n") ;
            
        }
        else if ((len == 13 || len == 16) && k1 == 4)
        {
            printf("VISA\n") ;
            
        }
        else if (len == 16 && (m == 51 || m == 52 || m == 53 || m == 54 || m == 55))
        {
            printf("MASTERCARD\n") ;
                
        }
        else
        {
            printf("INVALID\n") ;
        }
    }
    else //prints INVALID if the credit number is fake
    {
        printf("INVALID\n") ;
    }
}

