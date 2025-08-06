class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int>sum={0};

        for(int i=0;i<m;i++){
            priority_queue<int,vector<int>, greater<int>>pq;

            for(auto x:sum){
                for(int j=0;j<n;j++){
                    pq.push(x+mat[i][j]);
                }
            }
            sum.clear();

            for(int i=0;i<k && pq.size()>0;i++){
                sum.push_back(pq.top());
                pq.pop();
            }
        }

        return sum[k-1];
    }
};
