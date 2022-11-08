class Solution {
public:
    void helper(int open ,int close ,vector<string> &res ,string &str){
        if(open == 0 && close == 0){
            res.push_back(str);
        }
        if(open){
            string a= str+"(";
            helper(open-1,close,res,a);
        }
        if(open<close)
        {
            string b=str+")";
            helper(open,close-1,res,b);
        }    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        helper(n,n,res,str);
        return res;
    }
};