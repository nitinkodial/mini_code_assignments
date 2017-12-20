//Reverse a string using recursion

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

void reverse_string(string str){
    if(str.size()==0){
        return;
    }
    reverse_string(str.substr(1));
    cout<<str.at(0);//<<endl;
//     cout<<" "<<str.size()<<" "<<str<<endl;
    return;
}

int main() {

    string str =  "tech";
    reverse_string(str);
    cout<<endl;
    return 0;
}