#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Isomorphic Strings
Problem link : https://leetcode.com/problems/isomorphic-strings/

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            if (mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i]) {
                return false;
            } else if (mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i]) {
                return false;
            }

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("badc", "baba") << endl;
    return 0;
}