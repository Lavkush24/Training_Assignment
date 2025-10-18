#include<iostream>
using namespace std;
#include<vector>


/*
Given the non-negative integers n , compute the factorial of a given number.
*/
int factorial(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return factorial(n-1)*n;
}


/*
Given an positive integer n, print numbers from 1 to n without using loops.

Implement the function printTillN() to print the numbers from 1 to n as space-separated integers.
*/
void printTillN(int n) {
    if(n == 1) {
        cout<<1<<" ";
        return;
    }
    printTillN(n-1);
    cout<<n<<" ";
}


/*
Given a number n, find the value of n raised to the power of its own reverse.
Note: The result will always fit into a 32-bit signed integer.
*/


/*
Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder when n is divided by d is 0 (n % d == 0).
Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.
*/

int sumArray(vector<int> arr) {
    if(arr.empty()) {
        return 0;
    }
    int t = arr.back();
    arr.pop_back();
    return t + sumArray(arr);
}




int main() {
    cout<<factorial(5)<<endl;
    vector<int> s = {3,4,5,5};
    cout<<sumArray(s)<<endl;
}