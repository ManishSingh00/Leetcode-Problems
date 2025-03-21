class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int hi=n*m;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int r=mid/m;
            int c=mid%m;
            if(r<n && c<m && matrix[r][c]==tar) return true;
            if(r<n && c<m && matrix[r][c]>tar) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};