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

/*//debug this code later
void quickSort(vector<int>& arr,int left, int right){
  if(left>=right){
      cout<<left<<" "<<right<<endl;

      return;
  }
 cout<<"y"<<right-left+1<<" "<<left<<" "<<right<< endl;
  int pivotIndex = rand()%(right-left+1)+left;
  
  int pivot = arr[pivotIndex];
  arr[pivotIndex] = arr[left];
  arr[left] = pivot;
  int leftIndex = left+1;
  int rightIndex = right;
  cout<<"xxx"<<leftIndex<<" "<<rightIndex<<endl;
  printArr(arr);
  while(leftIndex<rightIndex){
   while(leftIndex<rightIndex && arr[leftIndex]<=pivot){
     leftIndex++;   
   }
   while(leftIndex<rightIndex && arr[rightIndex]>=pivot){
     rightIndex--;   
   }
   cout<<"x"<<leftIndex<<" "<<rightIndex<<endl;
   if(leftIndex<rightIndex){
    cout<<"x"<<leftIndex<<" "<<rightIndex<<endl;
    int tmp = arr[leftIndex];
    arr[leftIndex] = arr[rightIndex];
    arr[rightIndex] = tmp;
    leftIndex++;
    rightIndex--;
   }
  }
  if(leftIndex==rightIndex){
   rightIndex--;   
  }
  int tmp = arr[left];
  arr[left] = arr[rightIndex];
  arr[rightIndex] = tmp;

  cout<<left<<" "<<pivotIndex<<" "<<right<<endl;
  printArr(arr);
  quickSort(arr,left,rightIndex-1);
  quickSort(arr,rightIndex+1,right);  
}*/

int partition(vector<int>& arr,int left, int right){
 int pivot = arr[right];
 
 int i = left-1;
 for(int j = left;j<right;j++){
  if(arr[j]<=pivot){
    i++;
    int tmp = arr[j];
    arr[j]  = arr[i];
    arr[i] = tmp;
  }
 }
 int tmp = arr[right];
 arr[right] = arr[i+1];
 arr[i+1] = tmp;
 return i+1;
    
}


void quickSort(vector<int>& arr,int left, int right){
  if(left<right){
        int pivotIndex = partition(arr,left,right);
        quickSort(arr,left,pivotIndex-1);
        quickSort(arr,pivotIndex+1,right);
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
    quickSort(vec,0,vec.size()-1);
    printArr(vec);
    return 0;
}
