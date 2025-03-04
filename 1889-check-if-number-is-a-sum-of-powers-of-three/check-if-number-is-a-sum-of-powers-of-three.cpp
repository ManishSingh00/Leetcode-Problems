class Solution {
public:
vector<int> arr = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721};
    bool f(int n,int i){
        if(n==0) return true;
        if(n<0 || i>=arr.size()) return false;
        int ans=false;
        ans = ans || f(n,i+1);
        ans= ans || f(n-arr[i],i+1);
        return ans;
    }
    bool checkPowersOfThree(int n) {
        return f(n,0);
    }
};