// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
// 
// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
// 
// Example 1:
// 
// Input: J = "aA", S = "aAAbbbb"
// Output: 3
// Example 2:
// 
// Input: J = "z", S = "ZZ"
// Output: 0

using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> myMap;
        int num=0;
        for(int i = 0;i<S.length();i++){
            char curr = S.at(i);
            unordered_map<char,int>::iterator it = myMap.find(curr);
            if(it!=myMap.end()){
                it->second = it->second + 1;
            }
            else{
                myMap.insert(make_pair(curr,1));
            }
        }
        for(int i = 0;i<J.length();i++){
            char curr = J.at(i);
            unordered_map<char,int>::iterator it = myMap.find(curr); 
            if(it!=myMap.end()){
                num = num+ it->second;
            }
        }
        return num;
    }
};