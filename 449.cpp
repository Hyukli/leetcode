class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return " #";
        string ans = " "+to_string(root->val);
        return ans + serialize(root->left) + serialize(root->right); 
    }

    TreeNode* DFS(istringstream &is)
    {
        string str;
        is >> str;
        if(str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = DFS(is), root->right = DFS(is);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return DFS(is);
    }
};
