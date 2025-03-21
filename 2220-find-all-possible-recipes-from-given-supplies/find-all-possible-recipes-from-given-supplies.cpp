class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // vector<string>ans;
        // unordered_map<string,vector<int>>gr;
        // int n=recipes.size();
        // unordered_set<string>supp(supplies.begin(),supplies.end());

        // vector<int>indeg(n,0);
        // for(int i=0;i<n;i++){
        //     for(auto x:ingredients[i]){
        //         if(supp.count(x)==0){
        //             gr[x].push_back(i);
        //             indeg[i]++;
        //         }
        //     }
        // }
        // queue<int>q;
        // for(int i=0;i<n;i++){
        //     if(indeg[i]==0) q.push(i);
        // }
        // while(q.size()>0){
        //     int curr=q.front();
        //     q.pop();
        //     ans.push_back(recipes[curr]);
        //     for(auto v:gr[recipes[curr]]){
        //         indeg[v]--;
        //         if(indeg[v]==0) q.push(v);
        //     }
        // }

        // return ans;


        vector<string>ans;
        int n=recipes.size();
        unordered_set<string>st;
        for(auto x:supplies) st.insert(x);

        bool check=true;

        while(check==true){
            check=false;

            for(int i=0;i<n;i++){
                if(st.count(recipes[i])!=0) continue;
                bool flag=true;
                for(auto x:ingredients[i]){
                    if(st.count(x)==0){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    ans.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    check=true;
                }
            }
        }
        return ans;
    }
};