class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* leftmost = root;

        while (leftmost->left) {
            Node* curr = leftmost;

            while (curr) {
                curr->left->next = curr->right;

                if (curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};