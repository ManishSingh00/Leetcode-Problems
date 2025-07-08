class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        set<int>st1(nums1.begin(),nums1.end());
        set<int>st2(nums2.begin(),nums2.end());
        int common = 0;
        for (int x : st1) {
            if (st2.count(x)) common++;
        }

        int unq1 = st1.size()-common;
        int unq2 = st2.size()-common;

        int take1 = min(n/2,unq1);
        int take2 = min(n/2,unq2);

        int rem1 = n/2-take1, rem2 = n/2-take2;

        int temp = min(common, rem1+rem2);

        return take1+take2+temp;



    }
};