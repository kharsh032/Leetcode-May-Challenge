Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.

*/

//Solution

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        int end=nums.size()-1;
        // if(nums[end]!=nums[end-1])
        //     return nums[end];
        int start=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(mid%2==0&&nums[mid]==nums[mid+1])
                start=mid+1;
            else if(mid%2==1&&nums[mid]==nums[mid-1])
                start=mid+1;
            else
                end=mid-1;
        }
        return 0;
    }
};