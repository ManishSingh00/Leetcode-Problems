class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k>0){
            if(k%2 == 0) return nums[0];
            else return -1;
        }
        else if(k == 1) return nums[1];
        else if(k==0) return nums[0];

        if(k>n) return *max_element(nums.begin(),nums.end());



        priority_queue<int>pq;
        int i = 0;
        while(i<n){
            if(k == 1){
                int maxi = pq.top();
                if(maxi > nums[i+1]) return maxi;
                else return nums[i+1];
            }
            pq.push(nums[i]);
            i++;
            k--;
        }
        return -1;

    }
};