#include<iostream>
using namespace std;
#include<string>
#include<vector>


/* 
Given a string, calculate the frequency of characters in a string.
*/

/*  ------------ Analysis----------------
    Time complexcity = O(n*m) = O(n) :(worst case) n for all alphabet iteration and m is grdually decreasing as s is update (shrink ) every time inside loop run. 
    Space complexcity = O(m)  : depend on unique cahracter in the string  0 < m < n
*/

class Pair {
    public: 
        char ch;
        int freq;

        Pair(char c,int f) {
            ch = c;
            freq = f;
        }
};

vector<Pair*> countFreq(string s) {
    vector<Pair*> freqTable;
    int j=0;

    while(!s.empty()) {
        string t = "";
        Pair *p = new Pair(s[0],0);
        for(int j=0; j<s.length(); j++) {
            if(s[0] == s[j]) {
                p->freq++;
            }else {
                t.push_back(s[j]);
            }
        }
        freqTable.push_back(p);
        s = t;
    }
    return freqTable;
}



/*
 Given a string, return the character that occurs the maximum number of times in the string. If the maximum occurrence of two or more characters is the same, return any one of them. 
*/

/*  ------------ Analysis----------------
    Time complexcity = O(n*m) = O(n) :(worst case) n for call to countFreq(s)
    Space complexcity = O(1)
*/
Pair* printMaximumOccurance(string s) {
    Pair* max = new Pair(' ',0);

    vector<Pair*> freq = countFreq(s);

    for(int i=0; i<freq.size(); i++) {
        if(freq[i]->freq > max->freq) {
            max = freq[i];
        }
    }

    return max;
}

int main() {
    string s = "Lavkusssssh";
    
    Pair* p = printMaximumOccurance(s);

    cout<<"maximum "<<p->ch<<" : "<<p->freq<<endl;
    return 0;
}