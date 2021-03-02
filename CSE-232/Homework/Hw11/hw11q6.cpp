#include <vector>
#include <iostream>
#include <string>
#include <cassert>
using std::string; using std::cout; using std::vector;
using c_str_vec = const vector<string>;

vector<string> zip(c_str_vec &v1, c_str_vec &v2){
    vector<string> out={};
    
    int v1size = int(v1.size());
    int v2size = int(v2.size());
    int length;
    bool v1large = false;
    bool v2large = false;

    std::cout << v1size << '\n' << v2size << '\n';

    if (v1size > v2size){
        length = v2size;
        v1large = true;
    } else if (v2size > v1size){
        length = v1size;
        v2large = true;
    } else {
        length = v1size;
    }

    std::cout << length << '\n';

    for(int i=0; i < length; i++){
        out.push_back(v1.at(i) + v2.at(i));
    }

    if (v2large){
        int difference = v2size - v1size;
        for (int i = 0; i < difference; i++){
            out.push_back(v2.at((v1size + i)));
        }
    } else if (v1large){
        int difference = v1size - v2size;
        for (int i = 0; i < difference; i++){
            out.push_back(v1.at((v2size + i)));
        }
    }

    return out;
}


int main(){
    const std::vector<std::string> a_1 = {"Spartan", "Wolverine", "Husky"};
    const std::vector<std::string> b_1 = {"MSU", "UM"};
    const std::vector<std::string> c_1 = {"SpartanMSU", "WolverineUM", "Husky"};
    vector<string> a = zip(a_1, b_1);
    for (auto ch: a){
        std::cout << ch << '\n';
    }

    assert(zip(a_1, b_1) == c_1);
    

    return 0;
} // main