class Solution {
public:
    vector<vector<int>>gr;
    vector<vector<int>>char_pos;
    vector<int>subtree_sz;
    vector<bool>vis;


    void dfs(int src,string& s){
        subtree_sz[src] = 1;
        char_pos[s[src]-'a'].push_back(src);

        vis[src] = true;
        for(auto v:gr[src]){
            if(vis[v] == false){
                dfs(v,s);

                int letter = s[v] - 'a';
                if(char_pos[letter].size() == 0) subtree_sz[src] += subtree_sz[v];
                else{
                    subtree_sz[char_pos[letter].back()] += subtree_sz[v];
                }
            }
        }
        char_pos[s[src] - 'a'].pop_back();

    }

    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n = par.size();
        gr.resize(n);
        vis.resize(n,false);
        subtree_sz.resize(n,0);
        for(int i=0;i<n;i++){
            if(par[i] != -1){
                gr[par[i]].push_back(i);
            }
        }
        char_pos.resize(26);
        dfs(0,s);

        return subtree_sz;

    }
};