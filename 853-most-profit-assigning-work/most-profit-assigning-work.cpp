class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        int ans = 0;

        sort(worker.begin(),worker.end());
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(),arr.end());

        int i = 0,j = 0;
        int temp = 0;
        while(i<m){
            // int j = 0;

            while(j<n && arr[j].first<=worker[i]){
                temp = max(temp,arr[j].second);
                j++;
            }
            ans += temp;
            i++;
        }
        return ans;
    }
};