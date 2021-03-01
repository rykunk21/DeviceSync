#include <iostream>
#include <sstream>
using std::istringstream; using std::ostringstream; using std::string;



void only_uppercase(istringstream &iss, ostringstream &oss){
    string word;
    bool upper=false;
    while (iss >> word){
        upper=false;
        for (char ch: word){
            if(!isupper(ch)){
                upper=false;
                break;
            } else {
                upper=true;
            }
        }
        if (upper){
            oss << word << '\n';
        }
    }
}

int main(){
    std::istringstream iss("WORD AND      ANOTHER   but NOT! This");
    std::ostringstream oss;
    only_uppercase(iss, oss);
    std::cout << oss.str();
}
