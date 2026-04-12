#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 10005

typedef struct { double re, im; } Complex;

typedef struct {double sigma, omega, amplitude;} Result;

double f (double t) {
    return  exp(-t) * sin (5 * t);
}

Complex Laplace (double sigmna, double omega, double T) {

    Complex sum;
    sum.im = 0;
    sum.re = 0;
    double dt = T / N;

    for (int i = 0; i < N; i++ ) {
        double t = i * dt;

        double exp_part = exp(-sigmna * t);
        double real = f(t) * exp_part * cos(omega * t);
        double imag = -f(t) * exp_part * sin(omega * t);
        sum.re += real * dt;
        sum.im += imag * dt;
    }

    return sum;
}

double modulus(Complex z) {

    return sqrt(z.re * z.re + z.im * z.im);
}

int cmp (const void* a, const void* b) {

    Result *r1 = (Result *)a;
    Result *r2 = (Result *)b;

    if (r1->amplitude < r2->amplitude)
        return 1;
    if (r1->amplitude > r2->amplitude)
        return -1;

    return 0;
}

int main () {

    int idx = 0;
    double T = 10.0;
    Result results[50];

    for (int i = 0; i < 5; i++ ) {
        double sigma = 0.5 + i * 0.5;
        for (int j = 1; j <= 10; j++ ) {
            double omega = j;
            Complex val = Laplace(sigma, omega, T);
            results[idx].sigma = sigma;
            results[idx].omega = omega;
            results[idx].amplitude = modulus(val);
            idx++;
        }
    }

    qsort(results, idx, sizeof(Result), cmp);

    printf("Laplace top components: \n");
    for (int i = 0; i < 10; i++ ) {
        printf("sigma = %.2f, omega = %.2f, amplitude = %.6f\n",
        results[i].sigma, results[i].omega, results[i].amplitude);
    }

    return 0;
}