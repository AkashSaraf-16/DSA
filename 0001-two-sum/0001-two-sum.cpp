class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) && map[complement] != i) {
                return { i, map[complement] };
            }
        }
        // In case there is no solution, we'll just return an empty vector
        return {};
    }
};