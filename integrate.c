#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

void integrate_power (double coeff, int expo) {

    if (expo == -1) {
        if (coeff == -1) {
            printf("I = ln|x| + C\n");
        } else {
            printf("I = %.2lf * ln|x| + C\n", coeff);
        }

        return;
    }

    if (coeff == 1) {
        printf("I = x^%d / %d + C\n", coeff, expo + 1, expo + 1);
    } else {

        printf("I = %.2lf * x^%d / %d + C\n", coeff, expo + 1, expo + 1);
    }
}

void integrate_sin (double coeff) {

    if (coeff  == 1) {
        printf("I = -cos(x) + C\n");
    } else {
        printf("I = %.2lf * (-cos(x)) + C\n");
    }
}

void integrate_cos (double coeff) {

    if (coeff == 1) {
        printf("I = sin(x) + C\n");
    } else {
        printf("I = %.2lf * sin(x) + C\n", coeff);
    }
}

void integrate_exp (double coeff) {

    if (coeff == 1) {
        printf("I = exp(x) + C\n");
    } else {
        printf("I = %.2lf * exp(x) + C\n", coeff);
    }
}

void integrate_constant (double coeff) {

    printf("I = %.2lf * x + C\n", coeff);
}


int main () {

    char function[MAX_LENGTH];
    double coeff, constant;
    int exponent;

    printf("Enter function: ");
    scanf("%49s", function);

    if (strcmp(function, "x^n") == 0) {
        printf("Coefficient: ");
        scanf("%lf", &coeff);
        printf("Exponent n: ");
        scanf("%d", &exponent);
        integrate_power(coeff, exponent);
    }
    
}