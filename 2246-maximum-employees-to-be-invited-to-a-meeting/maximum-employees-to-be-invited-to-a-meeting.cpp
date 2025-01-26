class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            indeg[fav[i]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>depth(n,1);
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            int next = fav[curr];
            indeg[next]--;
            depth[next]= 1+depth[curr];
            if(indeg[next]==0) q.push(next);
        }
        int longest_cycle=0,len_of_chain_for_two_len_cycles=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) continue;
            int cycle_len=0,curr=i;
            while(indeg[curr]!=0){
                indeg[curr]--;
                cycle_len++;
                curr=fav[curr];
            }

            if(cycle_len==2){
                len_of_chain_for_two_len_cycles += depth[i] + depth[fav[i]];
            }
            else{
                longest_cycle = max(longest_cycle,cycle_len);
            }
        }
        return max(longest_cycle,len_of_chain_for_two_len_cycles);
    }
};