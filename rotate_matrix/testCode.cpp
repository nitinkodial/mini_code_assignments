//Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. (an you do this in place?

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

void printMatrix(vector<vector<int> >& matrix,int width,int height) {

    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}


//with additional datastructures,i.e. hashmap
void rotateMatrix(vector<vector<int> >& matrix,int width,int height) {
    cout<<"1"<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width-i;j++){
//             cout<<i<<" "<<j<<" "<<j<<" "<<width-1-i<<endl;
            int temp = matrix[i][j];
            matrix[i][j]=matrix[height-1-j][width-1-i];
            matrix[height-1-j][width-1-i] = temp;
        }
    }
    
    for(int i=0;i<height/2;i++){
        for(int j=0;j<width;j++){
//             cout<<i<<" "<<j<<" "<<j<<" "<<width-1-i<<endl;
            int temp = matrix[i][j];
            matrix[i][j]=matrix[height-1-i][j];
            matrix[height-1-i][j] = temp;
        }
    }

//     printMatrix(matrix,width,height);
//     cout<<endl;

}

int main() {

    int width = 5;
    int height = 5;
    vector<vector<int> >matrix(height,vector<int>(width));

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            matrix[i][j]=(width*i+j+1);
        }
    }
    cout<<"0"<<endl;
    printMatrix(matrix,width,height);
    
    cout<<endl;
    rotateMatrix(matrix,width,height);

    printMatrix(matrix,width,height);

    return 0;

}