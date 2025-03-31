#define ll long long int
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<ll>temp(n-1);
        for(int i=0;i<n-1;i++){
            temp[i]=weights[i]+weights[i+1];
        }
        sort(temp.begin(),temp.end());
        ll maxi=0,mini=0;
        for(int i=0;i<k-1;i++){
            mini+=temp[i];
            maxi+=temp[n-2-i];
        }
        return maxi-mini;
    }
};