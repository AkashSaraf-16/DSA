class Solution {
public:
    bool isPair(char a,char b){
        if((a == '(' && b ==')') ||(a == '{' && b =='}') || (a == '[' && b ==']'))
            return true;
        return false;
    }
    bool isValid(string s) {
        int top=-1;
        for(int i=0;i<s.length();i++){
            if(top<0 || !isPair(s[top],s[i])){
                // think this in a way like when the 2 consecutive brackets are not pair we simply push the current char in stack
                top++;
                s[top]=s[i];
            }
            else
                top--;
        }
        return top==-1;
    }
};