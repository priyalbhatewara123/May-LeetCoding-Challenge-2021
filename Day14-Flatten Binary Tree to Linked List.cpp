class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        if (root -> left == NULL and root -> right == NULL)
            return;

        if (root -> left != NULL) {
            flatten(root -> left);
            TreeNode* temp = root -> right;
            root -> right = root -> left;
            root -> left = NULL;

            TreeNode* curr = root -> right;
            while (curr -> right)
                curr = curr -> right;

            curr -> right = temp;

        }

        flatten(root -> right);
    }
};