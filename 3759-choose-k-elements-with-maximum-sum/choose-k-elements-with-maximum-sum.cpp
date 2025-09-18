#define ll long long int
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>>arr(n,vector<int>(3));

        for(int i=0;i<n;i++){
            vector<int>temp = {nums1[i],nums2[i],i};
            arr[i] = temp;
        }
        // cout<<"hello"<<endl;
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<ll>ans(n);
        ll sum = 0;

        for(int i=0;i<n;i++){
            // cout<<"hello"<<" "<<i<<endl;
            // cout<<arr[i][0]<<arr[i][1]<<arr[i][2]<<endl;
            if(i > 0 && arr[i][0] == arr[i-1][0]) ans[arr[i][2]] = ans[arr[i-1][2]];
            else ans[arr[i][2]] = sum;

            sum += arr[i][1];
            pq.push(arr[i][1]);
            if(pq.size() > k){
                sum -=  pq.top();
                pq.pop();
            }

        }

        return ans;
    }
};