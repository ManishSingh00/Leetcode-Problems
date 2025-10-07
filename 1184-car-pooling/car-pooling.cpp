class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>arr(1002,0);
        int n = trips.size();

        for(int i=0;i<n;i++){
            int sz = trips[i][0] , from = trips[i][1] , to = trips[i][2];

            arr[from] += sz;
            arr[to] -= sz;
        }
        if(arr[0] > capacity) return false;
        for(int i=1;i<1002;i++){
            arr[i] += arr[i-1];
            if(arr[i] > capacity) return false;
        }

        return true;
    }
};