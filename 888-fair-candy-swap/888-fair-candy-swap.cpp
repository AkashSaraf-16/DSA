class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alicesum = 0, bobsum = 0;
        sort(aliceSizes.begin() , aliceSizes.end());
        sort(bobSizes.begin() , bobSizes.end());
        vector<int> ans;
        for(int it:aliceSizes)
            alicesum += it;
        int talicesum = alicesum;
        for(int it:bobSizes)
            bobsum += it;  
        int tbobsum = bobsum;
        int i=0 , j=0;
        while( i<aliceSizes.size() && j<bobSizes.size() ){      // two pointer
                alicesum = alicesum - aliceSizes[i];
                bobsum = bobsum - bobSizes[j];
                alicesum = alicesum + bobSizes[j];
                bobsum = bobsum + aliceSizes[i];
                if(alicesum == bobsum){
                   ans.push_back(aliceSizes[i]) ;
                   ans.push_back(bobSizes[j]) ;
                   return ans;
                }
                else if(alicesum > bobsum) i++;     // we need to remove larger no. then
                else j++;
                bobsum = tbobsum;
                alicesum = talicesum;
        }
        return ans;
        
    }
};