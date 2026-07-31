class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0)
            return false;
        if(n&(n-1))
            return false;
        int pos=0;
        while(n>1){
            n>>=1;
            pos++;
        }
        return pos%2==0;
    }
};