// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// 
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.


//DP, O(n) time complexity, O(1) space
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //012345
    //0 12345
    //0 1 2345
    //0 1 2 345
        //0 1 2 3 45
        // 0 1 2 3 4 5
        
    //01 2345
    //01 2 345
        int n = nums.size();
        int minProd;
        int maxProd;
        minProd = nums[0]; 
        maxProd = nums[0];
        int maxNum = nums[0];
        
        for(int i = 1 ;i<n;i++){
            int currMaxProd =  max(maxProd * nums[i],minProd * nums[i]);
            currMaxProd =  max(currMaxProd,nums[i]);
            int currMinProd =  min(maxProd * nums[i],minProd * nums[i]);
            currMinProd =  min(currMinProd, nums[i]);
            // cout<<i<< " "<<currMaxProd<<" "<<currMinProd<<endl;
            minProd = currMinProd;
            maxProd = currMaxProd;
            if(maxProd>maxNum){
                maxNum = maxProd;
            }
            

        }
        
        
        return maxNum;
    }
};

//DP, O(n^2) time complexity, O(n) space

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //012345
    //0 12345
    //0 1 2345
    //0 1 2 345
        //0 1 2 3 45
        // 0 1 2 3 4 5
        
    //01 2345
    //01 2 345
        int n = nums.size();
        vector<int>  maxProd1(n,0);
        vector<int>  maxProd2(n,0);
        
        // cout<<n<<endl;
        int max = INT_MIN;
        for(int i = 0;i<n;i++){
            maxProd1[i] = nums[i];
            if(maxProd1[i]>max){
                max = maxProd1[i];
            }
        }
        for(int k = 1 ; k<=n; k++){
            for(int i = 0 ;i<n-k;i++){
                maxProd2[i+k] =  maxProd1[i+k-1] * nums[i+k];
                
                if(maxProd2[i+k]>max){
                    max = maxProd2[i+k];
                }
                
            }
            maxProd1 = maxProd2;
        }
        //0
        
        return max;
    }
};

//DP, O(n^2) time complexity, O(n^2) space
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //012345
    //0 12345
    //0 1 2345
    //0 1 2 345
        //0 1 2 3 45
        // 0 1 2 3 4 5
        
    //01 2345
    //01 2 345
        int n = nums.size();
        cout<<n<<endl;
        vector<vector<int> > maxProd(n, vector<int>(n,0));
        cout<<"nitin"<<endl;
        int max = INT_MIN;
        for(int i = 0;i<n;i++){
            maxProd[i][i] = nums[i];
            if(maxProd[i][i]>max){
                max = maxProd[i][i];
            }
        }
        for(int k = 1 ; k<=n; k++){
            for(int i = 0 ;i<n-k;i++){
                maxProd[i][i+k] =  maxProd[i][i+k-1] * nums[i+k];
                if(maxProd[i][i+k]>max){
                    max = maxProd[i][i+k];
                }
            }
        }
        //0
        
        return max;
    }
};