#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }
        sort(nums.begin(), nums.end());
        int ctr = 1 ;
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] == 1) {
                ctr++;
                maxLen = max(maxLen,ctr);
            }else if(nums[i] == nums[i-1]) continue ;
            else ctr = 1;
        }

        return maxLen;
    }
};