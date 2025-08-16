class Solution {
public:
    int minNumberOperations(vector<int>& tar) {
        int n = tar.size();
        int ans = 0;
        ans += tar[0];
        for(int i=1;i<n;i++){
            if(tar[i]<= tar[i-1]) continue;
            else ans += tar[i] - tar[i-1];
        }

        return ans;
    }
};