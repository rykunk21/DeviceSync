#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <typeinfo>
using cstring = const std::string; 
using std::string;

template <typename T>
T all_convert(cstring &s, int *p){
    // accept a string and convert it to the template type
    *p=0;
    
    std::istringstream iss(s);
    T out;
    iss >> out;
    return out;

} // fn

int main(){
    std::string s1= "cats";
    int p = 0;
    string result = all_convert<string>(s1, &p);
    std::cout << result << '\n' << p << '\n';

} // main

