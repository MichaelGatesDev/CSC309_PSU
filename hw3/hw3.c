/*
    Michael Gates
    20 March 2018

    Homework 3
    •Please write a C program that
    1.accepts any number of command-line arguments
    2.Copies those arguments into a single array, separated by spaces
    –You can reject or chop inputs that exceed a certain length, perhaps 100 characters
    3.Prints this single long string to the terminal
    4.Prints this string backwards to the terminal

    For example, if your program is called hwk3:

    >hwk3 Mary had a little lamb
    Mary had a little lamb
    bmal elttil a dah yrraM

    Notice that the input is given to the program as command-line arguments;
    that is, as additional words following the name of the program, before hitting enter.
    This exercise does not use the scanf() function.
    It may be useful to review section 5.7 of the GNU C Reference manual (link)
    and experiment a bit with the example code provided.

    I have posted a compiled example program (commandArgsDemo)
    and a possible framework (commandArgs.c) to the moodle page.
    The example program should run on the lab's Linux computers, it won't run on a windows computer.
    It will probably be necessary to make it an executable file after downloading it
    (chmod u+x commandArgsDemo, on the command line).
    The framework contains my suggestions for functions you could create to solve this assignment.

    Note that while C's standard library does include programs for manipulating strings,
    for the purposes of this exercise I don't want you to use them.
*/


#include <stdio.h>


int _strlen(char c[])
{
    int len = 0;
    while (c[len++] != '\0');
    return len;
}

int main(int argc, char *argv[])
{
    // get size to allocate into array
    int bufferSize = 0;
    for(int a=1; a<argc; a++)
    {
        char *arg = argv[a];
        int argSize = _strlen(arg)-1;
        bufferSize += argSize;
        //printf("Size of arg (%s) is %d\n", arg, argSize);
    }
    int numOfSpaces = argc-2; // no space at end
    bufferSize += numOfSpaces;
    bufferSize++; // add space for end of string char


    // parse command line args to string
    char buffer[bufferSize];
    //printf("size of buffer is %d\n", bufferSize);
    int i = 1;  // arguments start at 1
    int k = 0;  // amount of words
    for(i=1; i<argc; i++)
    {
        int j = 0;
        char *arg = argv[i];

        //printf("Arg %d is %s\n", i, arg);

        while(arg[j] != '\0')
        {
            char c = argv[i][j];

            //printf("char c = argv[%d][%d]\n", i, j);
            buffer[k] = c;
            //printf("buf[%d] = %c\n", k, c);
            k++;

            j++;
        }
        // add space between words, but not the last one
        if(i < argc-1)
        {
            buffer[k] = ' ';
            k++;
        }
    }
    buffer[k] = '\0';

    // print original message
    printf("%s\n", buffer);

    // reverse
    int size = sizeof(buffer)-1;
    char backwardsBuffer[size];
    int j=0;
    for(i=size-1; i>=0; i--)
    {
        char c = buffer[i];
        //printf("%c %d\n", c, j);
        backwardsBuffer[j] = c;
        j++;
    }
    backwardsBuffer[size] = '\0';
    printf("%s\n", backwardsBuffer);

    return 0;
}
