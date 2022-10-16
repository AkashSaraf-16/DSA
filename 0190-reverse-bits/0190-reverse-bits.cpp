class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //TC:O(32) SC:O(1)
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
        /*
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;*/
    }
};