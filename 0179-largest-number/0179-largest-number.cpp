bool cmp(string a,string b){
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i=0;i<nums.size();i++)
            str.push_back(to_string(nums[i]));
        sort(str.begin(),str.end(),cmp);
        string res;
        for(int i=0;i<str.size();i++)
            res+=str[i];
        return res[0]=='0'?"0":res;
    }
};