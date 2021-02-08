#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iomanip>
using std::setprecision; using std::fixed;

int main(){
    double low;
    double high;
    int interval;

    cout << setprecision(3) << fixed;
    cin >> low;
    cin >> high;
    cin >> interval;

    double quotient = (high - low) / interval;

    for(int i{1}; i <= interval; i++){
        double xval = low + (quotient * (i-1));
        double yval = low + (quotient * i);

        cout << '(' << xval << ", "<< yval << ')' << endl;
        
    }
}