#include<iostream>
using namespace std;
#include<vector>



/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
bool present(vector<int> num,int key) {
    for(int i =0; i<num.size(); i++) {
        if(key == num[i]) {
            return true;
        }
    }
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;

    for(int i=0; i<nums1.size(); i++) {
        for(int j = 0; j<nums2.size(); j++) {
            if(nums1[i] == nums2[j] && !present(res,nums1[i])) {
                res.push_back(nums1[i]);
            }
        }
    }
    return res;
}