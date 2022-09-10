class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX , moves = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            mn = min(mn,nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            moves+= nums[i]-mn;
        }
        return moves;
    }
};