class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m=bookings.size();
        vector<int>diff(n+1);
        for(int i=0;i<m;i++){
            int l=bookings[i][0],r=bookings[i][1],val=bookings[i][2];
            diff[l-1] += val;
            diff[r] -= val;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=diff[i];
        }
        return ans;
    }
};