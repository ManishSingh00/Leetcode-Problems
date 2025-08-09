class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int slidingPuzzle(vector<vector<int>>& arr) {
        queue<pair<vector<vector<int>>,int>>q;
        set<vector<vector<int>>>vis;
        q.push({arr,0});
        vis.insert(arr);

        vector<vector<int>>ans;
        vector<int>v1 = {1,2,3};
        vector<int>v2 = {4,5,0};
        ans.push_back(v1);
        ans.push_back(v2);

        
        while(q.size()>0){
            vector<vector<int>> v = q.front().first;
            int step = q.front().second;
            q.pop();

            if(v == ans) return step;
            int i,j;
            bool flag = false;
            for(int ii=0;ii<=1;ii++){
                for(int jj=0;jj<=2;jj++){
                    if(v[ii][jj] == 0){
                        i=ii;
                        j=jj;
                        flag= true;
                        break;
                    }
                }
                if(flag == true) break;
            }

            for(int k=0;k<4;k++){
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(nr>=0 && nc>=0 && nr<=1 && nc<=2){
                    vector<vector<int>>copy = v;
                    swap(copy[i][j], copy[nr][nc]);
                    if(!vis.count(copy)){
                        vis.insert(copy);
                        q.push({copy, step + 1});
                    }
                }
            }

        }

        return -1;
    }
};