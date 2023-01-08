/*
Link to the Questions : 
https://leetcode.com/problems/number-of-boomerangs/submissions/
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int total = 0;
        for(int i = 0; i<points.size(); i++){
            unordered_map<int, int> m;
            for(int j = 0; j<points.size(); j++){
                int dist = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);

                m[dist]++;
            }
            for(auto i : m){
                if(i.second>1){
                    total= total + (i.second *(i.second-1));
                }
            }
        }

        return total;
    }
};