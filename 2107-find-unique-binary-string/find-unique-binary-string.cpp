class Solution {
public:
    vector<string>binary;
    void f(int i,int n,string temp){
        if(i==n){
            binary.push_back(temp);
            return;
        }
        temp.push_back('0');
        f(i+1,n,temp);
        temp.pop_back();

        temp.push_back('1');
        f(i+1,n,temp);
        temp.pop_back();      
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int m=nums[0].length();
        f(0,m,"");
        int sz=binary.size();
        sort(nums.begin(),nums.end());
        sort(binary.begin(),binary.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=binary[i]) return binary[i];
        }
        return binary[n];
    }
};