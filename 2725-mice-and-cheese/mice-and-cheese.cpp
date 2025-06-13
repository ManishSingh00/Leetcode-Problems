class Solution {
public:
    int miceAndCheese(vector<int>& arr, vector<int>& brr, int k) {
        int n = arr.size();

        vector<int>temp;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += brr[i];
            temp.push_back(arr[i]-brr[i]);
        }

        sort(temp.rbegin(),temp.rend());
        int i = 0;
        while(i<n && k--){
            ans += temp[i];
            i++;
        }

        return ans;
    }
};