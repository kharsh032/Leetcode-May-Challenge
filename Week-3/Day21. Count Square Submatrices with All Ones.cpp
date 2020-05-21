Problem Link :- https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

//Solution

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    int countSquares(vector<vector<int>>& matrix) {
        int i,j,ans=0,r,c;
        r=matrix.size();
        c=matrix[0].size();
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(matrix[i][j]&&i&&j)
                    matrix[i][j]=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]))+1;
                ans+=matrix[i][j];
            }
        }
        return ans;
    }
};