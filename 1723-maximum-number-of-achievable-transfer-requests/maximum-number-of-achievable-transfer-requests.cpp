class Solution {
public:
    vector<int>indeg;
    int ans;
    void f(int i,vector<vector<int>>& arr,int sz,int cnt,int n){
        if(i == sz){
            for(int i=0;i<n;i++){
                if(indeg[i]!=0) return;
            }
            ans = max(ans,cnt);
            return;
        }
        
        f(i+1,arr,sz,cnt,n);// Not Take

        indeg[arr[i][0]]--;
        indeg[arr[i][1]]++;
        f(i+1,arr,sz,cnt+1,n); // TAKE
        // BACKTRACK    
        indeg[arr[i][0]]++;
        indeg[arr[i][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& arr) {
       indeg.resize(n,0);
       int sz = arr.size();
       int cnt = 0;
       f(0,arr,sz,0,n);
       return ans;
    }
};