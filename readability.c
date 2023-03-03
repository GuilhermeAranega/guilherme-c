#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>


int l(string text);
int w(string text);
int s(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = l(text);
    int words = w(text);
    int sentences = s(text);

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

//count for letters
int l(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}

//count for words
int w(string text)
{
    int words = 0;
    bool reading_word = false;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            reading_word = false;
        }
        else if (isalpha(text[i]))
        {
            if (!reading_word)
            {
                reading_word = true;
                words++;
            }
        }
    }
    return words;
}

//count for sentences
int s(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
 
