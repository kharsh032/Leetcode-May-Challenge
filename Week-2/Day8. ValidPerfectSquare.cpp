Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

*/



//Solution (We can use binary search also but i have used some another approach.

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1)
            return true;
        if(num%4==0||num%4==1)
        {
            int k;
            if(!(num&1))
                k=2;
            else
                k=3;
            for(int i=k;i<=(num/2);i+=2)
            {
                if(num==i*i)
                    return true;
            }
        }
        return false;
    }
};

//another binary search solution
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1)
            return true;
        int start=0,end=num/2;
        while(start<=end)
        {
                int mid=start+(end-start)/2;
                if((long)mid*mid==num)
                    return true;
                else if((long)mid*mid>num)
                    end=mid-1;
                else
                    start=mid+1;
        }
        return false;
    }
};