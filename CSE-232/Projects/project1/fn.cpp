#include <iostream>
#include <string>
using std::string; using std::cout;
#include "head.h"

string ToLower(string s){
    // use ascii table to change chars mathematically
    string out = "";
    for (char chr: s){
        if ((65 <= chr) && (chr <= 90)){
            chr += 32;
            chr = static_cast<char>(chr);
        }
        out += chr;
    }
    return out;
}

bool ImprovedContains(string search, string pattern, bool *case_sens){
    // return true if the pattern is found in the text, false otherwise.
    if (case_sens){
        // convert strings into lowercase
        search = ToLower(search);
    } 

    if (search.find(pattern) != string::npos){
        return true;
    } else {
        return false;
    }

} // ImprovedContains

int ImprovedMatches(string search, string pattern, bool *case_sens){
    // return the number of times the pattern is found in the text.
    if (case_sens){
        // convert strings into lowercase
        search = ToLower(search);
    }
    int count = 0;
    int index = 0;

    // todo count all occurances
    do{
        index = (search.find(pattern, index) + 1);
        if (index){
            count += 1;
        }
    }
    while (search.find(pattern, index) != string::npos);
    
    return count;
}

int ImprovedFindFirstOf(string search, string pattern, bool *case_sens){
    // return the index in the text that the pattern is found
    // return -1 if pattern is not found.
    if (case_sens){
        search = ToLower(search);
    }
    int index = search.find(pattern);

    if (index != string::npos){
        return index;
    } else {
        return -1;
    }
 
    return 0;
}

void ImprovedReplace(string &search, string pattern, string replace, bool *case_sens){
    // find pattern in search and replace "replace"

    int index = search.find(pattern);
    if (index != string::npos){
        search.replace(index, pattern.length(), replace);
    }
}

int ImprovedNumberOfDifferences(string s1, string s2, bool *case_sens){
    //return the number of characters that differ between the two strings.

    return 0;
}

void test_toLower(){
    string s = "THiS iS a SAMplE sTrIng";
    cout << ToLower(s);
    
}

void test_ImprovedContains(){
    bool sens = false;
    cout << "expected: true\n" << "Returned: ";
    cout << ImprovedContains("string" , "st", &sens) << std::endl;
}

void test_ImprovedMatches(){
    // string search, string pattern, bool *case_sens
    bool sens = false;
    cout << "expected: 3\n"<< "Returned: ";
    cout << ImprovedMatches("stringstringstring", "st", &sens) << std::endl;
}

void test_ImprovedFindFirstOf(){
    bool sens = false;
    cout << "expected: 3\n" << "Returned: ";
    cout << ImprovedFindFirstOf("lllstring", "st", &sens);
}

void test_ImprovedReplace(){
    bool sens = false;
    cout << "expected: success\n"<< "Returned: ";
    string s = "suss";
    ImprovedReplace(s, "uss", "uccess", &sens);
    cout << s;
}