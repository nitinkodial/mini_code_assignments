// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         if(nums.size()==0||nums.size()==1)
//             return false;
//         unordered_set<int> mySet;
//         for(int i =0;i<nums.size();i++){
//             unordered_set<int>::iterator it = mySet.find(nums[i]);
//             //cout<<nums[i]<<endl;
//             if(it!=mySet.end()){
//                 return true;
//             }
//             //cout<<"x"<<endl;
//             mySet.insert(nums[i]);
//         }
//         return false;
//     }
// };
