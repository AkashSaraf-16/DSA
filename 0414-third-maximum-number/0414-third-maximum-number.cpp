class Solution {
public:
    // One of a pattern 
    int thirdMax(vector<int>& nums) {
    long a, b, c;
    a = b = c = LONG_MIN;
    for (auto num : nums) {
        if (num <= c || num == b || num == a) continue;
        c = num;
        if (c > b) swap(b, c);
        if (b > a) swap(a, b);
    }
    return c == LONG_MIN ? a : c;
}
};