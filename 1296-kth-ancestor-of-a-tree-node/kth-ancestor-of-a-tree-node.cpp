class TreeAncestor {
public:
    vector<vector<int>>up;
    vector<vector<int>>gr;
    int LOG;

    void dfs(int src,int parent){
        up[src][0]=parent;
        for(auto v:gr[src]){
            dfs(v,src);
        }
    }

    void preprocess(int n , int LOG){
        for(int j = 1;j<LOG;j++){
            for(int v=1;v<n;v++){
                if(up[v][j-1]!=-1){
                    up[v][j] = up[up[v][j-1]][j-1];
                }
            }
        }
    }
    int findKthAncestor(int LOG,int x,int k){
        for (int i = LOG - 1; i >= 0; i--) {
            if (k & (1 << i)) {
                if (up[x][i] == -1) return -1;
                x = up[x][i];
            }
        }
        return x;
    }

    TreeAncestor(int n, vector<int>& parent) {
        gr.resize(n);
        for(int i=1;i<n;i++){
            gr[parent[i]].push_back(i);
        }
        LOG = log2(n) + 1;
        up.resize(n,vector<int>(LOG,-1));

        dfs(0,-1); // it will fill the first col of up array which tells the immediate parent.
        preprocess(n,LOG);
    }
    
    int getKthAncestor(int node, int k) {
        return findKthAncestor(LOG,node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */