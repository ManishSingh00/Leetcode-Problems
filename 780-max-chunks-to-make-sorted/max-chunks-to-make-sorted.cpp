class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre_max(n);
        vector<int>suff_min(n);

        pre_max[0] = arr[0];
        for(int i=1;i<n;i++){
            pre_max[i] = max(pre_max[i-1],arr[i]);
        }

        suff_min[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suff_min[i] = min(suff_min[i+1],arr[i]);
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(pre_max[i]<= suff_min[i+1]) ans++;
        }

        return ans+1;
    }
};