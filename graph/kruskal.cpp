class Solution {
public:
    void solve(TreeNode* root, int target){
        if(!root)
            return;
        if(root->left==NULL&&root->right==NULL)
            return;
        
        solve(root->left,target);
        solve(root->right,target);
        if(root->left&&(root->left->val==target))
        {
            if(root->left->left==NULL&&root->left->right==NULL)
            root->left=nullptr;
            
        }
        if(root->right&&(root->right->val==target))
        {
             if(root->right->left==NULL&&root->right->right==NULL)
            root->right=nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target);
        if(root->val==target)
        {
            if(root->left==NULL&&root->right==NULL)
                root=NULL;
        }
        return root;
    }
};