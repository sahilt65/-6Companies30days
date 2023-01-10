class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int arr[1000001] = {-1};
        int ans = INT_MAX;
        int count = 0;
        for(int i = 0; i<1000001; i++){
            arr[i] = -1;
        }

        for(int i = 0; i<cards.size(); i++){
            if(arr[cards[i]] != -1){
                int temp = i - arr[cards[i]] + 1;
                if( (i - arr[cards[i]] + 1)<ans){
                    ans =  i - arr[cards[i]] + 1;
                    count++;
                }
                arr[cards[i]]=i;
            }else{
                arr[cards[i]] = i;
            }
        }
        if(count == 0){
            return -1;
        }
        return ans;
    }


};