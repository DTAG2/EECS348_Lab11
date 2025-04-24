#include <stdio.h>
#include "temperature.h"

int main(int argc, char *argv[]) {
    float temp_in, conv_temp, to_cel; //define variables to hold calculated and obtained values
    int scale, target_scale;

    printf("Enter temperature value: ");
    if (scanf("%f", &temp_in) != 1) { //if unable to obtain correct input
        printf("Invalid input, please enter a number.\n"); //print an error message
        while (getchar() != '\n'); // consume the remaining invalid input
        while(1){ //continue to loop until correct temperature value is given
            printf("\nEnter temperature value: ");
            if (scanf("%f", &temp_in) != 1) {
                printf("Invalid input, please enter a number.\n"); //print an error message if unable to obntain correct input
                while (getchar() != '\n'); // consume the remaining invalid input
            }else{ //break when given correct input
                break;
            }
        }
    }
    
    printf("\nScales\n1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\n\nSelect the input scale (1, 2, 3): "); //obtain input scale
    if (scanf("%d", &scale) != 1 || scale < 1 || scale > 3) { //if unable to obtain correct input or scale is not in correct range
        printf("Invalid scale\n"); //print an error message if unable to obntain correct input
        while (getchar() != '\n'); // consume the remaining invalid input
        while(1){ //continue to loop until correct scale value is given
            printf("\nSelect the input scale (1, 2, 3): ");
            if (scanf("%d", &scale) != 1 || scale < 1 || scale > 3) { 
                printf("Invalid scale\n"); //print an error message if unable to obntain correct input
                while (getchar() != '\n'); // consume the remaining invalid input
            }else{ //break when given correct input
                break;
            }
        }
    }
    
    printf("Select the target scale (1, 2, 3): "); //obtain target scale
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {//if unable to obtain correct input or target scale is not in correct range
        printf("Invalid scale\n"); //print an error message if unable to obntain correct input
        while (getchar() != '\n'); // consume the remaining invalid input
        while(1){ //continue to loop until correct target scale value is given
            printf("\nSelect the target scale (1, 2, 3): ");
            if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) { 
                printf("Invalid scale\n"); //print an error message if unable to obntain correct input
                while (getchar() != '\n'); // consume the remaining invalid input
            }else{ //break when given correct input
                break;
            }
        }
    }
    
    if (scale == 3 && temp_in < 0) { //if input scale is Kelvin (3) and the input temperature is negative
        printf("Error: Kelvin cannot be negative.\n"); //print error message that Kelvin can't be negative
        return 1;
    }
    
    if (scale == target_scale) { //if the scale and target are the same
        printf("No conversion needed. Temperature remains: %.2f\n", temp_in); //print that no conversion is needed
        return 0;
    }

    if (scale == 1){ //if input scale is celsius
        if (target_scale == 2){ //if target scale is fahrenheit
            conv_temp = celsius_to_fahrenheit(temp_in);
        }else{ //if target scale is kelvin
            conv_temp = celsius_to_kelvin(temp_in);
        }
    }

    if (scale == 2){ //if input scale is fahrenheit
        if (target_scale == 1){ //if target scale is celsius
            conv_temp = fahrenheit_to_celsius(temp_in);
        }else{ //if target scale is kelvin
            conv_temp = fahrenheit_to_kelvin(temp_in);
        }
    }

    if (scale == 3){ //if input scale is kelvin
        if (target_scale == 1){ //if target scale is celsius
            conv_temp = kelvin_to_celsius(temp_in);
        }else{ //if target scale is fahrenheit
            conv_temp = kelvin_to_fahrenheit(temp_in);
        }
    }

    printf("\nConverted Temperature: %.2f\n", conv_temp); //print the converted temperature
    to_cel = conv_temp; //initialze variable to convert all conv_temp to celsius
    if (target_scale == 2){ //if target scale is fahrenheit
        to_cel = fahrenheit_to_celsius(conv_temp); //convert conv_temp to celsius
    }
    if (target_scale == 3){ //if target scale is kelvin
        to_cel = kelvin_to_celsius(conv_temp); //convert conv_temp to celsius
    }
    //made sure all conv_temp were converted to celsius in to_cel
    
    categorize_temperature(to_cel); //call to print categorization of temperatures
    
    return 0;
}
