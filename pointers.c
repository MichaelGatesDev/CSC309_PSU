#include <stdio.h>



void getDate(int *month, int *day, int *year)
{
    *month = 4;
    *day = 5;
    *year = 1997;
    return;
}


int main()
{
    int month, day, year;

    getDate(&month, &day, &year);
    printf("Date: %d/%d/%d\n", month, day, year);

    return 0;
}
