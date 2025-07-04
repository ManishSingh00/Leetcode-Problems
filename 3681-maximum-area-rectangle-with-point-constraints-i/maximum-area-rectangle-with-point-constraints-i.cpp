class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& arr) {
        int n = arr.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(arr[i][0]*1000 + arr[i][1]);
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int x1 = arr[i][0], y1 = arr[i][1];
                int x2 = arr[j][0], y2 = arr[j][1];
                if (x1 == x2 || y1 == y2) continue;
                int fnd1 = x1*1000+y2, fnd2 = x2*1000+y1;

                if(st.count(fnd1)!=0 && st.count(fnd2)!=0){
                    int minx = min(x1,x2), maxx = max(x1,x2);
                    int miny = min(y1,y2), maxy = max(y1,y2);
                    bool flag = false;

                    for(int k=0;k<n;k++){
                        int px = arr[k][0], py = arr[k][1];

                        if ((px == x1 && py == y1) || (px == x2 && py == y2) ||
                            (px == x1 && py == y2) || (px == x2 && py == y1)) continue;

                        if(px>=minx && px<=maxx && py>=miny && py<=maxy){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) ans = max(ans,abs(x2-x1)*abs(y2-y1));
                }
            }
        }
        return ans;
    }
};