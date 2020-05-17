Problem Link:- https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/

/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

//Solution

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty()||p.length()>s.length())
             return {};
        vector<int> cur(26),goal(26),ans;
        for(int i=0;i<p.length();i++)
            goal[p[i]-'a']++;
        for(int i=0;i<s.length();i++)
        {
             cur[s[i]-'a']++;
             if(i>=p.size())
                 cur[s[i-p.size()]-'a']--;
             if(cur==goal)
                 ans.push_back(i+1-p.size());
        }
        return ans;
    }
};