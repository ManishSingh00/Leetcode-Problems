class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);

        vector<int>brr(n);
        for(int i=0;i<n;i++){
            brr[i]=arr[i][1];
            // cout<<arr[i][1]<<" ";
        }

        vector<int>temp;
        temp.push_back(brr[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<brr[i]){
                temp.push_back(brr[i]);
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),brr[i]) - temp.begin();
                cout<<idx<<" ";
                temp[idx] = brr[i];
                cout<<"hello";
            }
        }
        return temp.size();
    }
};