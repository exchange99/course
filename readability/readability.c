// Grades the readability of a text with the Coleman-Liao Index
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int compute_grade(int letters, int words, int sentences, string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = compute_grade(letters, words, sentences, text);

    // Call out grade!
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

// Done
// Calculates the grade rating
int compute_grade(int letters, int words, int sentences, string text)
{
    float grade = 0;

    // int index = 0.0588 * L - 0.296 * S - 15.8
    float L = 0;
    float S = 0;

    L = ((float) letters / (float) words) * 100;
    S = ((float) sentences / (float) words) * 100;

    grade = 0.0588 * L - 0.296 * S - 15.8;
    grade = round(grade);

    return grade;
}

// Done,
// Counts letters
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            letters++;
        }
        else if (islower(text[i]))
        {
            letters++;
        }
    }
    // printf("Letters: %i\n", letters);
    return letters;
}

// Done
// Counts words (spaces + 1)
int count_words(string text)
{
    int words = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    // printf("Words: %i\n", words);
    return words;
}

// Done
// Counts sentences by filtering '.', '!' and '?' out of non alphanumerical chars.
int count_sentences(string text)
{
    int sent = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!isalnum(text[i]))
        {
            char c = text[i];

            switch (c)
            {
                case '.':
                    sent++;
                    break;
                case '!':
                    sent++;
                    break;
                case '?':
                    sent++;
                    break;
            }
        }
    }
    // printf("Sentences: %i\n", sent);
    return sent;
}