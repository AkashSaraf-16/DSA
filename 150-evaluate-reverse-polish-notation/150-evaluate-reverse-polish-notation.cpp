class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> result;
    int a,b;
    for(int i = 0 ; i<tokens.size() ; i++){
        if(tokens[i] == "+"){
            a = result.top();
            result.pop();
            b = result.top();
            result.pop();
            result.push(a+b);
            
        }else if (tokens[i] == "-"){
            a = result.top();
            result.pop();
            b = result.top();
            result.pop();
            result.push(b-a);
            
        }else if (tokens[i] == "*"){
            a = result.top();
            result.pop();
            b = result.top();
            result.pop();
            result.push(a*b);
            
        }else if (tokens[i] == "/"){
            a = result.top();
            result.pop();
            b = result.top();
            result.pop();
            result.push(b/a);
            
        }else{
            result.push(atoi(tokens[i].c_str()));
            
        }
    }
        
        return result.top(); 
    }
};