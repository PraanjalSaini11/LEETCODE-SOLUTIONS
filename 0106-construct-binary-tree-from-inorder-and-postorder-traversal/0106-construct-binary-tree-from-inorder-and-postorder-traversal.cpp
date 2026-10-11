class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int idx = postorder.size() - 1;

        return solve(inorder, postorder, idx, 0, inorder.size() - 1, mp);
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& idx,
                    int l, int r, unordered_map<int, int>& mp) {
        if (l > r) return nullptr;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->right = solve(inorder, postorder, idx, mid + 1, r, mp);
        root->left = solve(inorder, postorder, idx, l, mid - 1, mp);

        return root;
    }
};