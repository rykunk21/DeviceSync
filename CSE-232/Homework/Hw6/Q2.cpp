#include <iostream>
using std::cin; using std::cout; using std::endl;

void switch_value(char *x, char *y){
    char store = *y;
    *y = *x;
    *x = store;
    
}
