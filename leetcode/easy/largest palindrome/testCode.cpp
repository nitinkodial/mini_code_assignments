// Find the largest palindrome made from the product of two n-digit numbers.
// 
// Since the result could be very large, you should return the largest palindrome mod 1337.
// 
// Example:
// 
// Input: 2
// 
// Output: 987
// 
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
// 
// Note:
// 
// The range of n is [1,8].

//java solution from leet code...
class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) 
            return 9;
        long max = (long)Math.pow(10, n)-1;
        long min = max/10;
        long t = 0;
        for (long num = max - 1; num >= min; num--) {
            t = makePalindrome(num);
            if (isFactorable(t, max, min)) {
                return (int)(t % 1337);
            }
        }
        return -1;
    }

    private long makePalindrome(long num) {
        long res = num;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    
    public boolean isFactorable(long num, long max, long min) {
        long mid = (long)Math.sqrt(num);
        if (mid > max || mid < min) 
            return false;
        long low = mid, high = mid, t = low * high;
        while (t != num) {
            if (t < num) {
                high++;
                if (high > max) 
                    return false;
            } else {
                low--;
                if (low < min) 
                    return false;
            }
            t = low * high;
        }
        return true;
    }
}