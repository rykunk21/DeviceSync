
#include <iostream>
#include <string>
using std::string;
using std::cout;

std::string find_repeated(const std::string &inp){
    std::string fail = " ";
    if (8 > inp.length())
        return fail;
    for (std::string::size_type i{0};i < inp.length();i++){
        std::string temp;
        temp.assign(inp, i, 4);
        if ((temp.length() == 4) && inp.find(temp, i+1)!= std::string::npos)
            return temp;
        else
            continue;
    }
    return fail;
}

int main(){
    string repeat = "1111111";
    string out = find_repeated(repeat);
    cout << "repeated substr: " << out << std::endl;

    return 0;
}