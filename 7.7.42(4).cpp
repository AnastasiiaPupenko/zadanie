#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Deklarácia funkcií

double mc_odhad_integralu(double (*fun)(double), double a, double b, double l, unsigned int n_tests);
double my_sin(double x);
double my_log7(double x);

//Definícia funkcie

double mc_odhad_integralu(double (*fun)(double), double a, double b, double l, unsigned int n_tests) {
    unsigned int count_inside = 0;
    double x, y, integral;

    for (unsigned int i = 0; i < n_tests; ++i) {
        x = a + ((double)rand() / RAND_MAX) * (b - a); 
        y = -l + ((double)rand() / RAND_MAX) * (2 * l); 
        double f_val = (*fun)(x); 

        if (y >= 0 && y <= f_val)
            count_inside += 1;
    }

    integral = ((double)count_inside / n_tests) * (b - a) * (2 * l);

    return integral;
}

//Definícia funkcie 'my_sin' a 'my_log7'

double my_sin(double x) {
    return sin(x);
}
double my_log7(double x) {
    return log(x) / log(7);
}

//Hlavná funkcia programu

int main() {
    double result1, result2;

    result1 = mc_odhad_integralu(&my_sin, 0, 2 * M_PI, 1.0, 1000000);
    printf("Odhadnutý integrál pre sin na intervale [0, 2π]: %lf\n", result1);

    result2 = mc_odhad_integralu(&my_log7, 1.1, 7, 1.0, 1000000);
    printf("Odhadnutý integrál pre log7 na intervale [1.1, 7]: %lf\n", result2);

    return 0;
}
