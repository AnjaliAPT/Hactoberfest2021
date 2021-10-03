// Identical tree
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p) return !q;
        if(!q) return !p;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
