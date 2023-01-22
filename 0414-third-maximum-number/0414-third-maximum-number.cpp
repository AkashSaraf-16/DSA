class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        unordered_set<int> st;
        for(int num:nums){
            // If we have already taken the element
            if(st.count(num))
                continue;
            if(minHeap.size()==3){
                if(minHeap.top()<num){
                    st.erase(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                    st.insert(num);
                }
            }
            else{
                st.insert(num);
                minHeap.push(num);
            }
        }
        if(minHeap.size()==1)
            return minHeap.top();
        else if(minHeap.size()==2){
            int f=minHeap.top();
            minHeap.pop();
            return max(f,minHeap.top());
        }
        return minHeap.top();
    }
};