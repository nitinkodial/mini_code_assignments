//replaces spaces of string with %20

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
string replaceSpace(string str) {

    int n = str.length();
    int numOfSpaces = 0;
    int endSpaces = 0;
    bool endSpacesFlag = true;
    for(int i=0; i<n; i++) {
        char  c1 = str.at(i);
        if(c1==' '){
            numOfSpaces++;
        }
        if(str.at(n-i-1)==' '&&endSpacesFlag){
         endSpaces++;   
        }
        else{
            endSpacesFlag = false;
        }
    }
    numOfSpaces = numOfSpaces - endSpaces;
//     cout<<numOfSpaces<<" "<<endSpaces<<endl;
    
    int numOfSpacesExpanded = numOfSpaces * 2;
    for(int i=n-1-endSpaces; i>=0; i--) {
//         cout<<str<<endl;
        char  c1 = str.at(i);
        str[i+numOfSpacesExpanded]=str[i];
        if(c1==' '){
            int index = i+numOfSpacesExpanded-2;
            str[index]='%';
            str[index+1]='2';
            str[index+2]='0';
            numOfSpacesExpanded-=2;
        }
    }
    
    return str;
}

int main() {

    string str = "Mr John Smith    ";
    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<replaceSpace(str)<<endl;
//     printArr(arr,n);

    return 0;

}