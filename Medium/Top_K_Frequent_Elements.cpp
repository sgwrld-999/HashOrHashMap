#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Top K Frequent Elements
Problem Statement: Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Explanation: Given a list jsut find the frequency of each element and then sort the list in descending order or 
you can do the sorting in the accesding order and then traverse the list from the end and push the elements in the
answer list. 

The question was'nt that tricky but the thing is that how you can sort the function with respect to the frequency.
And how you can store the frequency of each element in the list with the number mapped to it.


Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Explanation: [{1,3},{2,2},{3,1}]
after sorting the list will be [{3,1},{2,2},{1,3}]
so the answer will be [1,2]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 1 && k == 1) return nums;
        vector<pair<int,int>> hashMap;
        map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] = 0 ;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++ ;
        }
        for(auto i : mp){
            hashMap.push_back(i);
        }
        //Using lambda function doint the sorting thing
        sort(hashMap.begin(), hashMap.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        vector<int> ans;
        int idx = hashMap.size() - 1 ;
        while(k--){
            ans.push_back(hashMap[idx--].first);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,1,1,2,2,3};
    vector<int>ans = s.topKFrequent(nums,2);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}