
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::abs;
#include <iomanip>

double fn(double x){
    return (-6*(x*x)) + (5*x) + 3;
}

double integral(double x){
    return (-2*(x*x*x)) + ((5/2)*(x*x)) + (3*x);
}

double trapezoid(double lower, double upper, long n){
    double delta_x;
    delta_x = (upper - lower) / n;
    double integral_sum;

    for(double i=lower;i < upper; i++){
        double x1 = i;
        double x2 = (i + delta_x);
        double y1 = fn(x1);
        double y2 = fn(x2);

        integral_sum = (integral_sum + (((y1 + y2)/2)* delta_x));

    }
    return integral_sum; 
}

bool tolerCheck(double integral, double trapezoid, double tolerance){
    return (abs(integral-trapezoid) < tolerance);
}

int main(){

    //gather input
    double lower;
    double upper;
    double tolerance;
    int n;

    cin >> lower >> upper >> tolerance >> n;

    cout << "Lower Range: " << lower << endl;
    cout << "Upper Range: " << upper << endl;
    cout << "Tolerance: " << tolerance << endl;
    cout << "Initial trapezoid count: "<< n << endl;

    double exact;
    double estimate;

    exact = integral(upper) - integral(lower);
    estimate = trapezoid(lower, upper, n);

    cout << "exact " << exact << endl;
    cout << "estimate " << estimate << endl;
    cout << exact - estimate << endl;


    while ((true != tolerCheck(exact, estimate, tolerance)) && 0){
        cout << "Intermediate Result" << estimate << 
                ", Traps:"<< n << ", diff:" << (abs(exact-estimate));
        n *= 2;
        estimate = trapezoid(lower, upper, n);

    }
    cout << "broke";

} // to main

