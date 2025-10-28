#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stack>

#include "Mystack.h"


/*
Given an array arr[ ] of n positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".
*/





/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/
bool isValid(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {

        if((s[i] == ')' || s[i] == '}' || s[i] == ']') && st.empty()) {
            return false;
        }

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if(st.top() == '(') {
                st.pop();
            }else {
                return false;
            }
        }else if(s[i] == '}') {
            if(st.top() == '{') {
                st.pop();
            }else {
                return false;
            }
        }else if(s[i] == ']') {
            if(st.top() == '[') {
                st.pop();
            }else {
                return false;
            }
        }
    }
    return st.empty()? true: false;
}