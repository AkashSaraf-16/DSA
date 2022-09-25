class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0 , r = arr.size()-1;
        while(l<=r){
            int mid = (r-l)/2 + l;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(arr[mid] > arr[prev] && arr[mid] > arr[next]){
                return mid;
            }
            else if(arr[mid] < arr[prev])
                r = mid;
            else
                l = mid;
        }
        return -1;
    }
};