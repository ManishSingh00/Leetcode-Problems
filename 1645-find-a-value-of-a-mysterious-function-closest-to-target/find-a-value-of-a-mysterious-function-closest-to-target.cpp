class Solution {
public:
    int closestToTarget(vector<int>& arr, int tar) {
        int n = arr.size();
        int ans = INT_MAX;

        unordered_set<int>prev, curr;
        for(int i=0;i<n;i++){
            curr.clear();
            curr.insert(arr[i]);
            ans = min(ans, abs(tar-arr[i]));

            for(auto x:prev){
                int temp = x&arr[i];
                ans = min(ans,abs(tar-temp));
                curr.insert(temp);

            }

            prev = curr;
        }
       

        return ans;
    }
};