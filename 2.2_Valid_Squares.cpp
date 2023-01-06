/*
Link to the Question:
https://leetcode.com/problems/valid-square/
*/

class Solution {
public:
    double squareDistanceBetweenTwoPoint(vector<int> p1, vector<int> p2){
        return ((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if((p1[0]==p2[0] && p1[1]==p2[1]) || (p1[0]==p3[0] && p1[1]==p3[1]) || (p1[0]==p4[0] && p1[1]==p4[1])||
        (p2[0]==p3[0] && p2[1]==p3[1]) || (p2[0]==p4[0] && p2[1]==p4[1]) || (p3[0]==p4[0] && p3[1]==p4[1])){
            return false;
        }
        int dist12 = squareDistanceBetweenTwoPoint(p1,p2);
        int dist13 = squareDistanceBetweenTwoPoint(p1,p3);
        int dist14 = squareDistanceBetweenTwoPoint(p1,p4);

        if((dist12 == dist13) && 2*dist12==dist14){
            int dist = squareDistanceBetweenTwoPoint(p2,p4);
            return (dist==squareDistanceBetweenTwoPoint(p3,p4) && dist == dist13);
        }

        if((dist12 == dist14) && 2*dist12==dist13){
            int dist = squareDistanceBetweenTwoPoint(p2,p3);
            return (dist==squareDistanceBetweenTwoPoint(p4,p3) && dist == dist12);
        }

        if((dist13 == dist14) && 2*dist13==dist12){
            int dist = squareDistanceBetweenTwoPoint(p2,p3);
            return (dist==squareDistanceBetweenTwoPoint(p4,p2) && dist == dist13);
        }
        return false;
    }
};