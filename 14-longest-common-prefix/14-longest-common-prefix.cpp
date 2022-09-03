class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lca = strs[0];
        for(int i = 1 ; i < strs.size() ; i++){
            while(strs[i].find(lca) != 0){
                lca = lca.substr(0,lca.size()-1);
                if(lca == "")
                    break;
            }
        }
        return lca;
    }
};