// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to O.

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
void zeroMatrix(vector<vector<int> >& matrix,int width,int height) {

    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    
    for(int i=0;i<height;i++){
        if(matrix[i][0]==0){
            for(int j=0;j<width;j++)
                matrix[i][j]=0;
        }
    }
    for(int j=0;j<width;j++){
         if(matrix[0][j]==0){
            for(int i=0;i<height;i++)
                matrix[i][j]=0;
        }
    }


}

int main() {

    int width = 10;
    int height = 10;
    vector<vector<int> >matrix(height,vector<int>(width));

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            matrix[i][j]=1;//(width*i+j+1);
        }
    }
    matrix[3][2]=0;
    matrix[7][5]=0;
    cout<<"0"<<endl;
    printMatrix(matrix,width,height);
    
    cout<<endl;
    zeroMatrix(matrix,width,height);

    printMatrix(matrix,width,height);

    return 0;

}