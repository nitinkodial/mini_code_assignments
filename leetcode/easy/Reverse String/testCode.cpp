// Write a function that takes a string as input and returns the string reversed.
// 
// Example:
// Given s = "hello", return "olleh".

class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        if(n==0||n==1){
            return s;
        }
        
        for(int i = 0;i<n/2;i++){
            char a = s.at(i);
            char b = s.at(n-i-1);
            s.at(i) = b;
            s.at(n-i-1) = a;
            
        }
        return s;
    }
};