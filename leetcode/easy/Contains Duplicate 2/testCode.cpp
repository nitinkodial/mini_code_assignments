class Solution {
public:
    //UnOptimized space solution
    /*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return false;
        }
        
        for(int i = 0;i<n;i++){
            for(int j=i+1;(j-i)<=k;j++){
                if(j<n){
                    if(nums[i]==nums[j]){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    */
    
    //O(n) solution using hash set (not hash map)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return false;
        }
        unordered_set<int> myMap;
        
        for(int i = 0;i<n;i++){
           unordered_set<int>::iterator it = myMap.find(nums[i]);
            if(it!=myMap.end()){
                return true;
            }
            else{
                
                myMap.insert(nums[i]);
                if(myMap.size()>k){
                    myMap.erase(nums[i-k]);
                }
            }
        }
        
        return false;
        
    }
};
//0,1,2,3,4,5,6,7,8
//99,99
//i0,j1,k2
//i2,j3,