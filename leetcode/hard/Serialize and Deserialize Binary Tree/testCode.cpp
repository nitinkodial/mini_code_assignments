// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// 
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// 
// For example, you may serialize the following tree
// 
//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 //Method: I used preorder traversal
 //Note: Because of strings and vectors, I didnt pass 3 out of 48 testcases because of really long inputs. Need to optmize and use faster structures for parsing string. I passed 45 out of 48 cases.


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
        if(root==NULL){
            return "";
        }
        else{
            string s="";
            //s = s + convertInttoString(root->val)  + ",";
            int nodeCount = 1;
            int entryCount = 1;
            traversalHelper(root,s,nodeCount,entryCount);
            cout<<s<<endl;
            return s;
        }
        
    }
    string convertInttoString(int n){
        stringstream ss;
        ss << n;
        string str = ss.str();
        return str;
    }
    void traversalHelper(TreeNode* root, string& s,int& nodeCount, int& entryCount){
        if(root==NULL){
            s =s +",NULL";
            return;
        }
        if(s==""){
            s = convertInttoString(root->val) ;
        }
        else{
            s = s +"," + convertInttoString(root->val) ;
        }
        traversalHelper(root->left, s,nodeCount,entryCount);
        traversalHelper(root->right, s,nodeCount,entryCount); 
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        else{
         vector<string> str;
         string  s = "";
         for(int i = 0;i<data.length();i++){
            char curr = data.at(i);
            // cout<<curr<<""<<i;
            if(curr!=','){
                s = s + curr; 
            }
            else{
                str.push_back(s);
               // cout<<s<<endl;
                s  = "";
            }
            if(i==(data.length()-1)){
                str.push_back(s);
                //cout<<endl<<s<<endl;
                s  = "";
            }
         }
            TreeNode* root;
            int index = 0;
            root = treeCreaterHelper(root,str,index);
            return root;
        }    
    }
    int stringToInt(string s){
        stringstream ss(s);
        int x = 0;
        ss>>x;
        return x;
    }
    
    TreeNode* treeCreaterHelper(TreeNode* root, vector<string> s ,int& index){
        //cout<<s[index]<<"xx"<<index<<endl;
        if(s[index ]=="NULL"){
            root = NULL;
            return root;
        }
        root = new TreeNode(stringToInt(s[index]));
        //root->val = stringToInt(s[index]);
        int leftIndex = index +1;
        int rightIndex = index +2;
        //cout<<index<<" "<<leftIndex<< " "<<rightIndex<<endl;
        root->left = treeCreaterHelper(root->left,s,++index);
        root->right = treeCreaterHelper(root->right,s,++index);
        
        return root;
        
            

    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));