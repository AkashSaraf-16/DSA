class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0 ; i < arr.size()-2  ; i++ ){
            if(arr.size() < 3) return false;
            if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i+2]%2==1){
                return true;
            }
        }
        return false;
    }
};