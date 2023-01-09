#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
void alg();
int main(void) //main function
{
    alg();
}
void alg()
{
    string s = get_string(" sentence: \n");
    int n = strlen(s), i, c = 0, letter = 0, sentence = 0;
    for (i = 0; i < n; i++) //for loop begins
    {
        if (s[i] == 32)
        {
            c++;
        }
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            letter++;
        }
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            sentence++;
        }
    } //for loop ends
    int words = c + 1;
    float l = letter, w = words, s2 = sentence; //converting variables to float
    float L = (l / w) * 100;
    float S = (s2 / w) * 100;
    float ind = 0.0588 * L - 0.296 * S - 15.8; //algorithm expression
    int index = round(ind); //rounding the index vaue
    if (index < 1)
    {
        printf(" Before Grade 1\n"); //printing before grade 1
    }
    else if (index >= 16)
    {
        printf(" Grade 16+\n"); //if grade is 16 or higher
    }
    else
    {
        printf(" Grade %d\n", index); //if grade is between 1 and 16
    }

}