#include <iostream>
#include <string>

template <typename arb>

arb tripled(arb var){
    return var + var + var;
}

int main() {
    std::string s{"Josh"};
    std::cout << tripled(8) << std::endl;
    std::cout << tripled(s) << std::endl;
    std::cout << tripled(5.5) << std::endl;
    std::cout << tripled<int>(5.6) << std::endl;
    std::cout << tripled('!') << std::endl;
}