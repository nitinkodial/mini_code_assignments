//Compress string as follows aabcccccaaa as a2b1c5a3. Only letters in input string.
#include<iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;



template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

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
bool isRotateString(string str1,string str2) {
    bool flag = true;

//     int n = str.length();
    string str3 = str2+str2;
    
    if (str3.find(str1) != std::string::npos) {
        return true;
    }
    
    return false;
}

int main() {

    string str1 = "waterbottle";

    string str2 = "erbottlewat";

    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<isRotateString(str1,str2)<<endl;
//     printArr(arr,n);

    return 0;

}