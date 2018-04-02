// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// 
// Note: You can only move either down or right at any point in time.
// 
// Example 1:
// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]

#include <algorithm>
class Solution {
public:
    int min_val(int x,int y){
        return (x<=y)?x:y;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m<n){
            vector<int> path(m,0);
            for(int i = 0;i<n;i++){
                path[0] = path[0] + grid[0][i]; 
                for(int j = 1; j<m;j++){
                    if(i==0){
                        path[j] = grid[j][i] + path[j-1]; 
                    }
                    else{
                        path[j] = grid[j][i] + min_val(path[j],path[j-1]);
                    }
                }
            }
            return path[m-1];
        }
        else{
            vector<int> path(n,0);
            for(int i = 0;i<m;i++){
                path[0] = path[0] + grid[i][0]; 
                // cout<<path[0]<<endl;
                for(int j = 1; j<n;j++){
                    if(i==0){
                        path[j] = (grid[i][j] + path[j-1]);    
                    }
                    else{
                        path[j] = (grid[i][j] + min_val(path[j],path[j-1]));
                    }
                    // cout<<path[j]<<endl;
                }
                // cout<<endl;
            }
            return path[n-1];
            
        }
        
        
    }
};