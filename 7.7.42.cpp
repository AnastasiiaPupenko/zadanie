#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double mc_odhad_integralu(double (*fun)(double), double a, double b, double l, unsigned int n_tests) {
    unsigned int count_inside = 0;
    double x, y, integral;

    for (unsigned int i = 0; i < n_tests; ++i) {
        double x = a + ((double)rand() / RAND_MAX) * (b - a); 
        double y = -l + ((double)rand() / RAND_MAX) * (2 * l); 
        double f_val = (*fun)(x); 

        if (y >= 0 && y <= f_val)
            integral += 1;
    }
     integral = ((double)count_inside / n_tests) * (b - a) * (2 * l);

    return integral;

}


double my_sin(double x) {
    return sin(x);
}

double my_log7(double x) {
    return log(x) / log(7);
}

int main() {
    double result1, result2;

    result1 = mc_odhad_integralu(&my_sin, 0, 2 * M_PI, 1.0, 1000000);
    printf("Estimated integral for sin on the interval [0, 2?]: %lf\n", result1);

    result2 = mc_odhad_integralu(&my_log7, 1, 7, 1.0, 1000000);
    printf("Estimated integral for log7 on the interval [1, 7]: %lf\n", result2);

    return 0;
}
