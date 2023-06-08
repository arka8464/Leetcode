/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + ",";

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* frnt = q.front();
                q.pop();

                if (frnt->left) {
                    ans += to_string(frnt->left->val) + ",";
                    q.push(frnt->left);
                } else {
                    ans += "#,";
                }

                if (frnt->right) {
                    ans += to_string(frnt->right->val) + ",";
                    q.push(frnt->right);
                } else {
                    ans += "#,";
                }
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* frnt = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                frnt->left = nullptr;
            } else {
                TreeNode* temp = new TreeNode(stoi(str));
                frnt->left = temp;
                q.push(temp);
            }

            getline(s, str, ',');
            if (str == "#") {
                frnt->right = nullptr;
            } else {
                TreeNode* temp = new TreeNode(stoi(str));
                frnt->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));