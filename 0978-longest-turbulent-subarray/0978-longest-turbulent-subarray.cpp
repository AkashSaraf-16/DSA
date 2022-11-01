class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int incsofar = 1;
        int decsofar = 1;
        int res = 1;
        for(int i = 1; i < arr.size() ; i++){
            if(arr[i-1]<arr[i]){        // if we encounter prev element lesser than current
                decsofar = incsofar + 1;          // adding 1 in running length 
                incsofar = 1;                // setting this becoz in next iteration greter no. ???
            }
            else if(arr[i-1]>arr[i]){   // if we encounter prev element greater than current
                incsofar = decsofar + 1;          
                decsofar = 1;
            }
            else{
                incsofar = 1;
                decsofar = 1;
            }
            res = max(res,max(incsofar,decsofar));
        }
        return res;
    }
};