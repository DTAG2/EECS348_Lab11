#include <stdio.h>
#include "temperature.h"

float celsius_to_fahrenheit(float celsius){
    return ((9.0/5.0)*celsius+32); //conversion functions obtained from lab documents
}

float fahrenheit_to_celsius(float fahrenheit){
    return ((5.0/9.0)*(fahrenheit-32));
}

float celsius_to_kelvin(float celsius){
    return(celsius + 273.15);
}

float kelvin_to_celsius(float kelvin){
    return(kelvin - 273.15);
}

float fahrenheit_to_kelvin(float fahrenheit){
    return (celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit))); //convert from fahrenheit to celsius and then convert to kelvin
}

float kelvin_to_fahrenheit(float kelvin){
    return (celsius_to_fahrenheit(kelvin_to_celsius(kelvin))); //convert from kelvin to celsius and then convert to fahrenheit
}

void categorize_temperature(float celsius){ //when using this function parameter has to be in celsius
    if (celsius < 0) { //categories according to lab documents
        printf("Category: Freezing.\nAdvisory: Wear winter clothing.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold.\nAdvisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable.\nAdvisory: Normal attire is fine.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot.\nAdvisory: Stay hydrated.\n");
    } else {
        printf("Category: Extreme Heat.\nAdvisory: Avoid direct sunlight.\n");
    }
}
