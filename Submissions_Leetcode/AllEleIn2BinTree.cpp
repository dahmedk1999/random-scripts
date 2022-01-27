#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using std::cout;
using std::vector;

/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 
Constraints:
The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105

Runtime: 112 ms, faster than 99.30% of C++ online submissions for All Elements in Two Binary Search Trees.
Memory Usage: 84.4 MB, less than 91.41% of C++ online submissions for All Elements in Two Binary Search Trees.
 */

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traversePreO(vector<int> *vals, TreeNode *root){
        if (root==nullptr)
            return;
        vals->push_back(root->val);
        traversePreO(vals,root->left);     
        traversePreO(vals,root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values;
        TreeNode *orig1=root1,*orig2=root2; // for some reason keeping this useless line in the code speeds up Leetcode runtime by 100 ms. Submitting the code without this line results in 211ms runtime. ???
        traversePreO(&values,root1);
        traversePreO(&values,root2);
        std::sort(&values[0],&values[values.size()]);

        return values;
    }
};
