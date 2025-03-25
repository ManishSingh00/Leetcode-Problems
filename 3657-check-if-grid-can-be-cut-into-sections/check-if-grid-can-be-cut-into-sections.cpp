class Solution {
public:
    vector<vector<int>>x_cor;
    vector<vector<int>>y_cor;
    static bool cmp(vector<int>& a,vector<int>&b){
        return a[0]<b[0];
    }
    void merge_interval(vector<vector<int>>& to_merge,vector<vector<int>>& ans){
        ans.push_back(to_merge[0]);
        for(int i=1;i<to_merge.size();i++){
            vector<int>temp=to_merge[i];
            if(ans[ans.size()-1][1]>temp[0]){
                ans[ans.size()-1][0]=min(ans[ans.size()-1][0],temp[0]);
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],temp[1]);
            }
            else{
                ans.push_back(temp);
            }
        }
    }
    bool checkValidCuts(int n, vector<vector<int>>& arr) {
        int m=arr.size();
        for(int i=0;i<m;i++){
            x_cor.push_back({arr[i][0],arr[i][2]});
            y_cor.push_back({arr[i][1],arr[i][3]});
        }
        sort(x_cor.begin(),x_cor.end(),cmp);
        sort(y_cor.begin(),y_cor.end(),cmp);
        vector<vector<int>>ans1;
        vector<vector<int>>ans2;
        merge_interval(x_cor,ans1);
        merge_interval(y_cor,ans2);

        if(ans1.size()>=3 || ans2.size()>=3) return true;
        else return false;

    }
};