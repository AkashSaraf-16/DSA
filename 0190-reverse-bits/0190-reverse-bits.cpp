class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            // left shifting it because in the next itertaion we have to consider the next bit
            res<<=1;
            if(n&1)
                res++;
            n>>=1;
        }
        return res;
    }
};