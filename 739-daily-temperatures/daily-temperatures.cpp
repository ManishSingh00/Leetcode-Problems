class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);

        stack<int>st;
        st.push(n-1);
        ans[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()] <= arr[i]) st.pop();

            if(st.size()>0) ans[i] = st.top()-i;

            st.push(i);
        }

        return ans;
    }
};