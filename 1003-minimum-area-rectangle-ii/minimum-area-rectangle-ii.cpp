class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& arr) {
        int n=arr.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int x=arr[i][0],y=arr[i][1];
            st.insert(x*40001+y);
        }
        double ans=1e20;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    for(int k=j+1;k<n;k++){
                        if(k!=i){
                            int x1=arr[i][0],y1=arr[i][1];
                            int x2=arr[j][0],y2=arr[j][1];
                            int x3=arr[k][0],y3=arr[k][1];
                            int x4=x2-x1+x3, y4=y2-y1+y3;
                            // int val=x4*40001+y4;
                            if(x4>=0 && x4<40001 && y4>=0 && y4<40001 && st.find(x4*40001+y4)!=st.end()){
                                if(((x2-x1)*(x3-x1) + (y2-y1)*(y3-y1))==0){
                                    int dist1=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                                    int dist2=(x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
                                    ans=min(ans,sqrt(1LL*dist1*dist2));
                                }
                            }
                        }
                    }
                }
            }
        }
        if(ans==1e20) return 0;
        else return ans;
        
    }
};