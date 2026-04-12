#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5005
#define PI 3.141592653589793

typedef struct {
    double re, im;
} Complex;

typedef struct {
    double omega;
    double amplitude;
} Result;

double f ( double t) {
    return sin(2*PI*3*t) + 0.7 * sin(2 * PI * 7 * t);
}

Complex Fourier (double omega, double T) {

    double dt = T / N;
    Complex sum;
    sum.im = 0;
    sum.re = 0;

    for (int i = 0; i < N; i++ ) {
        double t = i * dt;
        double real = f(t) * cos(omega * t);
        double imag = -f(t) * sin(omega * t);
        sum.re += real * dt;
        sum.im += imag * dt;
    }
    return sum;
}

double modulus (Complex z) {
    return sqrt(z.re * z.re + z.im * z.im);
}

int cmp (const void *a, const void *b) {

    Result *r1 = (Result *)a;
    Result *r2 = (Result *)b;

    if (r1->amplitude < r2->amplitude)
        return 1;
    if (r1->amplitude > r2->amplitude)
        return -1;

    return 0;
}

int main () {

    double T = 1.0;
    Result results[50];

    for (int k = 1; k <= 50; k++ ) {
        double omega = 2 * PI * k;
        Complex val = Fourier(omega, T);
        results[k-1].omega = k;
        results[k-1].amplitude = modulus(val);
    }

    qsort(results, 50, sizeof(Result), cmp);
    printf("Fourier top components:\n");
    for (int i = 0; i < 10; i++ ) {
        printf("k = %f, amplitude = %.6f\n", 
        results[i].omega, results[i].amplitude);
    }
    return 0;
}