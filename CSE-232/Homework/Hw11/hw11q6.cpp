#include <vector>
#include <iostream>
#include <string>
#include <cassert>
using std::string; using std::vector; using std::cout;
using c_str_vec = const vector<string>;

vector<string> zip(c_str_vec &v1, c_str_vec &v2){
    
    int range = static_cast<int>(v1.size()) ? v1.size() >= v2.size() : 
                static_cast<int>(v2.size());


    vector<string> out(range);
    cout << out.size() << '\n' << v1.size();
    assert(out.size()==v1.size());

    
    for(int i=0; i<=range; i++){
        out[i] = v1[i] + v2[i];
    }

    return out;
}


int main(){
    const std::vector<std::string> a_1 = {"Spartan", "Wolverine", "Husky"};
    const std::vector<std::string> b_1 = {"MSU", "UM", "UW"};
    const std::vector<std::string> c_1 = {"SpartanMSU", "WolverineUM", "HuskyUW"};


    assert(zip(a_1, b_1) == c_1);
    

    return 0;
} // main