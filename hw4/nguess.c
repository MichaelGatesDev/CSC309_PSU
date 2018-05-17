/*
    Michael Gates
    16 April 2018
*/
#include <stdio.h>
#include <stdlib.h>


struct listElement
{
    int i;
    struct listElement *next;
};


struct listElement *generateList(int size)
{
    struct listElement *listHead = 0;
    struct listElement *current = 0;

    // seed random number generator
    srand(time(0));

    // Create list
    int i;
    for(i=0; i<size; i++)
    {
        current = malloc(sizeof(struct listElement)); // creates a new object in memory of struct listElement
        current->i = (int) ((double) rand() / RAND_MAX * 12); // set i to random int

        current->next = listHead; // the next element is the list head
        listHead = current; // list head is now this element
    }

    return listHead;
}

void printSingleLineList(struct listElement *head)
{
    struct listElement *current = 0;
    for(current = head; current; current = current->next)
    {
        int value = current->i;
        printf("%d ", value);
    }
}


int numOfDigits(int n)
{
    if(n == 0)
    {
        return 1;
    }

    int count = 0;
    while(n != 0)
    {
        n /= 10;
        ++count;
    }

    return count;
}


void checkGuess(int guess, struct listElement *head)
{
    int gi = 0;
    char generated[100];

    int pfai = 0;
    int positionsFoundAt[] = {};

    int pos=0;
    int occurrences = 0;
    // Loop through the list
    struct listElement *current;
    for(current = head; current; current = current->next)
    {
        int value = current->i;
        // if the number guessed is in the list
        if(value == guess)
        {
            positionsFoundAt[pfai] = pos;
            pfai++;
            occurrences++;
        }
        // generated[gi] = current->i;
        // printf("There are %d digits in %d\n", numOfDigits(value), value);
        pos++;
    }

    if(occurrences > 0)
    {
        printf("Good guess! Found in position(s): ");
        for(int i=0; i<pfai; i++)
        {
            printf("%d ", positionsFoundAt[i]);
        }
        printf("\n");
        printf("Found %d times in total :)\n", occurrences);
    }
    else
    {
        printf("Guess not found :(\n");
        printf("Better luck next time :)\n");
    }

    printSingleLineList(head);
    printf("\n");
}


int main()
{
    int size = 8;
    struct listElement *listHead = generateList(size);

    // Ask for a guess
    unsigned int guess;
    printf("Guess a number from 0 to 11: ");
    scanf("%d", &guess);
    printf("\n");

    // Check guess
    checkGuess(guess, listHead);

    return 0;
}
