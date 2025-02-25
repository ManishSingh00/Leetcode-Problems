class Solution {
    #define mod 1000000007
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp(n);
        temp[0]=arr[0];
        for(int i=1;i<n;i++){
            temp[i]=temp[i-1]+arr[i];
        }
        int odd=0,even=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(temp[i]%2==0){
                ans = (ans+odd)%mod;
                even++;
            }
            else{
                ans = (ans+even)%mod;
                odd++;
            }
        }

        return ans;

    }
};