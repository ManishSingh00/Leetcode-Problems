class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int maxi = log(INT_MAX)/log(3);

        return (int)pow(3,maxi)%n==0 ? true:false;
    }
};