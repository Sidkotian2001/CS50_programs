#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int k, string j[])
{
    if (k != 2)//checks if key correct
    {
        printf("failure\n");
        return 1;
    }
    string str1 = j[1];
    int len = strlen(str1), q;
    for (q = 0; q < len; q++)
    {
        char ch = str1[q];
        if (isdigit(ch) == 0)
        {
            printf("./caesar key\n");
            return 1;
        }
    }
    int n = atoi(j[1]);//converts string to integer
    string s = get_string("plaintext: ");//asks for plaintext
    printf("ciphertext: ");
    string str = "" ;
    int i;
    char ch;
    for (i = 0; i < strlen(s); i++)
    {
        ch = s[i];
        if (ch >= 97 && ch <= 122)//checks for lowercase alphabets
        {
            ch = ch - 97;
            ch = (ch + n) % 26;
            ch = ch + 97;
            printf("%c", ch);
        }
        else if (ch >= 65 && ch <= 90)//checks for uppercase alphabets
        {
            ch = ch - 65;
            ch = (ch + n) % 26;
            ch = ch + 65;
            printf("%c", ch);
        }
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");
    return 0;
