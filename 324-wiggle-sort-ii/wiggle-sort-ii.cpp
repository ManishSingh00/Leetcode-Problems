class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp=nums;

        for(int i=1;i<nums.size();i+=2){
            nums[i]=temp.back();
            temp.pop_back();
        }
        for(int i=0;i<nums.size();i+=2){
            nums[i]=temp.back();
            temp.pop_back();
        }
    }
};