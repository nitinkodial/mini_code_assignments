// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
// 
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
// 
// Follow up:
// 
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
// Credits:
// Special thanks to @ syedee for adding this problem and creating all test cases.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        if(num==0){
            result.push_back(0);
            return result;
        }
        else if(num==1){
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        int numOfBits = ceil(log2(num+1));
        // cout<<numOfBits<<endl;
  
        result.push_back(0);
        result.push_back(1);
        int num_done = 2;
        int k = 1;
        bool flag = false;
        for(int i = 2;i<=numOfBits;i++){
            
            int num_curr = pow(2,i) - num_done; //4-2,
            // cout<< num_done<<" "<<num_curr<<endl;
            for(int j=0;j<num_curr;j++){
               result.push_back(1+result[j]); 
               k++;
               if(k==num){
                   flag = true;
                   break;
               }
            }
            if(flag){
                break;
            }
            num_done = num_curr + num_done;
        }

        return result;
    }
};




