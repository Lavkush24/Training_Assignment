#include<iostream>
using namespace std;
#include<vector>


void reverseArray(vector<int> &arr , int m) {
    int i = m+1;
    int j = arr.size()-1;

    while(i<j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }     	
}

