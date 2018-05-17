/*
    Driving Test
    -------------

    Using the code we started together in class, please create a program that

    1) randomly generates the results of a user-specified number of driving tests.

    You should 2) use at least 9 possible infractions when generating the tests.

    You should 3) store the test results in a linked list of integers.

    Then 4) loop through the linked list, printing the results of each test to the terminal.

    In the name of good coding practice, you should:
        5a) use a function to create the linked list.
        5b) use a function to randomly generate the outcome of a single driving test.
        5c) use a function to print the results of a single driving test.  Don't put all your code in main().

    20 points extra credit) Use a bitshift operator (<< or >>) and a loop to count the number of infractions on each test.

    -- doesn't care as long as it's random and it's possible to pass and follows conventions
*/

#include "drivingtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // seed random number generator
    srand(time(0));


    // Input number of tests to run
    unsigned int numTests;
    printf("How many tests should I conduct? ");
    scanf("%d", &numTests);
    printf("\n");


    struct testResult *listHead = generateTests(numTests);
    printTestResults(listHead);


    /*
    short result = generateRandomResult();
    printf("0x%02X\n", result);
    printBinary(result);
    printf("\n");
    */

    return 0;
}



struct testResult *generateTests(int size)
{
    struct testResult *listHead = 0;
    struct testResult *current = 0;

    // Create list
    int i;
    for(i=0; i<size; i++)
    {
        current = malloc(sizeof(struct testResult)); // creates a new object in memory of struct testResult
        current->result = generateRandomResult(); // generates a random test result
        current->next = listHead; // the next element is the list head
        listHead = current; // list head is now this element
    }

    return listHead;
}

short generateRandomResult()
{
    //short n = rand();
    //return (short) (0x1FF & n);

    short result = 0x000; // 000000000

    int perfectScore = 100;
    int difficultyThreshold = 10;
    int maxMistakeScore = perfectScore - difficultyThreshold; // this determines how 'difficult' it is to get a passing (0 mistake) score
    int scoreInterval = maxMistakeScore / TOTAL_INFRACTIONS;
    int maxPossibleMistakes = maxMistakeScore / scoreInterval;

    int randomScore = rand() % perfectScore; // generates a random number between 0 and 100 (inclusive
    int mistakes = randomScore < perfectScore - difficultyThreshold ? maxPossibleMistakes - (randomScore / scoreInterval) : 0;


    // for (int i=0; i<=100; i++)
    // {
    //     printf("%d percent = %d mistakes\n", i, maxPossibleMistakes - (i / scoreInterval));
    // }
    // 99-100%  chance = 0 Mistakes
    // 88-98%   chance = 1 Mistakes
    // 77-87%   chance = 2 Mistakes
    // 66-76%   chance = 3 Mistakes
    // 55-65%   chance = 4 Mistakes
    // 44-54%   chance = 5 Mistakes
    // 33-43%   chance = 6 Mistakes
    // 22-32%   chance = 7 Mistakes
    // 11-21%   chance = 8 Mistakes
    // 10-0%   chance = 9 Mistakes

    // apply number of mistakes
    for(int i=0; i<mistakes; i++)
    {
        // 0x000000000 & 0x000000001
        if(!(result & TOO_FAR_FROM_CURB))
        {
            result |= TOO_FAR_FROM_CURB;
            // printf("Set flag #%d: TOO_FAR_FROM_CURB\n", i+1);
        }
        else if(!(result & UNABLE_TO_PARK_PROPERLY))
        {
            result |= UNABLE_TO_PARK_PROPERLY;
            // printf("Set flag #%d: UNABLE_TO_PARK_PROPERLY\n", i+1);
        }
        else if(!(result & FAILURE_TO_CHECK_BLINDSPOTS))
        {
            result |= FAILURE_TO_CHECK_BLINDSPOTS;
            // printf("Set flag #%d: FAILURE_TO_CHECK_BLINDSPOTS\n", i+1);
        }
        else if(!(result & POOR_JUDGEMENT_SPEEDING))
        {
            result |= POOR_JUDGEMENT_SPEEDING;
            // printf("Set flag #%d: POOR_JUDGEMENT_SPEEDING\n", i+1);
        }
        else if(!(result & POOR_JUDGEMENT_TURNING))
        {
            result |= POOR_JUDGEMENT_TURNING;
            // printf("Set flag #%d: POOR_JUDGEMENT_TURNING\n", i+1);
        }
        else if(!(result & POOR_JUDGEMENT_STOPPING))
        {
            result |= POOR_JUDGEMENT_STOPPING;
            // printf("Set flag #%d: POOR_JUDGEMENT_STOPPING\n", i+1);
        }
        else if(!(result & POOR_JUDGEMENT_SIGNALING))
        {
            result |= POOR_JUDGEMENT_SIGNALING;
            // printf("Set flag #%d: POOR_JUDGEMENT_SIGNALING\n", i+1);
        }
        else if(!(result & FAILURE_TO_KEEP_RIGHT))
        {
            result |= FAILURE_TO_KEEP_RIGHT;
            // printf("Set flag #%d: FAILURE_TO_KEEP_RIGHT\n", i+1);
        }
        else if(!(result & IMPROPER_LANE))
        {
            result |= IMPROPER_LANE;
            // printf("Set flag #%d: IMPROPER_LANE\n", i+1);
        }
        else
        {
            printf("Error: Max mistakes set! No bits left for flag.\n"); // this should never fire
        }
    }

    // printf("maxPossibleScore %d | scoreInterval %d | maxPossibleMistakes %d | randomScore %d | mistakes %d\n", maxPossibleScore, scoreInterval, maxPossibleMistakes, randomScore, mistakes);
    // printf("Result: ");
    // printBinary(result);
    // printf("\n");


    return result;
}

void printTestResults(struct testResult *head)
{
    int counter=1;
    struct testResult *current = 0;
    for(current = head; current; current = current->next)
    {
        short result = current->result;

        printf("Test %d Result:\n", counter);
        printTestResult(result);

        counter++;
        printf("\n");
    }
}

void printTestResult(short result)
{
    if(result & TOO_FAR_FROM_CURB)
        printf("Student parked too far from curb.\n");
    if(result & UNABLE_TO_PARK_PROPERLY)
        printf("Student was unable to park properly.\n");
    if(result & FAILURE_TO_CHECK_BLINDSPOTS)
        printf("Student failed to check blindspots.\n");
    if(result & POOR_JUDGEMENT_SPEEDING)
        printf("Student had poor judgement speeding.\n");
    if(result & POOR_JUDGEMENT_TURNING)
        printf("Student had poor judgement turning.\n");
    if(result & POOR_JUDGEMENT_STOPPING)
        printf("Student had poor judgement stopping.\n");
    if(result & POOR_JUDGEMENT_SIGNALING)
        printf("Student had poor judgement signaling.\n");
    if(result & FAILURE_TO_KEEP_RIGHT)
        printf("Student failed to keep right.\n");
    if(result & IMPROPER_LANE)
        printf("Student drove in the improper lane.\n");

    int totalInfractions = countBitsSet(result);
    printf("Total of %d infraction(s).\n", totalInfractions);
}

// FOR EXTRA CREDIT
int countBitsSet(short n)
{
    int total = 0;
    while (n > 0)
    {
        if((n & 1) == 1)
            total++;
        n >>= 1;
    }
    return total;
}


// print bits of an unsigned number, used for testing (NOT MY CODE)
// taken from https://www.geeksforgeeks.org/binary-representation-of-a-given-number//
void printBinary(unsigned n)
{
    if (n > 1) printBinary(n/2);
    printf("%d", n % 2);
}
