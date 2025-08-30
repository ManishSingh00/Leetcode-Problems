class Solution {
public:
    bool backtrack(int i, vector<int>& jobs, vector<int>& workers, int limit) {
        if (i == jobs.size()) return true;

        for (int j = 0; j < workers.size(); j++) {
            if (workers[j] + jobs[i] <= limit) {
                workers[j] += jobs[i];
                if (backtrack(i+1, jobs, workers, limit)) return true;
                workers[j] -= jobs[i];
            }
            if (workers[j] == 0) break; // symmetry pruning
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0), ans = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            vector<int>workers(k,0);
            if (backtrack(0,jobs, workers, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
