#include<iostream>
using namespace std;
#include<vector>

#include"Mystack.h"

int nextGreater(vector<int> nums,int key) {
    int res = -1;

    int i=0;
    for(i=0; i<nums.size(); i++) {
        if(key == nums[i]) {
            break;
        }
    }

    for(int j=i; j<nums.size(); j++) {
        if(nums[j] > key) {
            res = nums[j];
            break;
        } 
    }

    return res;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size(),-1);

    for(int i=0; i<nums1.size(); i++) {
        res[i] = nextGreater(nums2,nums1[i]);
    }
    return res;
}




int main() {
    Mystack<string> st;
    st.push("hello");
    st.push("hi");

    st.display();
    return 0;
}