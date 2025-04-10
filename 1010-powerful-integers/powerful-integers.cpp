class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>ans;
        for(int i=1;i<bound;i*=x){
            for(int j=1;j+i<=bound;j*=y){
                ans.insert(i+j);
                if(y==1) break;
            }
            if(x==1) break;
        }
        vector<int>arr(ans.begin(),ans.end());
        return arr;
    }
};