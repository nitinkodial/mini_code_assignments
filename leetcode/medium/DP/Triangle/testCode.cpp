// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
// 
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).


#include <algorithm>    
class Solution {
public:
    //unoptimized space
//     int minimumTotal(vector<vector<int>>& triangle) {
//         if(triangle.size()==1){
//             return triangle[0][0];
//         }
//         vector< vector<int> > trianglePath = triangle ;
//         for(int i = 0 ;i<triangle.size();i++){
//             trianglePath.push_back(vector<int>(triangle[i].size(),-1));
//         }
//         trianglePath[0][0] = triangle[0][0];
//         int minVal = INT_MAX;
//         for(int i = 1 ;i<triangle.size();i++){
//             for(int j= 0 ;j<triangle[i].size();j++){
//                 int ulIndex = max(j-1,0);
//                 int urIndex = min(j,(int)(trianglePath[i-1].size()-1));
//                 trianglePath[i][j] = triangle[i][j] + min(trianglePath[i-1][ulIndex],trianglePath[i-1][urIndex]) ;
//                 //cout<<trianglePath[i][j]<<" "<<i<< " "<<j<<endl;
//                 if(i==triangle.size()-1){
//                     if(trianglePath[i][j]<minVal){
//                         minVal = trianglePath[i][j];
//                     }
//                 }
//             }
//         }
        
//         return minVal;
//     }
    
    //space optimized
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1){
            return triangle[0][0];
        }
        vector<int> trianglePath (triangle.size()+1,0) ;
        
        int minVal = INT_MAX;
        for(int i = triangle.size()-1 ;i>=0;i--){
            for(int j= 0 ;j<triangle[i].size();j++){
                trianglePath[j] = triangle[i][j] + min(trianglePath[j],trianglePath[j+1]) ;
                cout<<trianglePath[j]<<" "<<i<< " "<<j<<" "<<triangle[i][j+1]<<endl;
            }
            cout<<endl;
        }
        return trianglePath[0];
    }
};