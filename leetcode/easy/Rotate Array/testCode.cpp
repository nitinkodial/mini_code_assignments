// Rotate an array of n elements to the right by k steps.
// 
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
// 
// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// 
// [show hint]
// 
// Related problem: Reverse Words in a String II
// 
// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.


//Divide and conquer approach

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        
        if(k>=nums.size()){
            k = k%nums.size();
        }
        if(n==0||k<=0){
            return;
        }
        rotate_array_helper(nums,k,i);  
    }
 
    void rotate_array_helper(vector<int>&arr, int k,int i) {
        int prev_i = i;
        if(k>=arr.size()-prev_i){
          k = k%(arr.size()-prev_i);
        }
        if(k<=0){
            return;
        }
        if(i>=(arr.size()-1)){
            return ;
        }
        //cout<<endl;
        int n  = arr.size()-i;
//         cout<<"i "<<i<<" n"<<n<<endl;

        int rot_count = 0;
        for(;i<arr.size();i++){
            rot_count++;
            if(rot_count>k){
                break;
            }
            //cout<<i<<" "<<(i+n-k)<<endl;
            int tmp = arr[i];
            arr[i] = arr[(i+n-k)];
            arr[(i+n-k)] = tmp;

        }
        // for(int i = 0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        rotate_array_helper(arr,k,prev_i+k);
    }
};



// Approach #2 Using Reverse [Accepted]
// Algorithm

// This approach is based on the fact that when we rotate the array k times, k elements from the back end of the array come to the front and the rest of the elements from the front shift backwards.
// 
// In this approach, we firstly reverse all the elements of the array. Then, reversing the first k elements followed by reversing the rest n-kn−k elements gives us the required result.
// 
// Let n=7 and k=3.
// 
// Original List                   : 1 2 3 4 5 6 7
// After reversing all numbers     : 7 6 5 4 3 2 1
// After reversing first k numbers : 5 6 7 4 3 2 1
// After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result