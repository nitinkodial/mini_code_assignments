//Check if string has unique characters, with and without additional datastructures

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

//without additional datastructures
bool isStringUnique1(string str) {
    int n = str.length();
    bool flag = true;
    for(int i=0; i<n-1; i++) {
        char  c1 = str.at(i);
        for(int j=i+1; j<n; j++) {
            char  c2 = str.at(j);
//             cout<<c1<<" "<<c2<<endl;
            if(c1==c2) {
                return false;
            }
        }
    }
    return flag;
}

//with additional datastructures,i.e. hashmap
bool isStringUnique2(string str) {
    map<char,int> fMap;

    int n = str.length();
    bool flag = true;
    for(int i=0; i<n; i++) {
        char  c1 = str.at(i);
        map<char,int>::iterator it = fMap.find(c1);
        if(it!=fMap.end()) {
            return false;
        }
        else {
            fMap.insert(make_pair(c1,1));
        }

    }
    return flag;
}

int main() {

    string str = "Helo";
    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<isStringUnique2(str)<<endl;
//     printArr(arr,n);

    return 0;

}