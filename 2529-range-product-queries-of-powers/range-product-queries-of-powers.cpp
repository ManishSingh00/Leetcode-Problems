#define mod 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        int sz = q.size();
        vector<int>powers;
        for (int i = 31; i >= 0; i--) { 
            if(n & (1<<i)) powers.push_back(1<<i);
           
        }
        sort(powers.begin(),powers.end());
        // for(auto x:powers) cout<<x<<" ";
        int nn = powers.size();
        vector<long long>pre(nn);
        pre[0] = powers[0]%mod;

        for(int i=1;i<nn;i++){
            pre[i] = (pre[i-1]*powers[i])%mod;
        }
        vector<int>ans;
        for(int i=0;i<sz;i++){
            int l = q[i][0], r=q[i][1];
            // int temp = pre[r]/(l>0?pre[l-1]:1);
            // ans.push_back(temp);
            long long  temp = powers[l];
            for(int j=l+1;j<=r;j++){
                temp = (temp*powers[j])%mod;
            }
            temp = temp%mod;
            ans.push_back(temp);
            
        }
        return ans;
    }
};