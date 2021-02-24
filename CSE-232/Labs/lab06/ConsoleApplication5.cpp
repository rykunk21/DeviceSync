#include <iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
#include<algorithm>
using std::sort;
#include<cmath>

long loc_to_dec(string loc) {
    // add comment
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int num1 = 0;
    for (int i = 0; i < loc.size(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (loc[i] == alphabet[j]) {
                num1 += pow(2, j);
            }
        }
    }
    return num1;
}

string abbreviation(string loc) {

    sort(loc.begin(), loc.end());

    for (int i = 0; i <= loc.size(); i++) {
        if (loc.at(i) == loc.at(i + 1)) {
            loc.at(i + 1) = loc.at(i + 1) + 1;
            loc.erase(i, 1);

            cout << loc;
            abbreviation(loc);
        } else {
            continue;
        }
        sort(loc.begin(), loc.end());
    }
    return loc;
}
/*
string dec_to_loc(long dec) {

    return;
}

long add_loc(string loc1, string loc2) {
    return;
}
*/

int main() {
    string test;
    cin >> test;

    loc_to_dec(test);
    abbreviation(test);

    return 0;
}