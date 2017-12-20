//Reverse a string
//Given a string, that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), reverse the string in a way that special characters are not affected.

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

bool isAlphabet(char x) {
    if(x>='A'&&x<='Z'||x>='a'&&x<='z')
        return true;
    else
        return false;
}

string reverse_string(string str) {
    int j = str.size()-1;
    for(int i=0; i<str.size(); i++,j--) {
        char f = str.at(i);
        char b = str.at(j);
        while(!isAlphabet(f))
        {
            i++;
            if(i<str.size()) {
                f =str.at(i);
            }
        }
        while(!isAlphabet(b))
        {
            j--;
            if(j>=0) {
                b =str.at(j);
            }
        }
        if(i<=j&&i<str.size()&&j>=0) {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
        else {
            break;
        }
//         cout<<i<<endl;
    }

    return str;
}

int main() {

    string str =  "111t1ec%0h222";
    cout<<reverse_string(str)<<endl;
//     cout<<str<<endl;
    return 0;
}