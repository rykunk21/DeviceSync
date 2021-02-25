#include <iostream>
#include <string>
#include <typeinfo>
using std::string; using std::cout;


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


int specFind(string search, string pattern, int start=0){
    string digit = "0123456789";
    int search_length = search.length();
    int pattern_length = pattern.length();
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

bool ImprovedContains(string search, string pattern, bool case_sens){
    // return true if the pattern is found in the text, false otherwise.
    if (!case_sens){
        // convert strings into lowercase
        search = ToLower(search);
        pattern = ToLower(pattern);
    } 

    if (specFind(search, pattern) >= 0){
        return true;
    } else {
        return false;
    }

} // ImprovedContains

int ImprovedMatches(string search, string pattern, bool case_sens){
    // return the number of times the pattern is found in the text.
    if (!case_sens){
        // convert strings into lowercase
        search = ToLower(search);
        pattern = ToLower(pattern);
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

int ImprovedFindFirstOf(string search, string pattern, bool case_sens){
    // return the index in the text that the pattern is found
    if (!case_sens){
        search = ToLower(search);
        pattern = ToLower(pattern);
    }
    return specFind(search, pattern);
}

void ImprovedReplace(string &search, string pattern, string replace, 
                     bool *case_sens){
    // find pattern in search and replace "replace"
    int index;
    if (!case_sens){ // make a copy of lowercase entries
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
    if (!case_sens){
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

void ASSERT_TRUE(bool result){
    if (result){
        cout << "\nCorrect\n";
    } else {
        cout << "\nIncorrect\n";
    }
}

void ASSERT_FALSE(bool result){
    if (!result){
        cout << "\nCorrect\n";
    } else {
        cout << "\nIncorrect\n";
    }
}


void containseasy(){
    const std::string text{"abc"};
    const std::string pattern{"b"};
    const bool is_case_insensitive = false; 
    bool result;
    result = ImprovedContains(text, pattern, &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "d", &is_case_insensitive);
    ASSERT_FALSE(result);
}

void exactcontains(){
    const std::string text_1{"My dog is named Mal."};
    const std::string pattern_1{"named"};
    const bool is_case_insensitive = false; 
    bool result;
    result = ImprovedContains(text_1, pattern_1, &is_case_insensitive);
    ASSERT_TRUE(result);
    const std::string pattern_2{"ame"};
    result = ImprovedContains(text_1, pattern_2, &is_case_insensitive);
    ASSERT_TRUE(result);
    const std::string pattern_3{"not"};
    result = ImprovedContains(text_1, pattern_3, &is_case_insensitive);
    ASSERT_FALSE(result);
    result = ImprovedContains(pattern_1, text_1, &is_case_insensitive);
    ASSERT_FALSE(result);
    const std::string pattern_4{"My dog is named Mal."};
    result = ImprovedContains(text_1, pattern_4, &is_case_insensitive);
    ASSERT_TRUE(result);
    const std::string pattern_5{"mal"};
    result = ImprovedContains(text_1, pattern_5, &is_case_insensitive);
    ASSERT_FALSE(result);
    const std::string pattern_6{"My dog is named Mal.!"};
    result = ImprovedContains(text_1, pattern_6, &is_case_insensitive);
    ASSERT_FALSE(result);
}

void containsspecial(){
    const std::string text{"CSE232 is all about C++"};
    bool is_case_insensitive = false; 
    bool result;
    result = ImprovedContains(text, " is ", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, " %% all", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "ab%t", &is_case_insensitive);
    ASSERT_FALSE(result);
    result = ImprovedContains(text, "CSE%%%%%%", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "all%about", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "2#2", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "2###", &is_case_insensitive);
    ASSERT_FALSE(result);
    result = ImprovedContains(text, "E2", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "# ", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, " ###", &is_case_insensitive);
    ASSERT_FALSE(result);
    is_case_insensitive = true;
    result = ImprovedContains(text, "E23#%%s a", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "e23#%%S a", &is_case_insensitive);
    ASSERT_TRUE(result);
    result = ImprovedContains(text, "e23#%%# a", &is_case_insensitive);
    ASSERT_FALSE(result);

}

int main(){
    containsspecial();
    return 0;
}