class Solution {
public:
    bool isValid(string s) {
        int i=-1;// top
        for(int j=0;j<s.length();j++){
            if(i==-1 || !pairParenthesis(s[i],s[j])){
                i++;
                s[i]=s[j];
            }   
            else{
                i--;   
            }
        }
        return i==-1;
    }
    bool pairParenthesis(char a,char b){
        if((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'))
            return true;
        return false;
    }
};