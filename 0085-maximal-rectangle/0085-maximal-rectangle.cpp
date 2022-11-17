class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int oneD[n];            
        
        vector<vector<int>> matrix2(m,vector<int>(n));
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                matrix2[i][j] = matrix[i][j] - '0';     // convert char i/p -> int
            
        for(int i = 0 ; i<n ; i++)
            oneD[i] = matrix2[0][i];                    // convert 2D matrix -> 1D array
        
        int ans = MHA(oneD,n);                          // and applpying Max area of rectangle
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                oneD[j] = matrix2[i][j]==0?0:oneD[j]+1;  // adding in the height of previous height 
            }
            ans = max(ans,MHA(oneD,n));                 // max of the previous and this 1D area
        }
        return ans;
    }
    
    int MHA(int v[], int n){
        stack<pair<int,int>> NSL,NSR;           //NSL: next smallest left NSR: next smallest right
        int left[n], right[n];
        
        for(int i = 0 ; i < n ; i++){           // filling the left[]
            while(!NSL.empty() && NSL.top().first >= v[i])
                NSL.pop();
            if(NSL.empty())
                left[i] = -1;
            else
                left[i] = NSL.top().second;
            
            NSL.push({v[i], i});
        }
        
        for(int i = n-1 ; i >= 0 ; i--){        // filling the right[]
            while(!NSR.empty() && NSR.top().first >= v[i])
                NSR.pop();
            if(NSR.empty())
                right[i] = n;
            else
                right[i] = NSR.top().second;
            
            NSR.push({v[i], i});
        }
        
        for(int i = 0 ; i < n ; i++)            // calculating width
            left[i] = right[i] - left[i] - 1;
        
        int maxArea = INT_MIN;
        for(int i = 0 ; i < n ; i++)            // calculating the area
            maxArea = max(maxArea,left[i]*v[i]);
        
        return maxArea;
        
    }
};