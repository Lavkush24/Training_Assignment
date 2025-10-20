#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<climits>


/*
Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.

Return an array containing the index of the row, and the number of ones in it.
*/

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> oneCount;

    for(int i=0;i<mat.size(); i++) {
        int count = 0;
        for(int j=0; j<mat[0].size(); j++) {
            if(mat[i][j] == 1) {
                count++;
            }
        }
        oneCount.push_back(count);
    }

    vector<int> res;

    int max = INT_MIN;
    int ind = -1;
    for(int i=0; i<oneCount.size(); i++) {
        if(max < oneCount[i]) {
            max = oneCount[i];
            ind = i;
        }
    }

    res.push_back(ind);
    res.push_back(max);

    return res;
}



