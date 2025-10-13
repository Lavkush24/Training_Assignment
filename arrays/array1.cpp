#include<iostream>
using namespace std;
#include<vector>


// reverse array after m index
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

