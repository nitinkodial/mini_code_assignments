// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.*/

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int array[] = {-1	, -5,-10,-50,-100,-500,-1000};
        map<char,int> myMap;
        
        myMap.insert(make_pair('I',1));
        myMap.insert(make_pair('V',5));
        myMap.insert(make_pair('X',10));
        myMap.insert(make_pair('L',50));
        myMap.insert(make_pair('C',100));
        myMap.insert(make_pair('D',500));
        myMap.insert(make_pair('M',1000));
        
        for(int i=0;i<s.length();i++){
            //Symbol	I	V	X	L	C	D	M
            //Value	    1	5	10	50	100	500	1,000
            int currNum = 0;
            char curr = s.at(i);
            if(curr == 'M'){
                currNum = 1000;
            }
            else if(curr == 'D'){
                currNum = 500;
            }
            else if(curr == 'C'){
                currNum = 100;
            }
            else if(curr == 'L'){
                currNum = 50;
            }
            else if(curr == 'X'){
                currNum = 10;
            }
            else if(curr == 'V'){
                currNum = 5;
            }
            else if(curr == 'I'){
                currNum = 1;
            }
            if(i<s.length()-1){
                map<char,int>::iterator it = myMap.find(s.at(i+1));
                if(it->second>currNum){
                    currNum = -1*currNum;
                }
            }
            result +=currNum;
            cout<<result<<" "<<curr<<endl;
        }
        return result;
        
    }
};