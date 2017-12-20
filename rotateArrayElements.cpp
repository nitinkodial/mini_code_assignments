#include<iostream>

using namespace std;


void printArr(int arr[],int n);

//Use 1 tmp variable only
void rotateArrElements1(int arr[],int d,int n){
 for (int i=0;i<d;i++){
     int tmp = arr[0];
     for (int j=0;j<n-1;j++){
        arr[j]=arr[j+1];
     }
     arr[n-1]=tmp;
 }
}

//Use 1 tmp array only
void rotateArrElements2(int arr[],int d,int n){
 int* tmp =  new int[d];
 copy(arr,arr+d,tmp);
 printArr(tmp,d);
 for (int i=0,j=d;j<n;j++,i++){
        arr[i]=arr[j];
 }
 copy(tmp,tmp+d,arr+n-d);
 
 delete [] tmp;
}

void printArr(int arr[],int n){
 for (int i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
}
int main(){
    
 int arr[] = {1, 2, 3, 4, 5, 6, 7};
 int d = 2, n =7;   
 printArr(arr,n);
 bool useMethod1 = false;
 if(useMethod1){
  rotateArrElements1(arr,d,n);
 }
 else{
  rotateArrElements2(arr,d,n);
 }
 printArr(arr,n);
 
 return 0;
    
}