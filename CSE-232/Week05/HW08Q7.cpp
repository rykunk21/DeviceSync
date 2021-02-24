#include <iostream>
#include <string>

using std::cin;using std::cout; using std::endl;
using std::string;

void convertline(string line, int line_num){
    cout << line_num << ':';
    for(string::size_type i{0}; i < line.length(); i++){
        if (i % 10 == 0 && i != 0){ // not sure if im a fan of this
            cout << '\n' << line_num << ':';
            cout << line[i];
        }
        else
            cout << line[i];
    }
    cout << '\n';
}

int main(){
    string usrin;
    int line_num{1};

    while (getline(cin, usrin)){
        convertline(usrin, line_num);
        line_num += 1;
    }


} // to main


