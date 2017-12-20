//Check if string is permuation of another string
//Ideal method is to check if max of one character has odd count. (Slightly less optimized version implemented below though).
#include<iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


void printArr(int arr[],int n);


void printArr(int arr[],int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printMap(map<int,int> myMap) {
    for(map<int,int>::iterator it = myMap.begin(); it!=myMap.end(); it++) {
        cout<<"key: "<<it->first<<" , value: "<<it->second<<endl;
    }

}


//with additional datastructures,i.e. hashmap
bool checkForPermutation(string str1,string str2) {
    if(str1.length()!=str2.length()) {
        return false;
    }
    map<char,int> fMap;

    int n = str1.length();
    for(int i=0; i<n; i++) {
        char  c1 = str1.at(i);
        map<char,int>::iterator it = fMap.find(c1);
        if(it!=fMap.end()) {
            fMap.insert(make_pair(c1,it->second+1));
        }
        else {
            fMap.insert(make_pair(c1,1));
        }

    }
    bool flag = true;
    n = str2.length();
    for(int i=0; i<n; i++) {
        char  c1 = str2.at(i);
        map<char,int>::iterator it = fMap.find(c1);
        if(it!=fMap.end()) {
            
        }
        else {
            return false;
        }
    }

    return flag;
}

int main() {

    string str1 = "Hello";

    string str2 = "leHxo";

    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<checkForPermutation(str1,str2)<<endl;
//     printArr(arr,n);

    return 0;

}