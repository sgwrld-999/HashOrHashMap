#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Method 1: Using sorting and then checking the adjacent elements
    int sorting(vector<int>& nums){
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
    //Method 2: Using unordered_map to store the frequency of each element 
    //If the frequency of any element is greater than 1 then return that element
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