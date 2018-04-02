// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// 
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// 
// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

class Solution {
public:
    int findMaxElement(vector<int>& nums){
      int max = nums[0];
      int maxIndex = 0;
      for(int i = 1 ;i<nums.size();i++){
          if(nums[i]>max){
              max = nums[i];
              maxIndex = i;
          }
      }
      return maxIndex; 
    }
    
    int rob(vector<int>& nums) {
        //11,2,3,5,1,111
        //11
        //11
        //14
        //16
        //16
        //127
        
        //[1,2,1,1]
        //1
        //2
        //2
        //
        
        //[2,7,9,3,1]
        //2
        //7
        //11
        //10
        //12
        
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int sum = 0;
        int prev1 = nums[0];
        int prev2 = nums[1]>=nums[0]?nums[1]:nums[0];
        sum = prev2;
        for(int i = 2;i<n;i++){
            cout<<"sum "<<sum<<endl;
            if(prev1==prev2){
                int tmp = prev2;
                prev2 = nums[i]+prev1;
                prev1 = tmp;
            }
            else{
                if(nums[i]+prev1>=prev2){
                    int tmp = prev2;
                    prev2 = nums[i]+prev1;
                    prev1 = tmp;
                }
                else{
                    prev1 = prev2;
                }
            }
            
        }
        sum = prev2;
        return prev2;
        
    }
};