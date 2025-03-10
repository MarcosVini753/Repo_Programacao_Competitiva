/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char inorder(struct TreeNode* root, long *prev){
    if(!root) return 1;

    if(!inorder(root->left, prev)) return 0;

    if(*prev >= root->val) return 0; *prev = root->val;

    return inorder(root->right, prev);
}
bool isValidBST(struct TreeNode* root) {
    long prev = -0x3f3f3f3f3f3f3f3f;
    return inorder(root, &prev);
}
