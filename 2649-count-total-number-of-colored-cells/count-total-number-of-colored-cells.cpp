class Solution {
public:
    long long f(int n){
        if(n==1) return 1;
        return 4*(n-1) + f(n-1);
    }
    long long coloredCells(int n) {
        return f(n);
    }
};