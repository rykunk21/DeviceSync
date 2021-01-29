#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    double startKm = 37.33 * 149598000;
    double startMi = 37.33 * 92955800;
    
    int days;
    cin >> days;
    int seconds = days * 86400;
    
    double distanceKm = (14.33 * seconds) + startKm;
    double distanceMi = (8.90 * seconds) + startMi;
    
    double light = 299792.458;
    double radioSec = 2 * (distanceKm / light);
    double radioHrs = (radioSec / 3600);
    
    cout << distanceKm << endl << distanceMi << endl << radioHrs << endl;  
    return 0;
}
