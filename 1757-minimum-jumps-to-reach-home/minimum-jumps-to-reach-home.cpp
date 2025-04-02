class Solution {
public:
    int minimumJumps(vector<int>& arr, int a, int b, int x) {
        unordered_set<int>st(arr.begin(),arr.end());
        queue<pair<int,int>>q;
        vector<int>vis_forward(10000,0);
        vector<int>vis_backward(10000,0);
        q.push({0,0});//{x=0,no backward move} 1 represent backward move
        int jump=0;
        vis_forward[0]=1;
        while(q.size()>0){
            int len=q.size();
            while(len--){
                int curr=q.front().first;
                int check=q.front().second;
                q.pop();
                if(curr==x) return jump;
                if(curr+a<10000 && vis_forward[curr+a]==0 && st.count(curr+a)==0){
                    q.push({curr+a,0});
                    vis_forward[curr+a]=1;
                    // jump++;
                }
                if(check==0 && curr-b>=0 && vis_backward[curr-b]==0 && st.count(curr-b)==0){
                    q.push({curr-b,1});
                    vis_backward[curr-b]=1;
                    // jump++;
                }
            }
            jump++;
        }
        return -1;
    }
};