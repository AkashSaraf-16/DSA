class Solution {
public:
    bool isValid(string s) {
        int top=-1,i=0;
        while(i<s.length()){
            if(top==-1|| !pairParentheses(s[top],s[i])){
                top++;
                s[top]=s[i];
            }else{
                top--;
            }
            ++i;
        }
        return top==-1?true:false;
    }
    
    bool pairParentheses(char a,char b){
        if((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'))
            return true;
        return false;
    }
};