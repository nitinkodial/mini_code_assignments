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
string compressString(string str) {
    bool flag = true;

    int n = str.length();
    string str2(2*n,' ');
    int j = 0 ;
    int freq = 1;
    char c_prev = str.at(j);
    for(int i=1 ; i<n; i++ ) {

        char c_curr = str.at(i);
        if(c_prev==c_curr) {
            freq++;
        }
        else {

            str2[j] = c_prev;
            j++;
            string freqStr = NumberToString(freq);
            str2.replace(j,freqStr.length(),freqStr);
            j=j+freqStr.length();
            c_prev=c_curr;
            freq = 1;
        }

    }
    //for last char
    str2[j] = c_prev;
    j++;
    string freqStr = NumberToString(freq);
    str2.replace(j,freqStr.length(),freqStr);
    j=j+freqStr.length();
    
    cout<<str2<<" "<<j<<endl;
    if(j>=n) {
        return str;
    }
    else {
        
        return str2.substr(0,j);
    }

    return str;
}

int main() {

    string str1 = "aabcccccaaa";

    string str2 = "abbb";

    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<compressString(str2)<<endl;
//     printArr(arr,n);

    return 0;

}