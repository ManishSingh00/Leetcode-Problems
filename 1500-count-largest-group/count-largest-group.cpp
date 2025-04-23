class Solution {
public:
    int f(int num){
        int sum=0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>arr(40,0);
        for(int i=1;i<=n;i++){
            int sum=f(i);
            arr[sum]++;
        }
        sort(arr.rbegin(),arr.rend());
        int cnt=1;
        int i=1;
        while(i<n && arr[i-1] == arr[i]){
            cnt++;
            i++;
        }
        return cnt;
    }
};