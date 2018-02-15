// Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
// 
// The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
// 
// Example 1:
// Input: "UD"
// Output: true
// Example 2:
// Input: "LL"
// Output: false

class Solution {
public:
    bool judgeCircle(string moves) {
        int hor = 0,ver = 0;
        for(int i = 0; i<moves.size();i++){
            if(moves.at(i)=='L'){
             hor--;   
            }
            else if(moves.at(i)=='R'){
                hor++;
            }
            else if(moves.at(i)=='U'){
                ver++;
            }
            else if(moves.at(i)=='D'){
                ver--;
            }
        }
        if(ver==0&&hor==0)
            return true;
        else
            return false;
    }
};