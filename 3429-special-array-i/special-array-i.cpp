class Solution {
public:
    bool isEven(int x){
        if(x%2==0) return true;
        else return false;
    }
    bool isOdd(int x){
        if(x%2==0) return false;
        else return true;
    }
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
                if((isOdd(nums[i]) && isEven(nums[i+1])) || (isEven(nums[i]) && isOdd(nums[i+1]))) continue;
                else return false;
        }
        return true;
        
    }
};