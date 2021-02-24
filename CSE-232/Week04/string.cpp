#include <iostream>
#include <string>
using std::string;

string find_repeated(const string inp){
  for (int i{0}; i < inp.length(); i++)
    std::cout << inp[i] << std::endl;
}

int main(){
    string usrstr;

    std::cin >> usrstr;
    find_repeated(usrstr);
}