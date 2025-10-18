#include<iostream>
using namespace std;
#include<string>
#include<vector>




/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;

    int bottom = matrix.size()-1;
    int right = matrix[0].size()-1;
    int top = 0;
    int left = 0;

    while(top <= bottom && left <= right) {

        for(int j=left; j<=right; j++) {
            res.push_back(matrix[top][j]);
        }
        top++;

        for(int i=top; i<=bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(int j=right; j>=left; j--) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i=bottom; i>=top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}






/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j < matrix[0].size(); j++) {
            if(target == matrix[i][j]) {
                return true;
            }
        }
    }
    return false;
}


/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

