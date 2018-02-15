// Given a package with a weight limit limit and an array arr of item weights, implement a function getIndicesOfItemWeights that finds two items whose sum of weights equals the weight limit limit. Your function should return a pair [i, j] of the indices of the item weights, ordered such that i > j. If such a pair doesn’t exist, return an empty array.
//
// Analyze the time and space complexities of your solution.
//
// Example:
//
// input:  arr = [4, 6, 10, 15, 16],  lim = 21
//
// output: [3, 1] # since these are the indices of the
//                # weights 6 and 15 whose sum equals to 21

#include <iostream>
#include <vector>
#include <unordered_map>
// prabhuh@gmail.com

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
    // your code goes here
    unordered_map<int,vector<int> > fMap;
    for(int i=0; i<arr.size(); i++) {
        unordered_map<int,vector<int> >::iterator it = fMap.find(arr[i]);
        if(it!=fMap.end()) {
            (it->second).push_back(i);
        }
        else {
            vector<int> curr;
            curr.push_back(i);
            fMap.insert(make_pair(arr[i],curr));
        }
    }
    vector<int> result;
    unordered_map<int,vector<int> >::iterator it;
    for(it=fMap.begin(); it!=fMap.end(); it++) {
        vector<int> orig = it->second;
        int fEle = it->first;
        int diff = limit - fEle;
        if(diff==fEle) {
            vector<int> curr = it->second;
//             cout<<it->first<<" "<<curr.size()<<endl;
            if(curr.size()>1) {
                if(curr[0]>curr[1]) {
                    result.push_back(curr[0]);
                    result.push_back(curr[1]);
                }
                else {
                    result.push_back(curr[1]);
                    result.push_back(curr[0]);

                }
                return result;
            }
        }
        else{
            unordered_map<int,vector<int> >::iterator it2 = fMap.find(diff);
            if(it2!=fMap.end()) {
                vector<int> curr = it2->second;
                if(curr[0]>orig[0]) {
                    result.push_back(curr[curr.size()-1]);
                    result.push_back(orig[orig.size()-1]);

                }
                else {
                    result.push_back(orig[orig.size()-1]);
                    result.push_back(curr[curr.size()-1]);

                }
                return result;

            }
        }
    }
    return result;
}


int main() {
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(16);
    int lim = 8;
    vector<int> result = getIndicesOfItemWeights(vec,lim);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
//4:1
//4,[1,2,3]
//6:1
//10:1
//15:1
//16:1
//10
//5:1
//5:0
//4,4
//[4,4,4] 8
//[0,1],[1,2],[0,2]


//lower to higher val
//last el =x, lim -x ,y ..y+x<=lim, y+x>lim,
//