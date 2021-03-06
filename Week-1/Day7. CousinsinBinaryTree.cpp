Problem Link :-https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

/*

Cousins In Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
 
Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Note:
1. The number of nodes in the tree will be between 2 and 100.
2. Each node has a unique integer value from 1 to 100.

*/

//Solution 
/*We use queue q to iterate through the current level nodes and populate their children into q1. We also insert nullptr into q1 after inserting each node's children (to separate siblings froum cousins).

If we find a node with value x or y, we have one potential cousin. If we find another potential cousin, we return true if they are not siblings (nullptr sets siblings to false). If we finished the level with just one potential cousin, we stop and return false.*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
      queue<TreeNode*> q, q1;
      bool siblings = false;
      bool cousin = false;
      q.push(root);
      while (!q.empty() && !cousin)
      {
        while (!q.empty()) 
        {
          auto n = q.front();
          q.pop();
          if (n == nullptr) siblings = false;
          else 
          {
            if (n->val == x || n->val == y) 
            {
              if (!cousin) 
              cousin = siblings = true;
              else return !siblings;
            }
            q1.push(n->left); 
            q1.push(n->right);
            q1.push(nullptr);
          }
        }
        swap(q, q1);
      }
      return false;
      }
};