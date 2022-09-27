class Solution {
public:
    int len=0;
    void helper(vector<int>& arr,int prev ,int curr, bool incTrend , int l){
        len=max(len,l);
        
        if(curr==arr.size())
            return;
        
        if(incTrend==true && arr[prev]<arr[curr])         // if we want inc trend and it satifies
            helper(arr,curr,curr+1,!incTrend,l+1);
        else if(incTrend==false && arr[prev]>arr[curr])   // if we want dec trend and it satifies
            helper(arr,curr,curr+1,!incTrend,l+1);
        else{                                       // this can be due to two reasons
            //1 when both the curr n the prev are equal
            if(arr[curr]==arr[prev])
                helper(arr,curr,curr+1,incTrend,1);
                // helper(arr,curr,curr+1,!incTrend,1);   //we can do this also
            //2 If we get two consecutive inc or dec elements
            else
            // eg: 2,4,6,1 ... here when curr=4 we wanted dip but we get 6 so we will reset our 
            // series as 4,6 hence l=2 and since still we want dip int incTrend still holds
                helper(arr,curr,curr+1,incTrend,2);
        }
    }
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1)
            return 1;
        bool incTrend=true;
        helper(arr,0,1,incTrend,1);
        helper(arr,0,1,!incTrend,1);
        return len;
    }
};