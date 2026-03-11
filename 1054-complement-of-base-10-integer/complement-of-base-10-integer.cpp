class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = 0;
        int i = 0;

        while(n > 0){
            if(n % 2 == 0){
                ans += pow(2,i);
            }
            i++;
            n /= 2;
        }

        return ans;
    }
};