#include <iostream>
#include <string>
#include <typeinfo>
using std::string; using std::cout;
using cstring = const string; // Using many constant strings and I hate typing


string ToLower(string s){
    // use ascii table to change chars mathematically
    string out = "";
    for (char chr: s){
    // 65 = 'A'; 90 = 'Z'
    // 97 = 'a'; 122 = 'z'
    // therefore adding 32 to the char will return the lowercase equvilant

        if ((65 <= chr) && (chr <= 90)){
            chr += 32;
            chr = static_cast<char>(chr); // cast back to char
        }
        out += chr; // build the new string
    }
    return out;
}

int specFind(cstring search, cstring pattern, int start=0){
    // modified .find to allow for special circumstances

    string digit = "0123456789";
    int search_length = search.length(); // codecademy pro 
    int pattern_length = pattern.length(); // codecademy pro
    for(int i=start; i <= search_length; i++){ // iterate over search
        for(int j=0; j <= pattern_length;){ // dont increment j
            if (pattern[j]==search[i+j]){
                j++; // only increment to the next 
                if (j == pattern_length){
                    return i; // return first index that prompted the match
                }
            } else if (pattern[j]=='%'){ // special case '%' matches any
                j++;
                if (j == pattern_length){
                    return i;
                }
            } else if ((pattern[j]=='#') && // special case '#' matches digits
                (digit.find(search[i+j]) != string::npos)){
                j++;
                if (j == pattern_length){
                    return i;
                }
            } else { 
                break; // breaks the inner loop
            }
            continue;
        }
    }
    return -1; // exhausted the check and there are no matches
}

bool isSubStr(cstring search, cstring pattern){
    // Implemented to dry up ImprovedContains
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
        string lower_search = ToLower(search);
        string lower_pattern = ToLower(pattern);
        return isSubStr(lower_search, lower_pattern);
    } else {
        return isSubStr(search, pattern);
    }

}

int ImprovedMatches(string search, string pattern, bool *case_sens){
    // return the number of times the pattern is found in the text.
    bool sens = *case_sens;

    if (sens){
        // convert strings into lowercase
        search = ToLower(search);
        pattern = ToLower(pattern);
    }
    int count = 0;
    int nextIndex = 0;

    // todo count all occurances
    do {
        nextIndex = (specFind(search, pattern, nextIndex) + 1); // *** +1 ***
        // specFind returns -1 for no find so 0 is excluded -----------^^^
        if (nextIndex > 0){
            count += 1; // add to count
        }
    }   // until no more matches
    while (specFind(search, pattern, nextIndex) >= 0); 
    
    // if no matches, count is alread init to 0
    return count;
}

int ImprovedFindFirstOf(cstring search, cstring pattern, bool *case_sens){
    // return the index in the text that the pattern is found
    bool sens = *case_sens;

    if (sens){
        string lower_search = ToLower(search);
        string lower_pattern = ToLower(pattern);
        return specFind(lower_search, lower_pattern);
    } else {
        return specFind(search, pattern);
    }
}

void ImprovedReplace(string &search, cstring pattern, string replace, 
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
    int diffs = 0;
    if (case_sens){ // this function did not take a reference
        s1 = ToLower(s1);
        s2 = ToLower(s2);
    }

    // showing the pre c++11 standard rather than (char ch: s1)
    for (string::size_type i=0; i < s1.length(); i++){
        if (s1[i] != s2[i]){
            diffs +=1;
        }
    }
    return diffs;
}


int main(){
    return 0;
}