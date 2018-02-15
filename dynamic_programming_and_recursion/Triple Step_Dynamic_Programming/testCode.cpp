// Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
// steps at a time. Implement a method to count how many possible ways the child can run up the
// stairs.
#include <iostream>

using namespace std;

int numOfWays(int n){
    int a1 = 1,a2=2,a3=4;
    if(n==1){
        return a1;
    }
    else if(n==2){
        return a2;
    }
    else if(n==3){
        return a2;
    }
    else if(n<=0){
        return 0;
    }
    else{
    int sum = 0;
      for(int i=3;i<n;i++){
       sum = a3+a2+a1;
       a1 = a2;
       a2 = a3;
       a3 = sum;
      }
      return sum;
    }
}

int main(){
 int n = 5;
 cout<<numOfWays(n)<<endl;
}