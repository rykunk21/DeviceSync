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

// q2 correct
#include <iostream>

int main() {
  int number_of_lines{0};
  int max_value{0};
  std::cin >> number_of_lines >> max_value;
  for(int line{0}; line < number_of_lines; ++line) {
    
    int i{1};
    for ( ; i < line + 1; ++i){
      std::cout << i << ' ';
    }
    if (i > max_value) {
      break;
    }
    for (; i > 0; --i) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
}