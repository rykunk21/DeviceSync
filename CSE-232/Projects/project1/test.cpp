#include <iostream>
#include <string>
#include <typeinfo>
using std::string; using std::cout;
using cstring = const string;


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


int specFind(cstring search, cstring pattern, const int start=0){
    string digit = "0123456789";
    int search_length = search.length(); // codecademy pro
    int pattern_length = pattern.length(); // codecademy pro
    for(int i=start; i <= search_length; i++){
        for(int j=0; j <= pattern_length;){
            if (pattern[j]==search[i+j]){
                j++;
                if (j == pattern_length){
                    return i;
                }
            } else if (pattern[j]=='%'){
                j++;
                if (j == pattern_length){
                    return i;
                }
            } else if ((pattern[j]=='#') &&
                (digit.find(search[i+j]) != string::npos)){
                j++;
                if (j == pattern_length){
                    return i;
                }
            } else {
                break;
            }
            continue;
        }
    }
    return -1;
}

bool isSubStr(cstring search, cstring pattern){
    if (specFind(search, pattern) >= 0){
        return true;
    } else {
        return false;
    }
}

bool ImprovedContains(cstring search, cstring pattern, const bool *case_sens){
    // return true if the pattern is found in the text, false otherwise.

    // I could not for the life of me determine how to avoid this
    bool sens = *case_sens;

    if (sens){
        // convert strings into lowercase
        string lower_search = ToLower(search); // unable to 
        string lower_pattern = ToLower(pattern);
        return isSubStr(lower_search, lower_pattern);
    } else {
        return isSubStr(search, pattern);
    }

} // ImprovedContains

int ImprovedMatches(string search, string pattern, bool *case_sens){
    // "Was 2020 < 2021 do you think? Perhaps NOT?" //2022
    // return the number of times the pattern is found in the text.
    bool sens = *case_sens;

    if (sens){
        // convert strings into lowercase
        search = ToLower(search);
        pattern = ToLower(pattern);
    }
    int count = 0;
    int index = 0;

    // todo count all occurances
    do {
        index = (specFind(search, pattern, index) + 1);
        cout << index;
        if (index > 0){
            count += 1;
        }
    }
    while (specFind(search, pattern, index) >= 0);
    
    return count;
}

int ImprovedFindFirstOf(string search, string pattern, bool *case_sens){
    // return the index in the text that the pattern is found
    bool sens = *case_sens;

    if (sens){
        search = ToLower(search);
        pattern = ToLower(pattern);
    }
    return specFind(search, pattern);
}

void ImprovedReplace(string &search, string pattern, string replace, 
                     bool *case_sens){
    // find pattern in search and replace "replace"
    bool sens = *case_sens;
    int index;
    
    if (sens){ // make a copy of lowercase entries
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

int ImprovedNumberOfDifferences(string s1, string s2, bool case_sens){
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

template <typename test_type>
void ASSERT_EQ(test_type result, test_type compare, int test){
    std::cout << test << std::endl;
    if (result == compare){
        cout << "\nCorrect\n";
    } else {
        cout << "\nIncorrect\n";
    }
}



int main(){

    const std::string text{"Was 2020 < 2021 do you think? Perhaps NOT?"};
    bool is_case_insensitive = false; 
    int result;
    result = ImprovedMatches(text, "2022", &is_case_insensitive);
    cout << result << '\n';
    ASSERT_EQ(result, 0, 2);

    result = ImprovedMatches(text, "do ", &is_case_insensitive);
    ASSERT_EQ(result, 1, 1);
    result = ImprovedMatches(text, "####", &is_case_insensitive);
    ASSERT_EQ(result, 2, 3);
    result = ImprovedMatches(text, "o", &is_case_insensitive);
    ASSERT_EQ(result, 2, 4);
    result = ImprovedMatches(text, "% ", &is_case_insensitive);
    ASSERT_EQ(result, 8, 5);
    result = ImprovedMatches(text, "##", &is_case_insensitive);
    ASSERT_EQ(result, 6, 6);
    result = ImprovedMatches(text, "W", &is_case_insensitive);
    ASSERT_EQ(result, 1, 7);
    result = ImprovedMatches(text, "?", &is_case_insensitive);
    ASSERT_EQ(result, 2, 8);
    is_case_insensitive = true; 
    result = ImprovedMatches(text, "o", &is_case_insensitive);
    ASSERT_EQ(result, 3, 9);
    return 0;

}
