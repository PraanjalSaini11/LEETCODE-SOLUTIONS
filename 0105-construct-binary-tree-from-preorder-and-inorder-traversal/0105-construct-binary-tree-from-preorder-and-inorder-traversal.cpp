class Solution {
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return NULL;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        int mid = mp[value];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        preIndex = 0;

        return build(preorder, 0, inorder.size() - 1);
    }
};