class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> levels;
        if (root == NULL)
            return {};

        if (root -> left == NULL and root->right == NULL)
            return {{root->val}};
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* n = q.front();
            if (n == NULL) {
                ans.push_back(levels);
                levels.clear();
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }
            else {
                levels.push_back(n->val);
                q.pop();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }

        return ans;
    }
};

/*
Complexity Analysis-
N is number of nodes in Binary tree
Time Complexity - O(N) as each node is traversed only once
Space Complexity - O(N)
*/