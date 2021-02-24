#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;
#include <typeinfo>


string what_is_it(int var){
    if (var == 0) {
        return  "an int that is a zero (0)";
    }
    else {
        return "an int";
    }
  
} // what is it

string what_is_it(string var){
    if (var == "0") {
        return  "a string that is a zero (\"0\")";
    }
    else {
        return "a string";
    }
  
} // what is it

string what_is_it(char var){
    if (var == '0') {
        return  "a char that is a zero ('0')";
    }
    else {
        return "a char";
    }
  
} // what is it

int main(){
    cout << what_is_it('0') << endl;
}// to main