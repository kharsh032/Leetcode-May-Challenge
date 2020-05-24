Problem Link :- https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/

/*

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

*/

//Solution

class Solution {
public:
    TreeNode* bst(TreeNode* root,int data){
        if(root==NULL){
            root=new TreeNode(data);
            return root;
        }
        if(root->val>data)
            root->left=bst(root->left,data);
        if(root->val<data)
            root->right=bst(root->right,data);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if(preorder.size()<1)
              return NULL;
        TreeNode* root= new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
            root=bst(root,preorder[i]);
        return root;
    }
};