// Given an array of integers, every element appears twice except for one. Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    //space complexity O(n)
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> myMap;
//         for(int i = 0;i<n;i++){
//            unordered_map<int,int>::iterator it = myMap.find(nums[i]);
//             if(it!=myMap.end()){
//                 it->second = 0;
//             }
//             else{
//                 myMap.insert(make_pair(nums[i],1));
//             }
//         }
//         for(unordered_map<int,int>::iterator it = myMap.begin();it!=myMap.end();it++){
//             if(it->second==1){
//                 return it->first;
//             }
//         }
        
//     }
    
    //space complexity O(n)
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int number = 0;
        for(int i = 0;i<n;i++){
          number ^=nums[i];
        }
        return number;
        
    }
};