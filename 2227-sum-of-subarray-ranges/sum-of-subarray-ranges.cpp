#define ll long long int
class Solution {
public:

    ll saare_subarr_ka_min(vector<int>& arr){
        int n = arr.size();
        vector<int>pre(n); // previous less element
        vector<int>nxt(n); // next less element

        stack<int>st;
        pre[0]=-1;
        st.push(0);

        // cout<<"hello";
        for(int i=1;i<n;i++){
            while(st.size()> 0 && arr[st.top()] > arr[i]) st.pop();
            if(st.size()>0) pre[i] = st.top();
            else pre[i]=-1;
            st.push(i);
        }
        // cout<<"hello";
        stack<int>st2;
        nxt[n-1]=n;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st2.size()>0 && arr[st2.top()] >= arr[i]) st2.pop();
            if(st2.size()>0) nxt[i] = st2.top();
            else nxt[i] = n;
            st2.push(i);
        }
        // cout<<"hello2";


        long long ans = 0;
        for(int i=0;i<n;i++){
            long long l = i-pre[i];
            long long r = nxt[i]-i;
            // ans = (ans + (arr[i]*l%mod*r%mod))%mod;
            ans += arr[i]*l*r;
        }

        return ans;
    }

    ll saare_subarr_ka_max(vector<int>& arr){
        int n = arr.size();
        vector<int>pre(n); // previos greater
        vector<int>nxt(n); // next greater 

        stack<int>st;
        pre[0]=-1;
        st.push(0);

        // cout<<"hello";
        for(int i=1;i<n;i++){
            while(st.size()> 0 && arr[st.top()] < arr[i]) st.pop();
            if(st.size()>0) pre[i] = st.top();
            else pre[i]=-1;
            st.push(i);
        }
        // cout<<"hello";
        stack<int>st2;
        nxt[n-1]=n;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st2.size()>0 && arr[st2.top()] <= arr[i]) st2.pop();
            if(st2.size()>0) nxt[i] = st2.top();
            else nxt[i] = n;
            st2.push(i);
        }
        // cout<<"hello2";


        long long ans = 0;
        for(int i=0;i<n;i++){
            long long l = i-pre[i];
            long long r = nxt[i]-i;
            // ans = (ans + (arr[i]*l%mod*r%mod))%mod;
            ans += arr[i]*l*r;
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        ll x = saare_subarr_ka_max(nums);
        ll y = saare_subarr_ka_min(nums);

        return x-y;
    }
};