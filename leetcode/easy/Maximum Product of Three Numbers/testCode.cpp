// Given an integer array, find three numbers whose product is maximum and output the maximum product.

// Example 1:
// Input: [1,2,3]
// Output: 6
// Example 2:
// Input: [1,2,3,4]
// Output: 24
// Note:
// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.


class Solution {
public:
    int findKthElement(vector<int>& nums,int k){
      random_shuffle (nums.begin(), nums.end());
      nth_element (nums.begin(), nums.begin()+k, nums.end());
      return nums[k]; 
    }
    int maximumProduct(vector<int>& nums) {
      int n = nums.size();
      int max1 = findKthElement(nums,n-1);
      int max2 = findKthElement(nums,n-2);
      int max3 = findKthElement(nums,n-3);
      int min1 = findKthElement(nums,0);
      int min2 = findKthElement(nums,1);
        
        int tmpmax1 = max1*max2*max3;
        int tmpmax2 = min1*min2*max1;
        return (tmpmax1>tmpmax2?tmpmax1:tmpmax2);
        
        
        
    }
};