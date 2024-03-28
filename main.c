#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

    printf("\nWelcome to the Logarithmic Axis Scaling Application!\n");

    float smallestObservation;
    float largestObservation;
    int lowestDecade;
    int highestDecade;
    int numberOfDecades;

    float lowestTemperature;
    float highestTemperature;
    float stepLength;
    float axisLength;
    float materialConstant;
    float R0;
    float Rlowest;
    float Rhighest;
    float Rt;
    float lengthCM;


    printf("\nPlease provide the lowest temperature value in Celsius degrees: ");
    fflush(stdin);
    scanf("%f", &lowestTemperature);
    // convert into Kelvin degrees
    lowestTemperature = lowestTemperature + 273.15;

    printf("\nPlease provide the highest temperature value in Celsius degrees: ");
    fflush(stdin);
    scanf("%f", &highestTemperature);
    // convert into Kelvin degrees
    highestTemperature = highestTemperature + 273.15;

    printf("\nPlease provide the step length in Celsius degrees: ");
    fflush(stdin);
    scanf("%f", &stepLength);

    printf("\nPlease provide the axis length in Centimeters: ");
    fflush(stdin);
    scanf("%f", &axisLength);

    materialConstant = 3440.0;
    R0 = 5000;
    Rlowest = R0 * exp(materialConstant * (1.0/lowestTemperature - 1.0/293.15));
    Rhighest = R0 * exp(materialConstant * (1.0/highestTemperature - 1.0/293.15));
    if(Rhighest > Rlowest){
        largestObservation = Rhighest;
        smallestObservation = Rlowest;
    } else {
        largestObservation = Rlowest;
        smallestObservation = Rhighest;
    }

    lowestDecade = log10(smallestObservation);
    highestDecade = log10(largestObservation) + 1;
    numberOfDecades = highestDecade - lowestDecade;

    printf("\n +---------------------------------------------+");
    printf("\n |      Thermistor / logarithmic scaling       |");
    printf("\n |  temperature  |    RT[Ohm]   |     l[cm]    |");
    printf("\n +---------------------------------------------+");
    for(int t = lowestTemperature; t <= highestTemperature; t += stepLength){
        Rt = R0 * exp(materialConstant * (1.0/t - 1.0/293.15));
        lengthCM = axisLength / numberOfDecades * (log10(Rt) - 1.0);
        printf("\n |  %8.2f     |  %8.2f    |  %8.2f    |", t - 273.15, Rt, lengthCM);
    }
    printf("\n +---------------------------------------------+");
    printf("\n Total height of the graph[cm]: %8.2f", axisLength);
    printf("\n Distance between the decades[cm]: %8.2f", axisLength / numberOfDecades);
    printf("\n The lowest decade is: %d", (int)pow(10.0, lowestDecade));
    printf("\n The highest decade is: %d", (int)pow(10.0, highestDecade));
    printf("\n The total number of decades is: %d", numberOfDecades);
    printf("\n +---------------------------------------------+");


    return 0;
}


