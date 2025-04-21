class Solution {
public:
     static bool cmp(vector<int> &a,vector<int>&b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        int cnt=0,curr=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i][0]>curr){
                curr=arr[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};