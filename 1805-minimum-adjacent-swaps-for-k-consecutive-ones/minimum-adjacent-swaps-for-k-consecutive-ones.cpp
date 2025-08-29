#define ll long long int
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pos;

        for(int i=0;i<n;i++){
            if(nums[i] == 1) pos.push_back(i);
        }
        int m = pos.size();
        vector<ll>pref(m);
        pref[0] = pos[0];
        for(int i=1;i<m;i++){
            pref[i] = pref[i-1] + pos[i];
        }
        // cout<<"hello"<<endl;
        ll tot_moves = LLONG_MAX;
        for(int i=0;i+k-1 < m;i++){
            int mid = i+k/2;

            ll right = pref[i+k-1] - pref[mid];
            ll left = (mid - 1 >= 0) ? (pref[mid - 1] - (i > 0 ? pref[i - 1] : 0)) : 0;

            tot_moves = min(tot_moves,right - left + (k % 2 == 0 ? pos[mid] : 0));
        }
        int radius = (k-1)/2;
        ll spread = 1LL*(2*(1LL*radius*(radius+1))/2) + (k%2==0?radius+1:0);

        return (int)(tot_moves - spread);
    }
};
// first we are counting the minimum total number of moves to collect all the ones at one position which is the median of that particular K size window

// after that we are spreading that 1 from the to both sides by havind some radius and by subtracting the total spreadd from initial total moves will be the answer