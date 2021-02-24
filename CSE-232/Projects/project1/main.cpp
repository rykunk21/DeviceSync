#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;
#include <vector>
#include "head.h"

int main(){
    cout << "Testing Improved Contains\n";
    test_ImprovedContains();
    cout << '\n';
    test_ImprovedMatches();
    cout << '\n';
    test_ImprovedFindFirstOf();
    cout << '\n';
    test_ImprovedReplace();
    cout << '\n';


    return 0;
}