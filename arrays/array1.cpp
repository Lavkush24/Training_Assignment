#include<iostream>
using namespace std;
#include<vector>

/*
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.
*/
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



/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/
/// @brief Rotate the array k times
/// @param nums  array 
/// @param s  starting index
/// @param e  ending index
void reverse(vector<int>&nums,int s,int e) {
    while(s<e) {
        int temp = nums[s];
        nums[s] = nums[e];
        nums[e] = temp;
        s++,e--;
    }
}

void rotate(vector<int>& nums, int k) {        
    int n = nums.size();

    if(k > n) {
        k = k % n;
    }

    if(k == 0 ) {
        return ;
    }
    else {
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);    
    }
}



/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/
/// @brief find out the running sum for i  sum of all element form o to i
/// @param nums  array given 
/// @return 
vector<int> runningSum(vector<int>& nums) {
    int sum = nums[0];

    for(int i=1; i<nums.size(); i++) {
        sum += nums[i];
        nums[i] = sum;
    }

    return nums;
}


/*
You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.
*/
void findMinAndMax(vector<int> num,int& min,int& max) {
    for(int i=1; i<num.size();i++) {
        if(num[min] > num[i]) {
            min = i;
        }

        if(num[max] < num[i]) {
            max = i;
        }
    }
}

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    
    if(n == 1 || n == 2) {
        return n;
    }

    int min,max;
    min = max = 0;
    findMinAndMax(nums,min,max);

    //from both side 
    int front,end,both;

    if(min < max) {
        front = max+1;
        end = n-min;
        both = (min+1) + (n-max);
    }else {
        front = min+1;
        end = n-max;
        both = (max+1) + (n-min);
    }

    return (front < end) ? (front < both ? front : both) : (end < both ? end : both);
}


/*
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.
*/
int findmax(vector<int> num) {
    int m = num[0];
    for(int i=1; i<num.size(); i++) {
        if(m < num[i]) {
            m = num[i];
        }
    }
    return m;
}

int maxFrequencyElements(vector<int>& nums) {
    int max = findmax(nums);
    int n = nums.size();
    vector<int> res(max+1,0);

    int i =0; 
    while(i < n) {
        int count = 0;

        for(int j=0; j<n; j++) {
            if(nums[j] == nums[i]) {
                count++;
            }
        }

        res[nums[i]] = count;
        i++;
    }

    int maxFreq = findmax(res);
    int result = 0;
    i=0;
    while(i < max+1) {
        if(res[i] == maxFreq) {
            result += maxFreq;
        }
        i++;
    }  
    return result;
}