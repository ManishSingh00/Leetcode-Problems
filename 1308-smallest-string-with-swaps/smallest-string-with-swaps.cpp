class Solution {
public:
    void dfs(int i,vector<bool>& vis,vector<int>& group,vector<list<int>>& gr){
        vis[i]=true;
        group.push_back(i);
        for(auto it:gr[i]){
            if(vis[it]==false){
                dfs(it,vis,group,gr);

            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        string temp=s;
        vector<list<int>>gr(n);

        for(auto x: pairs){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }
        vector<vector<int>>groups;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vector<int>group;
                dfs(i,vis,group,gr);
                groups.push_back(group);
            }
        }
        for(auto group:groups){
            vector<int>idx=group;
            sort(idx.begin(),idx.end());
            vector<char>chars;
            for(int i=0;i<idx.size();i++){
                chars.push_back(temp[idx[i]]);
            }
            sort(chars.begin(),chars.end());
            for(int i=0;i<chars.size();i++){
                s[idx[i]]=chars[i];
            }
        }
        return s;
    }
};