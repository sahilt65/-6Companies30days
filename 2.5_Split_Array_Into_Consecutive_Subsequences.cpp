class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> avl;
        map<int, int> vac;

        for(int i = 0; i<nums.size(); i++){
            avl[nums[i]]++;
        }

        for(int i = 0; i<nums.size(); i++){
            if(avl[nums[i]]<=0){
                continue;
            }else if((vac[nums[i]] >0 )){
                avl[nums[i]]--;
                vac[nums[i]]--;
                vac[nums[i] + 1]++;
            }else if(avl[nums[i]]>0 && avl[nums[i] + 1] > 0 && avl[nums[i] + 2] > 0){
                avl[nums[i]]--;
                avl[nums[i]+1]--;
                avl[nums[i]+2]--;
                vac[nums[i] + 3]++;
            }else{
                return false;
            }
        }

        return true;
    }
};