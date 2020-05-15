Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

/*

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

*/

//Solution

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> ma(N+1,0);
        //set<int> s;
        for(int i=0;i<trust.size();i++)
        {
            ma[trust[i][0]]=-1;
            if(ma[trust[i][1]]!=-1)
                ma[trust[i][1]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(ma[i]==N-1)
                return i;
        }
        return -1;
    }
};

//Brute force Solution

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int,int> > ma;
        set<int> s;
        set<int> s1;
        for(int i=0;i<trust.size();i++)
        {
            s.insert(trust[i][0]);
            ma.push_back({trust[i][0],trust[i][1]});
        }
        if(s.size()+1!=N)
            return -1;
        int judge=1;
        for(auto ii:s)
        {
            if(s.find(judge)==s.end())
                break;
            judge++;
        }
        for(int i=0;i<ma.size();i++)
        {
            if(ma[i].second==judge)
                s1.insert(ma[i].first);
        }
        if(s1.size()==N-1)
            return judge;
        return -1;
    }
};
