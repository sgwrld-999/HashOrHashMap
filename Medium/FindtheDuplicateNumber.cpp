#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] = 0 ;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++ ;
            if(mp[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int>nums = {1,3,4,2,2};
    cout << s.findDuplicate(nums) << endl;
    return 0;
}