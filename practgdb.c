#include <stdio.h>

int concat(char[], char[], int *);

void printreverse(char[], int);

#define MAX_CHARS 1000

int main( int argc, char *argv[])
{
    char longstring[MAX_CHARS] = {'\0'};
    int i = 0;
    int j;
    if(argc < 2)
    {
        printf("%s requires command-line args\n", argv[0]);
        return 1;
    }
    for(j = 1; j <= argc; j++)
    {
        if(concat(argv[j], longstring, &i))
            return 1;
    }
    i--;
    longstring[i] = '\0'; //delete trailing space
    printf("%s\n", longstring);
}

int concat(char nextstr[], char longstr[], int *i)
{
    int j = 0;
    while(nextstr && nextstr[j] != '\0')
    {
        longstr[*i] = nextstr[j];

        (*i)++;
        j++;

        if(*i > MAX_CHARS)
        {
            printf("Error: Input is too long!\n");
            return 1;
        }
    }
    if(j > 0)
    {
        if((*i) + 2 > MAX_CHARS)
        {
            printf("Error: Input is too long!\n");
            return 1;
        }

        longstr[*i] = ' ';
        longstr[(*i)+1] = '\0';
        (*i)++;
    }

    return 0;
}
