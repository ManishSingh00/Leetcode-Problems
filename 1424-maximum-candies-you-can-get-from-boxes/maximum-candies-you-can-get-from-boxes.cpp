class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initial) {
        int n = candies.size();
        queue<int>q;
        vector<bool>found_box(n,false);
        
        for(int i=0;i<initial.size();i++){
            q.push(initial[i]);
            found_box[initial[i]] = true;
        }
        vector<bool>arr(n,false);
        unordered_set<int>find_keys;

        int ans = 0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            if(status[curr]==1 || find_keys.count(curr)==true){

                if(arr[curr]==false){
                    ans += candies[curr];
                    arr[curr] = true;

                }
                for (int k : keys[curr]) {
                    if (find_keys.find(k) == find_keys.end()) {
                        find_keys.insert(k);
                        if (found_box[k]==true && arr[k]==false) {
                            q.push(k);
                        }
                    }
                }
                
                for(auto v:containedBoxes[curr]){
                    if(found_box[v]==false){
                        q.push(v);
                        found_box[v] = true;
                    }
                }
            }


        }
        // for(auto x:find_keys){
        //     if(arr[x] == false && found_box[x]==true) ans+= candies[x]; 
        // }
        return ans;
    }
};