//merge sort implementation
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printArr(vector<int>& arr){
    
    int n = arr.size();
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>& arr,int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    
    vector<int> leftArr(n1,0);
    vector<int> rightArr(n2,0);
    
    for(i = 0;i<n1;i++){
      leftArr[i] = arr[l+i];   
    }
    for(j = 0;j<n2;j++){
      rightArr[j] = arr[m+1+j];   
    }
    
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
     if(leftArr[i]<=rightArr[j]){
      arr[k]=leftArr[i];
      i++;
     }
     else{
      arr[k]=rightArr[j];
      j++;   
     }
     k++;
        
    }
    while(i<n1){
      arr[k]=leftArr[i];
      i++;
      k++;
    }
    while(j<n2){
      arr[k]=rightArr[j];
      j++;
      k++;
    }
    
}

void mergeSort(vector<int>& arr,int l, int r){
  if(l<r){
//     printArr(arr);  
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
    
}



int main() {
    vector<int> vec;
    vec.push_back(12);
    vec.push_back(11);
    vec.push_back(13);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    
    printArr(vec);
    mergeSort(vec,0,vec.size()-1);
    printArr(vec);
    return 0;
}
