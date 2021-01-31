#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){
    int num1;
    int num2;
    cin >> num1 >> num2;
    int count = 1;
    bool ended = false;

    for(int i=1; i <= num1; i++){

        while(count <= i) {
            cout << count << ' ';
            count++;
            }
    
        do {
            cout << count << ' ';
            count--;
            }
            while(count >= 1);
            
        cout << endl;
        count = 1;

        if (i == num2)
            break;
    }

    for (int i=1; i<=num2; i++)
        cout << i << ' '<< endl;
}