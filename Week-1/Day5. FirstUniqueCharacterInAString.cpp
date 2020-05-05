Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/


//Solution

class Solution {
public:
    int firstUniqChar(string s) {
    
        int count[26]={0};
        //count frequency of every character in string
        for(int i=0;i<s.length();i++)
        {
           count[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(count[s[i]-'a']==1)
                return i;
        }
        //no such unique character
        return -1;
    }
};