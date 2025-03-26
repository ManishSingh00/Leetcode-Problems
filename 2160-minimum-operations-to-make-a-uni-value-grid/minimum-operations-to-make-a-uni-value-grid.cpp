class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int sz=n*m;
        int mid;
        if(sz%2==0) mid=sz/2 - 1;
        else mid=sz/2;
        int cnt=0;
        for(int i=0;i<sz;i++){
            int diff=abs(arr[i]-arr[mid]);
            if(diff!=0 && diff<x) return -1;
            if(diff%x!=0) return -1;
            int temp=diff/x;
            cnt+=temp;
        }
        return cnt;
    }
};