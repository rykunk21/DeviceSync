#include <iostream>

template <typename foo_type> 
void foo(foo_type & var){
    std::cout << var;
}

int main(){
    // foo(3); // calling a function with non-ref
}
