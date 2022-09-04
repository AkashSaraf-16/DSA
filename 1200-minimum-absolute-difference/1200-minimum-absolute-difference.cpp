class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());        
        int diff = arr[1] - arr[0];
                temp.push_back(arr[0]);
                temp.push_back(arr[1]);
                ans.push_back(temp);
        for(int i = 1 ; i < arr.size() - 1 ; i++){
            if(arr[i+1] - arr[i] == diff){
                temp.clear();
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);     
                ans.push_back(temp);             
            }
            else if(arr[i+1] - arr[i] < diff){
                diff = arr[i+1] - arr[i];
                temp.clear();
                ans.clear();
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);     
                ans.push_back(temp);             
            }
        }
        return ans;
    }
};