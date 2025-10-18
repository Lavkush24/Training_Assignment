#include<iostream>
using namespace std;
#include<vector>
#include<string>


/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

/*
    ----------------------Analysis--------------------------------------
    Time complexcity = 
    Space complexcity = 
*/

int index(vector<int>& num,int& sum,int& left,int i) {
    if(i == num.size()) {
        return -1;
    }

    sum = sum - num[i];
    if(sum == left) {
        return i;
    }else {
        left = left + num[i];
        return index(num,sum,left,i+1);
    }
}

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i =0; i<n; i++) {
        sum += nums[i];
    }

    int left = 0;
    return index(nums,sum,left,0);
}


/*
Given a non-negative integer n, your task is to find the nth Fibonacci number.

The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

The Fibonacci sequence is defined as follows:

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) for n > 1
*/
int nthFibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }        
    
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}



/*
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.
*/

int towerOfHanoi(int n, int from, int to, int aux) {
    if(n == 1) {
        return 1;
    }
    
    return towerOfHanoi(n-1,from,aux,to) + towerOfHanoi(n-1,aux,to,from)+1;
    
}

