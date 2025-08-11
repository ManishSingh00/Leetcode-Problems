class Solution {
public:
    bool f(int c,vector<vector<int>>& tar,int m,int n){
        int x1 = m-1, x2 = 0, y1 = n-1, y2 = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(tar[i][j]==c){
                    x1 = min(i,x1);
                    x2 = max(i,x2);
                    y1 = min(j,y1);
                    y2 = max(j,y2);
                }
            }
        }

        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                if(tar[i][j]==c || tar[i][j]==0) continue;
                else return false;
            }
        }
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                tar[i][j] = 0;
            }
        }

        return true;
    }
    bool isPrintable(vector<vector<int>>& tar) {
        int m = tar.size();
        int n = tar[0].size();

        set<int>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                st.insert(tar[i][j]);
            }
        }
        int sz = st.size();
        for(int i=0;i<sz;i++){
            int clr = 0;
            for(auto color:st){
                if(f(color,tar,m,n)==true){
                    clr = color;
                    break;
                }
            }
            if(clr == 0){
                return false;
            }
            st.erase(clr);
        }
        return true;
    }
};