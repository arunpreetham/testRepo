

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Codec {
public:

    // Encodes a tree to a single string.
    void helpSerialize(TreeNode* root, string *str)
    {
        if(!root)
        {
            str->push_back((char)'#');
            return;
        }
        str->push_back((char)'*');
        str->append(to_string(root->val));
        str->push_back((char)'*');
        helpSerialize(root->left,str);
        helpSerialize(root->right,str);
    }
    string serialize(TreeNode* root) {
        string str;
        if(root)
            helpSerialize(root, &str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        TreeNode * root;
        deserialize(&data,2);
        return root;
    }
    
    TreeNode* deserialize(string *data, int val) {
        if(*data == "")
            return NULL;
        
        int n = data->size();
        string temp;
         TreeNode * root;
        int state = 0;//start        
        
        for(int i=0;i<n;i++)
        {
            if(data->at(i) == '#')
            {
                data->erase(i,1);
                return NULL;
            }
            if(data->at(i) == '*' && temp == "")
            {
                state = 0;
                continue;
            }
            else if(data->at(i) == '*' && temp != "")
            {
                state = 1;//end of char
                int value = stoi(temp);
                temp.clear();
                
                root = new TreeNode(value);
                
                data->erase(0,i+1);                
                root->left = deserialize(data, 1);
                root->right = deserialize(data,1);
                return root;
            }
            //if(state == 0)
            {
                state = 1;
                temp.push_back(data->at(i));
            }
            
           
        }
            
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));