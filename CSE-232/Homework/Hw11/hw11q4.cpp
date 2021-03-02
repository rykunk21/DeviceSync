#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <typeinfo>
#include <iomanip>
#include <stdexcept>
#include <ctype.h> 
#include <stdio.h> 
using std::cout;
using cstring = const std::string; 
using std::string;

template <typename any>

any all_convert(cstring &s, int *p){
    // accept a string and convert it to the template type
    *p = 0;
    int count = 0;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int index = 0;
    // "   -67.34x"
    for (int i = 0; i < int(s.length()); i++){
        if (isspace(s.at(0))){
            if (isspace(s.at(i))){
                count += 1;
                continue;
            } else {
                index = i;
                break;
            }
        } 
    }
    *p += count;

    int next = (int(s.length())  - index + 1);
    
    string alphastring="";
    string digitstring="";

    for (int i=index; i < int(s.length()); i++){
        if (alpha.find(s.at(i)) != string::npos){
            alphastring += s.at(i);
        } else if (isspace(s.at(i))){
            alphastring += ' ';
        } else {
            digitstring += s.at(i);
        }
    }

    string toConvert = digitstring + ' ' + alphastring;

    std::cout << toConvert;
        
    std::istringstream iss(toConvert);
    any out;
    any def;
    iss >> out;
    if (out == def){

        out = def;
        iss >> out;
    }

    std::ostringstream oss;
    oss << out;
    string test = oss.str();

    *p += test.length();
    
    return out;

} // fn

template <typename T>
void ASSERT_EQ(T arg, T arg2){
    cout << std::boolalpha << '\n';
    if (arg == arg2) {
        cout << (arg == arg2) << std::endl;
    } else {
        cout << "Unequal" << std::endl;
        cout << "arg1: " << arg << std::endl;
        cout << "arg2: " << arg2 << std::endl;
    }
}

void test_same(){
    std::string s = "12";
    int pos = 99;
    int result = 999;
    result = all_convert<int>(s, &pos);
    ASSERT_EQ(result, 12);
    ASSERT_EQ(pos, 2);
    s = "-67.34";
    pos = 99;
    double result_2 = 999;
    result_2 = all_convert<double>(s, &pos);
    ASSERT_EQ(result_2, -67.34);
    ASSERT_EQ(pos, 6);
    s = "cats";
    pos = 99;
    std::string result_3 = "";
    result_3 = all_convert<std::string>(s, &pos);
    string cats = "cats";
    ASSERT_EQ(result_3, cats);
    ASSERT_EQ(pos, 4);
}
void test_different(){
    std::string s = "12cat";
    int pos = 99;
    auto result = all_convert<int>(s, &pos);
    ASSERT_EQ(result, 12);
    ASSERT_EQ(pos, 2);
    s = "   -67.34x";
    pos = 99;
    auto result_2 = all_convert<double>(s, &pos);
    ASSERT_EQ(result_2, -67.34);
    ASSERT_EQ(pos, 9);
    s = "\t  cats and dogs";
    pos = 99;
    auto result_3 = all_convert<std::string>(s, &pos);
    string cats = "cats";
    ASSERT_EQ(result_3, cats);
    ASSERT_EQ(pos, 7);
    s = "\t  cats and dogs";
    pos = 99;
    auto result_4 = all_convert<char>(s, &pos);
    char c = 'c';
    ASSERT_EQ(result_4, c);
    ASSERT_EQ(pos, 4);

}

int main(){
    test_same();
    test_different();
}

