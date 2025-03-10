/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode* parent = NULL, * aux_root = root;
    if(!root) return NULL;
    // Binary Search
    while(1){ 
        if(root->val == key) goto delete; 
        if(key > root->val){ // goes right
            if(!root->right) return aux_root; // not able to search on the right subtree
            parent = root;
            root = root->right;
        } else { // goes left
            if(!root->left) return aux_root; // not able to search on the left subtree
            parent = root;
            root = root->left;
        }
    }
    // one of the most complicated logic that U will ever see
    transfer:
    parent = root;
    if(root->right){
        struct TreeNode* successor = root->right;
        while(successor->left){
            parent = successor;
            successor = successor->left;
        }
        root->val = successor->val;
        root = successor;
    } else 
    if(root->left){
        struct TreeNode* predecessor = root->left;
        while(predecessor->right){
            parent = predecessor;
            predecessor = predecessor->right;
        }
        root->val = predecessor->val;
        root = predecessor;
    } 
    else return NULL; // the tree has only one node and I need to delete it

    delete:

    if(!parent || (root->left && root->right)) goto transfer; // need to delete the tree's root OR the noode has 2 childs

    if(!root->left && !root->right){ // its a leaf
        if(parent->left == root)
            parent->left = NULL;
        else 
            parent->right = NULL;
    } else { // root has only one child
        if(parent->left == root)
            if(root->left) parent->left = root->left;
            else parent->left = root->right;
        else // root is the right child
            if(root->left) parent->right = root->left;
            else parent->right = root->right;
    }
    free(root);
    return aux_root;    
}
