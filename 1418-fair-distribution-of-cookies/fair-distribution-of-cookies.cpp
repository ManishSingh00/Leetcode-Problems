class Solution {
public:
    vector<int>child;
    int ans=INT_MAX;
    void f(int i,int k,vector<int>cookies){
        if(i==cookies.size()){
            ans= min(ans,*max_element(child.begin(),child.end()));
            return;
        }

        for(int j=0;j<child.size();j++){
            child[j]+=cookies[i];
            if(child[j]<ans){
                f(i+1,k,cookies);
            }
            child[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        child.resize(k,0);
        f(0,k,cookies);
        return ans;
    }
};