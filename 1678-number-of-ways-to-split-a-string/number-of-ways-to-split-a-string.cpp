#define mod 1000000007
class Solution {
public:
    int numWays(string s) {
        long long  n = s.length();
        int one = 0;
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
                pos.push_back(i);
            }
        }
        long long ans = 1;

        if(one == 0) return (1LL*(n-1)*(n-2)/2)%mod;
        else if(one % 3 != 0) return 0;
        else{
            int x = one/3;
            int op1 = pos[x] - pos[x-1];
            int op2 = pos[2*x] - pos[2*x - 1];
            op1 %= mod;
            op2 %= mod;
            ans = (1LL*op1*op2)%mod;
        }

        return ans;
    }
};