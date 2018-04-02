// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// 
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// 
// The number of ways decoding "12" is 2.


class Solution {
public:
    int numDecodings(string s) {
        if(s==""||s=="0"){
            return 0;
        }
        else{
            int n = s.size();
            vector<int> arr(n+1,0);
            arr[n]=1;
            arr[n-1] = ((s.at(n-1)-'0')!=0?1:0);
            
            for(int i = n-2;i>=0;i--){
                int curr = s.at(i)-'0';
                int next = s.at(i+1)-'0';
                int num = curr*10+next;
                if(curr==0){
                    continue;
                }
                if(num<=26){
                    arr[i] = arr[i+1]+arr[i+2];
                }
                else{
                    arr[i] = arr[i+1];
                }
            }
            return arr[0];
        }
        
    }
};