#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Reverse Words in a String
Problem link : https://leetcode.com/problems/reverse-words-in-a-string/

*/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int ctr = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (ctr > 0) {
                    st.push(s.substr(i - ctr, ctr));
                    ctr = 0;
                }
            } else {
                ctr++;
            }
        }

        // Handle the last word in the string
        if (ctr > 0) {
            st.push(s.substr(s.size() - ctr, ctr));
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            ans += " ";
            st.pop();
        }

        // Remove the trailing space
        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};
