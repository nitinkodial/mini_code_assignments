//find mode of array, and if mode appears more than half the size of array, return mode, or else return -1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    // You still need to read in the rest of the input.

    int answer = -1;
//     vector<int> vec(n,0);
//     for(int i=0;i<n;i++){
//         int curr=0;
//         cin >> curr;
//         vec[i] =curr;
//         cout<<vec[i]<<endl;
//     }

    unordered_map<int,int> mymap;
    int min = 0;
    int mode = 0;
    for(int i=0;i<n;i++){
      int curr=0;
      cin >> curr;

      unordered_map<int,int>::iterator it = mymap.find(curr);
      if(it!=mymap.end()){
        it->second =it->second+1;
        if(it->second>min){
          min = it->second;
          mode = curr;
        }
      }
      else{
        if(min==0){
          min = 1;
          mode = curr;
        }
        mymap.insert(make_pair(curr,1));
      }
    }
    if(min>n/2){
      answer = mode;
      //cout<<mode<<endl;
    }
    else{
      answer = -1;
      //cout<<-1<<endl;
    }

    // Add your code here.
    // You can use the window on the right top
    // to pass in your own input for testing
    // (clear it before submitting).

    // Your code is evaluated by the output in stdout.
    // If you leave any debug messages when submitting,
    // your code will likely fail.

    cout << answer;

    // You'll see the result for the first test case,
    // but your code is run against many other inputs,
    // and they are all scored separately.

    return 0;
}

*/

/*
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main(){
    cout<<"nitin"<<endl;
    return 0;
}
*/
/*
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
//1
//2
//3
//
*/
/*
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    // You still need to read in the rest of the input.

    int answer = -1;
//     vector<int> vec(n,0);
//     for(int i=0;i<n;i++){
//         int curr=0;
//         cin >> curr;
//         vec[i] =curr;
//         cout<<vec[i]<<endl;
//     }

    unordered_map<int,int> mymap;
    int min = 0;
    int mode = 0;
    for(int i=0;i<n;i++){
      int curr=0;
      cin >> curr;

      unordered_map<int,int>::iterator it = mymap.find(curr);
      if(it!=mymap.end()){
        it->second =it->second+1;
        if(it->second>min){
          min = it->second;
          mode = curr;
        }
      }
      else{
        if(min==0){
          min = 1;
          mode = curr;
        }
        mymap.insert(make_pair(curr,1));
      }
    }
    if(min>n/2){
      answer = mode;
      //cout<<mode<<endl;
    }
    else{
      answer = -1;
      //cout<<-1<<endl;
    }

    // Add your code here.
    // You can use the window on the right top
    // to pass in your own input for testing
    // (clear it before submitting).

    // Your code is evaluated by the output in stdout.
    // If you leave any debug messages when submitting,
    // your code will likely fail.

    cout << answer;

    // You'll see the result for the first test case,
    // but your code is run against many other inputs,
    // and they are all scored separately.

    return 0;
}
*/



#include <iostream>
#include <cmath>       /* ceil */

using namespace std;

int pilesplit(int n,int m,int p){
  //cout<<endl;
  if(n<=m){
    return 1;
  }
  int curr1 = ceil(n/(p*1.0));
  int k = ceil(n/(curr1*1.0));
  //cout<<"a "<<n<< " "<<m<< " "<<p<< " "<<k<<",curr1 "<<curr1<<endl;
  //cout<<"x"<<curr1<<endl;
  int sum = 0;
  int p1 = 0;
  for(int i = 0;i<k;i++){
    sum = sum+curr1;
    int curr2 = curr1;
    if(i==k-1){
      curr2 = curr1-(sum-n);
    }
    //cout<<"b "<<curr2<<" "<<sum<<" "<<n<<endl;
    p1 = p1 + pilesplit(curr2,m,p);
    //p1++;
    //cout<<"c "<<sum<<endl;
  }
  //cout<<"p1 "<<p1<<" "<<n<<endl;
  //cout<<endl;
  return p1;
}

int main() {
    int n, m, p;
//    cin >> n >> m >> p;
    n = 11;
    m = 3;
    p = 3;
    int answer = -1;

    // Add your code here.
    // You can use the window on the right top
    // to pass in your own input for testing
    // (clear it before submitting).

    // Your code is evaluated by the output in stdout.
    // If you leave any debug messages when submitting,
    // your code will likely fail.
    if(n==m){
      cout<<1<<endl;
      return 0;
    }
    if(n>m){
      answer = pilesplit(n,m,p);
      cout<<answer;
    }
//     cout << answer;

    // You'll see the result for the first test case,
    // but your code is run against many other inputs,
    // and they are all scored separately.

    return 0;
}
