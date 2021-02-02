#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){
    bool q3=false;
    if (q3){
    int num1;
    int num2;
    cin >> num1 >> num2;
    
    for(int i=num1; i<=num2; i++)
        cout << 1 << i << ', ';
    }

    else {
        
    }
}

// question 1 corr

    #include <iostream>
    #include <string>

    int main() {
        int start{0};
        int end{0};
        std::cin >> start >> end;
        for (int i{start}; i <= end; ++i) {
        std::cout << '1' << i << ", ";
        }
        std::cout << std::endl;
    }