class Solution {
public:

    vector<int>rank;
    vector<int>par;
    int comps;
    int find(int x){
        if(x==par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void Union(int a,int b){
        a = find(a);
        b=  find(b);

        if(a!=b) comps--;

        if(rank[a]>=rank[b]){
            par[b] = a;
            rank[a]++;
        }
        else{
            par[a] = b;
            rank[b]++;
        }
    }
    bool f(string a, string b){
        int n = a.length();
        int mismatch = 0;
        for(int i=0;i<n;i++){
            if(a[i] == b[i]) continue;
            else mismatch++;
        }
        return mismatch<=2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        comps = n;
        par.resize(n);
        rank.resize(n,1);

        for(int i=0;i<n;i++) par[i] = i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(f(strs[i],strs[j]) == true){
                    Union(i,j);
                }
            }
        }

        return comps;
    }
};