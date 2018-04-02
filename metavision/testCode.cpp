// print n th element of series, a1,a2,a3...an, given a1,a2,n

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a1, a2, n;
    cin >> a1 >> a2 >> n;

    int answer = 0;
    if(n==1){
      cout<<a1<<endl;
      return a1;
    }
    else if(n==2){
      cout<<a2<<endl;
      return (a2);
    }
    // Add your code here.
    // You can use the window on the right top
    // to pass in your own input for testing
    // (clear it before submitting).

    vector<int> vec(n,0);
    vec[0] = a1;
    vec[1] = a2;

    for(int i = 2;i<n;i++){
        vec[i] = vec[i-1] + vec[i-2];
    }
    answer = vec[n-1];
    // Your code is evaluated by the output in stdout.
    // If you leave any debug messages when submitting,
    // your code will likely fail.

    cout << answer;

    // You'll see the result for the first test case,
    // but your code is run against many other inputs,
    // and they are all scored separately.

    return answer;
}

