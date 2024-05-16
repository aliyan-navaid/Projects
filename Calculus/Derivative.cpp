#include <iostream>

/* Calculates derivative using Difference Quotient */
double differenceQuotient(double x, double (*f)(double), double h = 1e-7) {
    return (f(x+h)-f(x))/h;
}

/* Calculates derivative using Average of derivative just before and after point */
double centralDifference(double x, double (*f)(double), double h = 1e-7) {
    return ( f(x+h)-f(x-h) ) / (2*h);
}

/* Sample x^2 function */
double squared(double x) {
    return x*x;
}

int main() {
    std::cout << "Slope of Tangent to f(x)=x^2 at x=5 is " << differenceQuotient(5, squared) << std::endl;
    std::cout << "Slope of Tangent to f(x)=x^2 at x=5 is " << centralDifference(5, squared) << std::endl;
}