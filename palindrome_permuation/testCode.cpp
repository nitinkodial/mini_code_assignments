//check if permuatation of string can be made into a palindrome

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
bool permuatationPalindrome(string str) {

    bool flag = true;
    int n = str.length();
    int numOfSpaces = 0;
    map<char,int> fmap;
    for(int i=0; i<n; i++) {
        char  c1 = str.at(i);
        if(c1==' '){
            numOfSpaces++;
            continue;
        }
        map<char,int>::iterator it = fmap.find(c1);
        if(it!=fmap.end()) {
            it->second = it->second+1;
            cout<<c1<<" "<<it->second+1<<endl;
        }
        else {
            fmap.insert(make_pair(c1,1));
        }
    }
    int numOfOddFreqChars = 0;
    int limitOfOddChars = ((n-numOfSpaces)%2);
    for(map<char,int>::iterator it = fmap.begin(); it!=fmap.end(); it++) {
        
        if(it->second%2==1){
            numOfOddFreqChars++;
        }
        cout<<numOfOddFreqChars<<" "<<it->first<<" "<<it->second<<endl;
        if(numOfOddFreqChars>limitOfOddChars){
            return false;
        }
    }
    return flag;
}

int main() {

    string str = "tact ca";
    //output  = [1,3,4,6,2,2,5,5,8,8,8]
    cout<<permuatationPalindrome(str)<<endl;
//     printArr(arr,n);

    return 0;

}