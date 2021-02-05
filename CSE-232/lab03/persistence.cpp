#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int usr_in{-1};
    int add_pers{0};
    int add_root{0};
    while (cin >> usr_in && usr_in > 0){
        while (usr_in % 10 > 0){
            add_pers += 1;
            int val = 0;
            if (usr_in < 10){ // check length   
                cout << add_root << ' ' << usr_in;
                break;
                }
            else
                for(usr_in; usr_in < 10;) {
                    add_root += val % 10;
            }
        }// cout >>  
    }
} // for main