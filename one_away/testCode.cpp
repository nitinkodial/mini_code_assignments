//Check if string1 is one or zero edits away from string2, in terms of edits being replace,insert,remove
#include<iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

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
bool checkForEdits(string str1,string str2) {
    if(abs(str1.length()-str2.length())>1) {
        return false;
    }
    bool flag = true;

    int n1 = str1.length();
    int n2 = str2.length();
    int numOfEdits = 0;

    for(int i=0, j=0; i<n1,j<n2; ) {
        if(str1.at(i)!=str2.at(j)) {
            numOfEdits++;
            if((numOfEdits)>1){
                return false;
            }
            if(n1>n2) {
                i++;
            }
            else if(n1<n2) {
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        else {
            i++;
            j++;
        }
    }

    return flag;
}

int main() {

    string str1 = "pale";

    string str2 = "bake";

    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<checkForEdits(str1,str2)<<endl;
//     printArr(arr,n);

    return 0;

}