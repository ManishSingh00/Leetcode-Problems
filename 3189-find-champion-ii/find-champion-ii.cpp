class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);
        if(n>=2 && edges.size()==0) return -1;
        if(edges.size()==0) return 0;
        for(int i=0;i<edges.size();i++){
            indeg[edges[i][1]]++;
        }
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({indeg[i],i});
        }
        sort(arr.begin(),arr.end());
        if(arr.size() > 1 && arr[0].first!=arr[1].first) return arr[0].second;
        else return -1;
    }
};