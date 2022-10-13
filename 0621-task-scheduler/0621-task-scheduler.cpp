class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;      //{job_left}
        queue<pair<int,int>> q;      //{job_left,Job_available_to_be_processed}
        vector<int> freq(26,0);
        int totalTime=0;
        // Getting the frequencies of all the tasks
        for(char task:tasks){
            freq[task-'A']++;
        }
        // Pushing them in prioirity queue so as to maintain the order of high freq job on top 
        for(int f:freq){
            if(f>0)
                pq.push(f);
        }
        while(!pq.empty() || !q.empty()){
            totalTime++;
            if(!pq.empty()){
                // Doing the high prio job for 1 unit of time
                int cnt = pq.top()-1;
                pq.pop();
                // If task still needs to be processed then saving it in queue
                if (cnt){
                    int timeToPick = totalTime+n;
                    q.push({cnt,timeToPick});
                }
            }
            // If jobs are there in queue to be processed and at that time we can pick any job from queue
            if(!q.empty() && q.front().second == totalTime){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return totalTime;
    }
};