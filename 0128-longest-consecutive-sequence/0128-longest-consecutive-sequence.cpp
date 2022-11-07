class Solution {
    public:
    // TC:O(n)  SC:O(n)
    int longestConsecutive(vector<int> nums) {
        unordered_set<int> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            // picking only the minimum element from continuous increasing sequences
            // Eg: [100,101,102,1,3,103] will pick only 100 , 1 ,3
            if (!num_set.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};