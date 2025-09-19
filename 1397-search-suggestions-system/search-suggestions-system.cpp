class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& arr, string word) {
        int n = arr.size();
        int m = word.length();
        sort(arr.begin(),arr.end());
        vector<vector<string>>ans;

        string search = "";
        for(int i=0;i<m;i++){
            search += word[i];

            int idx = lower_bound(arr.begin(),arr.end(),search) - arr.begin();
            cout<<idx<<" ";
            int cnt = 0;
            vector<string>st;
            for(int j=idx;j<n && cnt < 3;j++){
                if(arr[j].substr(0,search.size()) == search){
                    cnt++;
                    st.push_back(arr[j]);
                }
            }
            ans.push_back(st);
        }

        return ans;
    }
};