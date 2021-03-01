#include <vector>
#include <iostream>
using std::vector;


int sum(vector<vector<int>> data){
    int sum = 0;
    for (vector<int> col: data){
        for(int row: col){
            sum += row;
        }
    }
    return sum;
} // fn

int main(){
    std::vector<std::vector<int>> vec_2d = {{1, 3, 4}};

    std::cout << sum(vec_2d);
    return 0;
}