Link:- https://leetcode.com/problems/add-one-row-to-tree/
class Solution {
private:
    void GetNewRoot(TreeNode* root,int val,int curr_depth,int depth){
        if(root==NULL) return;
        if(curr_depth==(depth-1)){
            TreeNode* newLeft=new TreeNode(val);
            TreeNode* newRight=new TreeNode(val);
            newLeft->left=root->left;
            root->left=newLeft;
            newRight->right=root->right;
            root->right=newRight;
            return;
        }
        GetNewRoot(root->left,val,curr_depth+1,depth);
        GetNewRoot(root->right,val,curr_depth+1,depth);
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        GetNewRoot(root,val,1,depth);
        return root;
    }
};
