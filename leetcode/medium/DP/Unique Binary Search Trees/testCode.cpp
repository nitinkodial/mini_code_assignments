// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
// 
// For example,
// Given n = 3, there are a total of 5 unique BST's.
// 
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n,0);
        if(n==1||n==0){
            return n;
        }
        a[0] = 1;
        // cout<<a[0]<<endl;
        for(int i = 1;i<n;i++){
            int numOfNodes = i + 1;
            
            for(int j = 1 ; j<=numOfNodes ; j++){
                if(j==1){
                    a[i] = a[i]+a[i-1];        
                }
                else if(j==numOfNodes){
                    a[i] = a[i]+a[i-1];
                }
                else{
                    a[i] = a[i] + a[j-2]*a[numOfNodes-j-1];
                }
            }
            // cout<<a[i]<<endl;
        }
        return a[n-1];
    }
};