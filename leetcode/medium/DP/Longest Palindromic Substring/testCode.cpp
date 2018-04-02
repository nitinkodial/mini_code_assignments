// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
// 
// Example:
// 
// Input: "babad"
// 
// Output: "bab"
// 
// Note: "aba" is also a valid answer.
//  
// 
// Example:
// 
// Input: "cbbd"
// 
// Output: "bb"


// class Solution {
// public:
//     //iterative //unoptimized
//     bool isPalin(string s,int i,int j){
//         while(i<j){
//             if(s.at(i)!=s.at(j)){
//                 return false;
//             }
//             else{
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         int l =0, r =0;
//         int max = 0; 
//         int n =  s.length();
//         
//         for(int i = 0;i<n;i++){
//             for(int j =0 ;j<n;j++){
//                 if(i==j&&1>max){
//                     max = 1;
//                     l = i;
//                     r = j;
//                 }
//                 else if(i!=j){
//                     if(isPalin(s,i,j)){
//                         if((j-i+1)>max){
//                             max = j-i+1;
//                             l = i;
//                             r = j;
//                         }
//                     }
//                 }
//             }
//         }
//         return s.substr(l,r-l+1);
//     }
// };

class Solution {
public:
    //DP, optimized, can be reduced to O(1) space, check leetcode for that. This is O(n^2) space.
    string longestPalindrome(string s) {
        if(s==""){
            return s;
        }
        int n = s.length();
        vector<vector<int> > table(n,vector<int>(n,0));
        for(int i =0;i<n;i++){
            table[i][i]=1;
        }
        int l = 0,  max = 1;
        for(int i =0;i<n-1;i++){
            if(s.at(i)==s.at(i+1)){
                table[i][i+1]=1;
                l = i;
                max = 2;
            }
        }
        
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j = i+k;
                // cout<<i<<" "<<j<<endl;
                int t = table[i+1][j-1];
                if(t>0&&(s.at(i)==s.at(j))){
                    table[i][j] = 1;
                    if(k+1>max){
                        max = k+1;
                        l = i;
                    }
                }
                // cout<<table[i][j]<<endl;
                
            }
        }
        cout<<l<<" "<<max<<endl;
        return s.substr(l,max);
    }
};


/*
 class Solution {
public:
    vector<int> longestPalindromeH(string s,int i,int j,unordered_map<string,vector<int> >& myMap){
        vector<int> result;
        unordered_map<string,vector<int> >::iterator it = myMap.find(s.substr(i,j-i+1));
        if(it!=myMap.end()){
            result= it->second;
            return result;
        }
        //cout<<"x "<<s.substr(i,j-i+1)<<" "<<i<< " "<<j<<endl; 
        if(i+1==j){
            if(s.at(i)==s.at(j)){
                result.push_back(2);
                result.push_back(i);
                result.push_back(j);
                ////cout<<s.substr(i,j-i+1)<<" "<<result[0]<<" "<<result[1]<< " "<<result[2]<<endl;
                string curr = s.substr(i,j-i+1);
                myMap.insert(make_pair(curr,result));
                return result;    
            }
            else{
                result.push_back(1);
                result.push_back(i);
                result.push_back(j-1);
                myMap.insert(make_pair(s.substr(i,j-i+1),result));
                // //cout<<s.substr(i,j-i)<<" "<<result[0]<<" "<<result[1]<< " "<<result[2]<<endl; 
                return result;
            }
        }
        if(i==j){
            
            result.push_back(1);
            result.push_back(i);
            result.push_back(j);
            myMap.insert(make_pair(s.substr(i,j-i+1),result));
            ////cout<<s.substr(i,j-i+1)<<" "<<result[0]<<" "<<result[1]<< " "<<result[2]<<endl; 
            return result;
        }
        int max = -1;
        vector<int> m1V(3,0),m2V(3,0),m3V(3,0);
        m1V = longestPalindromeH(s,i,j-1,myMap);
        if(i+1<=j){
            m2V = longestPalindromeH(s,i+1,j,myMap);
        }
        if(i+1<=j-1){
            ////cout<<s.substr(i+1,j-1+i)<<" y"<<endl;
            m3V = longestPalindromeH(s,i+1,j-1,myMap);
            ////cout<< m3V[0]<<" "<<i<<" "<<j<<" "<<m3V[1]<<" "<<m3V[2]<<" yy"<<endl;
        }
        
        int m1 = m1V[0];
        int m2 = m2V[0];
        int m3 = m3V[0];
        bool flag = false;
        if(s.at(i)==s.at(j)&&(m3V[2]-m3V[1]+1)==j-i-1){
            m3 = m3+2 ;
            flag = true;
        }
        ////cout<<m3<<" yyy"<<endl;
        if(m3>m2){
            if(m3>m1){
                result.push_back(m3);
                if(flag){
                    result.push_back(i);
                    result.push_back(j);
                }
                else{
                    result.push_back(m3V[1]);
                    result.push_back(m3V[2]);
                }
            }
            else{
                result.push_back(m1);
                result.push_back(m1V[1]);
                result.push_back(m1V[2]);
            }
        }
        else{
            if(m2>m1){
                result.push_back(m2);
                result.push_back(m2V[1]);
                result.push_back(m2V[2]);
            }
            else{
                result.push_back(m1);
                result.push_back(m1V[1]);
                result.push_back(m1V[2]);
            }
        }
        myMap.insert(make_pair(s.substr(i,j-i+1),result));
        // unordered_map<string,vector<int> >::iterator it2 = myMap.find(s.substr(result[1],result[2]-result[1]+1));
        // if(it2!=myMap.end()){
            // //cout<<"z "<<s.substr(result[1],result[2]-result[1]+1)<<endl;
        // }
        //cout<<"y "<<s.substr(i,j-i+1)<<" "<<result[0]<<" "<<result[1]<< " "<<result[2]<<endl; 
        return result;
    }
    string longestPalindrome(string s) {
        
        int max = 0; 
        int n =  s.length();
        int l =0, r =n-1;
        unordered_map<string,vector<int> > myMap;
        vector<int> result = longestPalindromeH(s,l,r,myMap);
        l = result[1];
        r = result[2];
        return s.substr(l,r-l+1);
    }
};
*/