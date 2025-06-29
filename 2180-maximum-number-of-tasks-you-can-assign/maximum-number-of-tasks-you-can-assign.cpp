class Solution {
public:
    bool f(int k,vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int>mt(workers.end()-k,workers.end());

        for(int i=k-1;i>=0;i--){
            if(*mt.rbegin() >= tasks[i]) mt.erase(mt.find(*mt.rbegin()));
            else{
                if(pills<=0) return false;
                auto it = mt.lower_bound(tasks[i]-strength);
                if(it == mt.end()) return false;

                mt.erase(it);
                pills--;
            }

        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int lo = 0;
        int hi = min(n,m);
        int ans = 0;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;

            if(f(mid,tasks,workers,pills,strength) == true){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        return ans;
    }
};