Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/

/*

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

*/

//Solution

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.empty()||s1.length()>s2.length())
             return false;
        vector<int> cur(26),goal(26);
        for(int i=0;i<s1.length();i++)
        {
            goal[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++)
        {
             cur[s2[i]-'a']++;
             if(i>=s1.size())
             {
                 cur[s2[i-s1.size()]-'a']--;
             }
             if(cur==goal)
                 return true;
        }
        return false;
    }
};