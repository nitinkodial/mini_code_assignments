// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
// 
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// 
// Return true because "leetcode" can be segmented as "leet code".


//Method 1 : Recursive Solution O(n^n) time complexity and O(n) space complexity
using namespace std;
class Solution {
public:
    
    
    /*
    Take string and traverse it, creating string from start to index i. Check if the substr belongs to dict, if yes just add it to 
    new string with space and start checking new substr from where i onwards.
    
    s =length n
    wordDict =  length m
    */
    bool wordBreakH(string s, unordered_set<string> wordSet){
        //cout<<"d0 "<<s<<endl;
      if(wordSet.find(s)!=wordSet.end()){
          return true;
      }
        else{
      for(int i =0;i<s.length();i++){
         //cout<<s.substr(0,i)<<" "<<s.substr(i,s.length()-i)<<endl;
           if (wordBreakH(s.substr(0,i),wordSet)){
               if(wordBreakH(s.substr(i,s.length()-i),wordSet)){
                   return true;
               }
            }
      }
        
    return 0;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>  wordSet;
        for(int i=0;i<wordDict.size();i++){
            wordSet.insert(wordDict[i]);
        }
        //return 0;
        return wordBreakH(s,wordSet);
        
    }

    
};


//Method 2 : Recursive solution using memoization
// Time complexity : O(n^2). Size of recursion tree can go up to n^2
//Space complexity : O(n). The depth of recursion tree can go up to n.
using namespace std;
class Solution {
public:
    
    
    /*
    Take string and traverse it, creating string from start to index i. Check if the substr belongs to dict, if yes just add it to 
    new string with space and start checking new substr from where i onwards.
    
    s =length n
    wordDict =  length m
    */
    bool wordBreakH(string s, unordered_set<string> wordSet,unordered_map<string,bool>& memoCache){
        //cout<<"d0 "<<s<<endl;
          bool result = false;
        if(wordSet.find(s)!=wordSet.end()){
          //    cout<<"d0.5 "<<s<<endl;
              result = true;
        }
        else if(memoCache.find(s)!=memoCache.end()){
            //cout<<"d1 "<<s<<endl;
            return(memoCache.find(s)->second);
        }
        else{
          for(int i =0;i<s.length();i++){
             //cout<<"x0 "<<s.substr(0,i)<<" "<<s.substr(i,s.length()-i)<<endl;
              //cout<<endl;
              //cout<<"x1 "<<wordBreakH(s.substr(0,i),wordSet,memoCache)<<endl;
               if (wordBreakH(s.substr(0,i),wordSet,memoCache)){
                //   cout<<"d1.5"<<endl;
                   if(wordBreakH(s.substr(i,s.length()-i),wordSet,memoCache)){
                       result = true;
                       break;
                   }
                }
          }
        }
       // cout<<"d2 "<<s<< " "<<result<<endl;    
        memoCache.insert(make_pair(s,result));      
        return result;
    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>  wordSet;
        unordered_map<string,bool> memoCache;
        for(int i=0;i<wordDict.size();i++){
            wordSet.insert(wordDict[i]);
        }
        //return 0;
        return wordBreakH(s,wordSet,memoCache);
        
    }

    
};