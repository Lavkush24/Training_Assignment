#include<iostream>
using namespace std;
#include<string>
#include<vector>


/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

/*  ------------ Analysis----------------
    Time complexcity = O(n+n/2) = O(n) :(worst case)  n when call for alphaStr and n/2 when check for palindrome
    Space complexcity = O(m)  :    0 < m < n  as the alphaNumeric string is always smaller than current string
 */
string alphaStr(string s) {
    string t = "";

    for(char ch : s) {
        if(ch >= 'a' && ch <='z') {
            t.push_back(ch);
        }

        if(ch >= 'A' && ch <='Z') {
            char c = ch + 32;
            t.push_back(c);
        }

        if(ch >= '0' && ch <= '9') {
            t.push_back(ch);
        }
    }
    return t;
}

bool isPalindrome(string s) {
    s = alphaStr(s);
    int i =0,j = s.length()-1;

    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++,j--;
    }
    return true;
}


/*
 Given a string, write a program to count the number of vowels, consonants, and spaces in that string.
*/

/*------------------- Analysis -----------------------------
    Time Complexcity = O(n + m) = O(n + 1) = O(n) : n for iteration each charater and m is fix for 10 alphabet array search (considerd as constant)
    
    Space complexcity = O(m) = O(1) : m is considered negligible so 

*/
bool isVowel(char ch) {
    char vow[] = {'a','e','i','o','u','A','E','I','O','U'};

    for(char c : vow) {
        if(ch == c) {
            return true;
        }
    }
    return false;
}

void countVowelConsonantsSpaces(string s) {
    int vowel=0,consonant=0,space=0;

    for(char ch : s) {
        if(isVowel(ch)) {
            vowel++;
        }
        else if(ch != ' ' && ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z'))) {
            consonant++;
        }
        else if(ch == ' ') {
            space++;
        }
    }
    cout<<"Vowels: "<<vowel<<endl<<"consonants: "<<consonant<<endl<<"spaces: "<<space<<endl;
}



/* 
Write a program to remove all characters from a string except alphabets in a given string.
*/

/*  ------------ Analysis----------------
    Time complexcity = O(n) = O(n) :(worst case)  for iteration 
    Space complexcity = O(m)  :    0 < m < n  as the alphaNumeric string is always smaller than current string
 */
string alphaString(string s) {
    string t = "";

    for(char ch : s) {
        if(ch >= 'a' && ch <='z') {
            t.push_back(ch);
        }

        if(ch >= 'A' && ch <='Z') {
            char c = ch;
            t.push_back(c);
        }

        if(ch == ' ') {
            t.push_back(ch);
        }
    }
    return t;
}



int main() {
    string s = "Lavkusdddssssh";
    countVowelConsonantsSpaces(s);

    cout<<alphaString(s)<<endl;

    
    return 0;
}



