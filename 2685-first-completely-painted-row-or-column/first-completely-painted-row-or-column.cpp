class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>>v(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = mat[i][j];
                v[x]={i,j};
            }
        }

        unordered_map<int,int>row;
        unordered_map<int,int>col;

        for(int i=0;i<m*n;i++){
            int x = arr[i];
            row[v[x].first]++;
            if(row[v[x].first]==n) return i;
            col[v[x].second]++;
            if(col[v[x].second]==m) return i;
        }

        return -1;
    }
};