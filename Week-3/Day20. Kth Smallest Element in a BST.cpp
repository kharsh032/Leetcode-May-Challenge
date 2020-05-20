Problem Link :- https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/

/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

*/

//Solution

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<TreeNode*> st;
    while(true)
    {
        
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
       // st.pop();
        //st.pop();
        root=st.top();
        if(--k==0)
            return root->val;
       st.pop();
       root=root->right;
    }
  ///  return root->val;
    }
};