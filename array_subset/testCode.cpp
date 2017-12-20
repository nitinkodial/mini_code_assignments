//check if 1 array is subset (non contiguous) of another array 
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int isSubset(int* arr1,int m, int* arr2, int n) {
    map<int,int> mp;
    for(int i=0; i<m; i++) {
        map<int,int>::iterator it  = mp.find(arr1[i]);

        if(it!=mp.end())
        {   
            it->second=it->second+1;
        }
        else {
//             cout<<arr1[i]<<" "<<endl;
            mp.insert(make_pair(arr1[i],1));
        }

    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
//       cout<<"x"<<it->first<<" "<<it->second<<endl;   
    }
    for(int i=0; i<n; i++) {
        map<int,int>::iterator it  = mp.find(arr2[i]);
        if(it!=mp.end()) {
//             cout<<it->first<<" "<<it->second<<endl;
            if(it->second>0) {
                it->second = it->second-1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr1[] =  {11, 1, 13, 21, 3,3, 7};
    int arr2[] =  {11, 3, 3,7, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);

    int n = sizeof(arr2)/sizeof(arr2[0]);
//  cout<<m<<n<<endl;
    int result = isSubset(arr1,m,arr2,n);

    if(result==1)
        cout<<"arr2 is subset of arr1\n";
    else
        cout<<"arr2 is not subset of arr1\n";

    return 0;
}