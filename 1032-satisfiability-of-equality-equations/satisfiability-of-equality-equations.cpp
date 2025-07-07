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
    bool equationsPossible(vector<string>& arr) {
        par.resize(26);
        rank.resize(26,1);
        int n = arr.size();

        for(int i=0;i<26;i++) par[i] = i;

        for(int i=0;i<n;i++){
            if(arr[i][1] == '='){
                Union(arr[i][0]-'a', arr[i][3]-'a');
            }
        }


        for(int i=0;i<n;i++){
            if(arr[i][0] == arr[i][3] && arr[i][1]=='!') return false;
            if(arr[i][1] == '!'){
                int x = find(arr[i][0]-'a');
                int y = find(arr[i][3]-'a');
                cout<<i<<"hello"<<endl;
                if(x==y) return false;
            }
        }
        return true;
    }
};