Problem Link :- https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/

/*

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/

//Solution

class Solution {
public:
    string frequencySort(string s) 
    {
      unordered_map<char,int> a;
        for(auto i:s)
            a[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:a)
            pq.push({i.second,i.first});
        s="";
        int freq;
        char ch;
        while(!pq.empty())
        {
            freq=pq.top().first;
            ch=pq.top().second;
            pq.pop();
            s.append(freq,ch);
        }
        return s;
    }
};