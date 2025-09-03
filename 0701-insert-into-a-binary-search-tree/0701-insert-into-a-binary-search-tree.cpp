/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node=new TreeNode(val);
        
        if(root==NULL)
        {
            root=node;
            return root;
        }
        
        TreeNode*temp=root;
        
        
        
        while(temp)
        {
            if(val>temp->val )
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                else {
                    temp->right=node;
                    break;
                }
            }
            else {
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                else {
                    temp->left=node;
                    break;
                }
            }
           
        }
        return root;
    }
};