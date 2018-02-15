// Given a 32-bit signed integer, reverse digits of an integer.
// 
// Example 1:
// 
// Input: 123
// Output:  321
// Example 2:
// 
// Input: -123
// Output: -321
// Example 3:
// 
// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        
        cout<<x<<endl;
        long long rev = 0;
        int flag = 1;
        if(x<0){
            x = -1*x;
            flag = -1;
        }
        while(x>0){
            rev = rev*10+x%10;
            cout<<rev<<endl;
            
            x = x/10;
            
        }
        if(rev>INT_MAX||rev<INT_MIN){
                return 0;
        }
        return (int)rev*flag;
    }
};