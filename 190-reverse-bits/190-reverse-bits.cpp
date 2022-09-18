class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            //1) left shift the res so as to put the value at right place
            res<<=1;
            //2) Set the bit of res if rightmost bit is set for n
            if(n&1)
                res++;
            //3) Right shift the bit if n since it is already consisdered now
            n>>=1;
        }
        return res;
    }
};