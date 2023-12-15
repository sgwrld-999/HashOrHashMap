#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Group Anagrams
Problem link : https://leetcode.com/problems/group-anagrams/
Time Complexity : O(n*mlogm)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s : strs){
            string t = s ;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : mp)ans.push_back(it.second);

        return ans;
    }
};