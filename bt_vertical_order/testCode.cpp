#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

/*
Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /
       2      3
      /     /
     4   5  6   7

              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
*/
struct Node {

    int key;
    Node* left;
    Node* right;

};

struct Node* newNode(int key) {
    Node* node =  new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void getVerticalOrder(Node* node, int hd, map<int,vector<int> >& mp) {
    
    if(node==NULL) {
        return;
    }
//     cout<<node->key<<endl;
    mp[hd].push_back(node->key);
    getVerticalOrder(node->left, hd-1, mp);
    getVerticalOrder(node->right, hd+1, mp);
}
void printVerticalOrder(Node* node) {
    map<int,vector<int> > mp;
    getVerticalOrder(node,0,mp);

    for(map<int,vector<int> >::iterator it = mp.begin(); it!=mp.end(); it++) {
        vector<int> vec = it->second;
        cout<<"HD "<<it->first;
        for (int i = 0; i<vec.size(); i++) {
            cout<<" "<<vec[i]<<" ";
        }
        cout<<endl;
    }

}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n\n";
    printVerticalOrder(root);
    return 0;
}