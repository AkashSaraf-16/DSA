class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0 , n = arr.size() , h = n-1;
        while(l<=h){
            int mid = (h-l)/2 + l;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            
            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])  // checking min. element
                return arr[mid];
            else if(arr[mid]<=arr[h])       // if right side of array is sorted 
                h=mid-1;                    // then min exist in left(usorted part)
            else if(arr[mid]>=arr[l])       // if left side of array is sorted 
                l=mid+1;                    // then min exist in right(usorted part)
        }
        return arr[0];
    }
};