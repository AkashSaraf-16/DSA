class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n ==1 && k == 1){        //base condition 1st row 1 column
            return 0;
        }
        
        int l;                      // Induction : getting the index which will determine the value of present index
        if(k%2){
             l = (k/2)+1;
        }
        else
             l = k/2;
        
        int parent = kthGrammar(n-1,l);     // Hypothesis : assuming we can get the parent index to get our current index
        
        if(parent == 0 && k%2==1)           // Induction: returning values depending upon 0/1 and odd and even index
            return 0;
        else if(parent == 0 && k%2==0)
            return 1;
        else if(parent == 1 && k%2==1)
            return 1;
        else
            return 0;
    }
};