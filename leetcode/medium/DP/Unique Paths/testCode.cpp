// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// 
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// 
// How many possible unique paths are there?
// 
// 
// Above is a 3 x 7 grid. How many possible unique paths are there?


class Solution {
public:
    //unoptimized
//     int uniquePaths(int m, int n) {
//         cout<<m<<" "<<n<<endl;
//         vector<vector<int> > paths(m,vector<int>(n,-1));
//         paths[0][0] = 1;
//         for(int i = 1 ;i<n;i++){
//             paths[0][i] = 1;
//         }
//         for(int i = 1 ;i<m;i++){
//             paths[i][0] = 1;
//         }
//         for(int i = 1 ;i<m;i++){
//             for(int j = 1 ;j<n;j++){
//                 paths[i][j] = paths[i-1][j] + paths[i][j-1];
//             }
//         }
        
//         return paths[m-1][n-1];
    
        
//     }
    
    //space optimized
    int uniquePaths(int m, int n) {
        if(m>n){
            return uniquePaths(n,m);
        }
        vector<int> paths(m,1);
        
        for(int i = 1 ;i<n;i++){
            for(int j = 1 ;j<m;j++){
                paths[j] = paths[j] + paths[j-1];
            }
        }
        
        return paths[m-1];
    
        
    }
};