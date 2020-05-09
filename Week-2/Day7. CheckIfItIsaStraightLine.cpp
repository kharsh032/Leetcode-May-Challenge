Problem Link:- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

/*

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/


//Solution

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
    
    if(coordinates.size()==2)
            return true;
    double a=coordinates[1][1]-coordinates[0][1]; 
    double b=coordinates[0][0]-coordinates[1][0];
    //Slope of line
    double c=a*(coordinates[0][0])+b*(coordinates[0][1]);
     for(int i=2;i<coordinates.size();i++)
     {
         double result=a*coordinates[i][0]+b*coordinates[i][1];
         if(result!=c)
            return false;
     }
     return true;  
    }
};