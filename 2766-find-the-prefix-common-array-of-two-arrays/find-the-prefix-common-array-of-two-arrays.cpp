class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        unordered_set<int>st;
        vector<int>ans;
        // for(int i=0;i<n;i++){
        //     st.insert(a[i]);
        //     int cnt=0;
        //     for(int j=0;j<=i;j++){
        //         if(st.count(b[j])!=0) cnt++;
        //     }
        //     ans.push_back(cnt);
        // }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(st.count(a[i])!=0) cnt++;
            else st.insert(a[i]);
            if(st.count(b[i])!=0) cnt++;
            else st.insert(b[i]);

            ans.push_back(cnt);
        }
        return ans;
    }
};