#include<bits/stdc++.h>
using namespace std;
/*
Problem Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/
Description  : Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
               A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
               0 <= i, j < nums.length
               i != j
               |nums[i] - nums[j]| == k
               Notice that |val| denotes the absolute value of val.

Explanation : Example 1:
               Input: nums = [3,1,4,1,5], k = 2
               Output: 2
               Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
               Although we have two 1s in the input, we should only return the number of unique pairs.
               Example 2:
               Input: nums = [1,2,3,4,5], k = 1
               Output: 4
               Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
               Example 3:
               Input: nums = [1,3,1,5,4], k = 0
               Output: 1
               Explanation: There is one 0-diff pair in the array, (1, 1).
               Example 4:
               Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
               Output: 2
               Example 5:
               Input: nums = [-1,-2,-3], k = 1
               Output: 2
            First Approach : Sorting and using set to store the unique pairs.Finding the all pairs and checking if the pair is unique or not.
            Time Complexity : O(n^2)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ctr = 0;
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {
            set<int> st;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i; j < n; j++) {
                if (i != j && abs(nums[i] - nums[j]) == k) {
                    if (st.find(nums[j]) == st.end()) {
                        st.insert(nums[j]);
                        ctr++;
                    }
                }
            }
        }
        return ctr;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,4,1,5};
    int k = 2;
    cout << s.findPairs(nums, k) << endl;
    return 0;
}