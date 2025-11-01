#include<iostream>
using namespace std;

/*
You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).
*/
 int countSetBits(int n) {
    int res = 0;
    for(int i=1; i<=n; i++) {
        int t = i;
        while(t > 0) {
            if(t%2 == 1) {
                res++;
            }
            t = t/2;
        }
    }
    return res;
}

/* find out the optimize one */