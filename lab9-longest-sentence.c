#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sentence Sentence;

struct Sentence
{
    char word[20];
};

void get_words(int *len, char *argv[], Sentence *words, int *longest);
void print_longest(int *longest, int *len, Sentence *words);

int main(int argc, char *argv[])
{
    int len = argc - 1;

    Sentence *words = malloc(len * sizeof(*words));
    if (!words)
    {
        printf("Error allocating memory!\n");
        exit(0);
    }
    int longest = 0;
    get_words(&len, argv, words, &longest);
    print_longest(&longest, &len, words);
    free(words);
    return 0;
}

void get_words(int *len, char *argv[], Sentence *words, int *longest)
{
    for (int i = 0; i < *len; ++i)
    {
       Sentence *ptr = &words[i];
       strcpy(ptr->word, argv[i + 1]);
       int word_length = strlen(ptr->word);

       if (word_length > *longest)
       {
         *longest = strlen(ptr->word);
       }

    }
}

void print_longest(int *longest, int *len, Sentence *words)
{
    for (int i = 0; i < *len; ++i)
    {
        Sentence *ptr = &words[i];
        if (strlen(ptr->word) == *longest)
        {
            printf("%s\n", ptr->word);
        }
    }
}