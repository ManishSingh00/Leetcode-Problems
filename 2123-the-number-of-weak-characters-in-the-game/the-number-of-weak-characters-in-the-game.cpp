class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr){
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);

        int cnt = 0;
        int mn = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i][1]<mn) cnt++;
            else mn = arr[i][1];
        }

        return cnt;
    }
};