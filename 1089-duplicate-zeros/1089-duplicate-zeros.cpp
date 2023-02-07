class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return;
        // int i = 0, j = 1;
        for(int i = 0 ; i < n-1 ;i++){
            if(arr[i] == 0){
                int t = arr[i+1];
                int j = i+2;
                // Overriding arr after i+1 with shifted value i.,e right shifting values
                while(j<n){
                    swap(arr[j],t);
                    j++;
                }
                arr[i+1] = 0 ;
                i++;
            }
        }
        // for(int i = 0 ; i< arr.size() ; i++){
        //     if(arr[i] == -1)
        //         arr[i] =0;
        // }
        
    }
};