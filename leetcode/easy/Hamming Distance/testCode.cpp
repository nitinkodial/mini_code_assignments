// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// 
// Given two integers x and y, calculate the Hamming distance.
// 
// Note:
// 0 ≤ x, y < 231.
// 
// Example:
// 
// Input: x = 1, y = 4
// 
// Output: 2
// 
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// 
// The above arrows point to positions where the corresponding bits are different.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int res = x^y;
        cout<<res<<endl;
        while(res){
            count+=res&1;
            res = res>>1;
        }
        //Faster:the “n &= n-1” turns off(set to 0) the right most 1 bit, you can see this by just trying a few examples.
//         while (res) {
//             ++count;
//             res &= res - 1;
//         }
        return count;
    }
};