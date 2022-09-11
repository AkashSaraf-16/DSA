class Solution {
public:
    // T.C:O(n*n*Logk) S.C:O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq; // we are interested only minimum elements
        int col = matrix[0].size() , row = matrix.size();
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            } 
        }
        return pq.top();
    }
};