#include<bits/stdc++.h>
using namespace std;
/*
Problem Link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
Problem name : Group the People Given the Group Size They Belong To
Explanation : 
            Using the map to store the group size as key and the vector of people as value.
            If the size of the vector is equal to the group size then push the vector in the answer and clear the vector.
            If the size of the vector is less than the group size then push the index of the person in the vector.
            At last push the remaining vectors in the answer.
Time Complexity : O(n)
Space Complexity : O(n)
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        
        for (int i = 0; i < groupSizes.size(); i++) {
            if (mp[groupSizes[i]].size() < groupSizes[i]) {
                mp[groupSizes[i]].push_back(i);
            } else {
                ans.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
                mp[groupSizes[i]].push_back(i);
            }
        }

        for (auto& entry : mp) {
            if (!entry.second.empty()) {
                ans.push_back(entry.second);
            }
        }

        return ans;
    }
};
