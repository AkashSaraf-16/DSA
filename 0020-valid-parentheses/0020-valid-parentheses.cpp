class Solution {
public:
    bool isValid(string s) {
        int top=-1;
        for(int curr=0;curr<s.size();curr++){
            if(top<0 || !isComplementery(s[top],s[curr])){
                top++;
                s[top]=s[curr];
            }
            else
                top--;
        }
        return top==-1;
    }
    bool isComplementery(char a, char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
            return true;
        return false;
    }
};