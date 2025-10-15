#include<iostream>
using namespace std;
#include<vector>

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int j = i+1;

    while(j < nums.size()) {
        if(nums[i] != nums[j]) {
            i++;
            swap(&nums[i],&nums[j]);
        }
        j++;
    }

    return i+1;
}



/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/
int pivotIndex(vector<int>& nums) {
    int rightSum = 0,leftSum = 0;

    for(int i=0; i<nums.size() ; i++){
        rightSum += nums[i];
    }  


    int j=0;
    while(j < nums.size()) {
        rightSum -= nums[j];
        if(rightSum == leftSum) {
            return j;
        }
        leftSum += nums[j];
        j++;
    } 

    return -1;
}