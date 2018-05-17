#include <stdio.h>

// Michael Gates
// CSC309A
// 20 February 2017
// Temperature conversion table in C

// Please make a program (using the provided starting code) that outputs a table of temperatures in Celsius, Kelvin, and Fahrenheit that fall between a user-specified starting and ending temperature.


void printTable(char unit, double lowTemp, double highTemp, double interval);

double farenheitToCelcius(double temp);
double farenheitToKelvin(double temp);
double celciusToFarenheit(double temp);
double celciusToKelvin(double temp);
double kelvinToFarenheit(double temp);;
double kelvinToCelcius(double temp);

int main()
{
    double lowTemp;
	double highTemp;
	double interval;
	char unit;
	printf("Enter unit (F, C, or K): ");
	scanf("%c", &unit);
	if(unit != 'C' && unit != 'K' && unit != 'F'){
		printf("Bad input!\n");
		return 1;
	}
	while (getchar() != '\n');   //Flush stdin
	printf("\nEnter low temperature: ");
	scanf("%lf", &lowTemp);
	while (getchar() != '\n');   //Flush stdin
	printf("\nEnter high temperature: ");
	scanf("%lf", &highTemp);
	while (getchar() != '\n');   //Flush stdin
	printf("\nEnter table interval: ");
	scanf("%lf", &interval);

    // print table
    printTable(unit, lowTemp, highTemp, interval);

    return 0;
}

void printTable(char unit, double lowTemp, double highTemp, double interval)
{
    printf("\n%f%c to %f%c counting by %f\n\n", lowTemp, unit, highTemp, unit, interval);

    double i;
    double last;

    double inF;
    double inC;
    double inK;
    switch(unit)
    {
        case 'F':
            printf("F\t\tC\t\tK\n");
            for(i=lowTemp; i<=highTemp; i+=interval)
            {
                inC = farenheitToCelcius(i);
                inK = farenheitToKelvin(i);
                last = i;

                printf("%f\t%f\t%f\n", i, inC, inK);
            }
            break;
        case 'C':
            printf("C\t\tF\t\tK\n");
            for(i=lowTemp; i<=highTemp; i+=interval)
            {
                inF = celciusToFarenheit(i);
                inK = celciusToKelvin(i);
                last = i;

                printf("%f\t%f\t%f\n", i, inF, inK);
            }
            break;
        case 'K':
            printf("K\t\tF\t\tC\n");
            for(i=lowTemp; i<=highTemp; i+=interval)
            {
                inF = kelvinToFarenheit(i);
                inC = kelvinToCelcius(i);
                last = i;

                printf("%f\t%f\t%f\n", i, inF, inC);
            }
            break;
    }
    // possibly need to print last one
    if(last != highTemp)
    {
        // printf("-- DEBUGGING --\n");
        switch(unit)
        {
            case 'F':
                inC = farenheitToCelcius(highTemp);
                inK = farenheitToKelvin(highTemp);

                printf("%f\t%f\t%f\n", highTemp, inC, inK);
                break;
            case 'C':
                inF = celciusToFarenheit(highTemp);
                inK = celciusToKelvin(highTemp);

                printf("%f\t%f\t%f\n", highTemp, inF, inK);
                break;
            case 'K':
                inF = kelvinToFarenheit(highTemp);
                inC = kelvinToCelcius(highTemp);

                printf("%f\t%f\t%f\n", highTemp, inF, inC);
                break;
        }
    }

}


double farenheitToCelcius(double temp)
{
    double result = (double) (temp - 32.0) * (5.0/9.0);
    return result;
}

double farenheitToKelvin(double temp)
{
    return (temp + 459.67) * (5.0/9.0);
}

double celciusToFarenheit(double temp)
{
    return (temp * (9.0/5.0)) + 32.0;
}

double celciusToKelvin(double temp)
{
    return temp + 273.15;
}

double kelvinToFarenheit(double temp)
{
    return ((temp - 273.0) * (9.0/5.0)) + 32.0;
}

double kelvinToCelcius(double temp)
{
    return temp - 273.0;
}
