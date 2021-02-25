#include <iostream>
#include <string>
#include <typeinfo>
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


int specFind(string search, string pattern, int start){
    string digit = "0123456789";
    int search_length = search.length();
    int pattern_length = pattern.length();

    for(int i=start; i <= search_length; i++){
        for(int j=0; j <= pattern_length;){
            if (pattern[j]==search[i+j]){
                j++;
                if (j == pattern_length - 1){
                    return i;
                } else {
                    continue;
                }
            }
            if ((pattern[j]=='%') && 
                (digit.find(search[i+j]) == string::npos)){
                j++;
                if (j == pattern_length - 1){
                    return i;
                } else {
                    continue;
                }
            }
            if ((pattern[j]=='#') &&
                (digit.find(search[i+j]) != string::npos)){
                    j++;
                    if (j == pattern_length - 1){
                    return i;
                } else {
                    continue;
                }
            }
            break;
        }
    }
    return -1;
}

bool ImprovedContains(string search, string pattern, bool *case_sens){
    // return true if the pattern is found in the text, false otherwise.
    if (case_sens){
        // convert strings into lowercase
        search = ToLower(search);
    } 

    if (specFind(search, pattern) >= 0){
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
        index = (specFind(search, pattern, index) + 1);
        if (index >= 0){
            count += 1;
        }
    }
    while (specFind(search, pattern, index) >= 0);
    
    return count;
}

int ImprovedFindFirstOf(string search, string pattern, bool *case_sens){
    // return the index in the text that the pattern is found
    if (case_sens){
        search = ToLower(search);
    }
    return specFind(search, pattern);
}

void ImprovedReplace(string &search, string pattern, string replace, 
                     bool *case_sens){
    // find pattern in search and replace "replace"
    int index;
    if (case_sens){ // make a copy of lowercase entries
        std::string lower_search = ToLower(search);
        std::string lower_pattern = ToLower(pattern);
        index = specFind(lower_search, lower_pattern);
    } else {  
        index = specFind(search, pattern);
    }

    if (index >= 0){
        // replace exactly what the user inputs
        search.replace(index, pattern.length(), replace);  
    }
}

int ImprovedNumberOfDifferences(string s1, string s2, bool *case_sens){
    //return the number of characters that differ between the two strings.
    if (case_sens){
        s1 = ToLower(s1);
        s2 = ToLower(s2);
    }
    int diffs = 0;
    for (string::size_type i=0; i < s1.length(); i++){
        if (s1[i] != s2[i]){
            diffs +=1;
        }
    }

    return diffs;
}

void test_toLower(){
    string s = "THiS iS a SAMplE sTrIng";
    cout << ToLower(s);
    
}

void test_ImprovedContains(){
    bool sens = false;
    cout << "expected: 1\n" << "Returned: ";
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
    cout << "expected: 1\n" << "Returned: ";
    string search = "suss";
    string pattern = "uss";
    cout << ImprovedFindFirstOf("suss", pattern, &sens) << std::endl;
}

void test_ImprovedReplace(){
    bool sens = false;
    cout << "expected: success\n"<< "Returned: ";
    string s = "suss";
    ImprovedReplace(s, "uss", "uccess", &sens);
    cout << s;
}

void test_ImprovedNumberOfDifferences(){
    bool case_sens = false;
    int result = ImprovedNumberOfDifferences("", "", &case_sens);
    cout << result;

}


