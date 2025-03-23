#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        
        // Precompute prefix sums: P[i] = sum_{k=0}^{i-1} skill[k]
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + skill[i];
        }
        
        // prev[i] holds the finish time of wizard i for the last processed potion.
        vector<long long> prev(n, 0);
        
        // Process each potion sequentially.
        for (int j = 0; j < m; j++) {
            // Minimum start time required by wizard 0 being free.
            long long req = prev[0];
            // For each wizard i (i>=1), ensure that when wizard i-1 finishes,
            // wizard i is free: start + prefix[i] * mana[j] >= prev[i]
            for (int i = 1; i < n; i++) {
                req = max(req, prev[i] - prefix[i] * (long long)mana[j]);
            }
            long long start = req;
            // Update finish times for current potion:
            // Wizard i finishes at start + prefix[i+1]*mana[j]
            for (int i = 0; i < n; i++) {
                prev[i] = start + prefix[i + 1] * (long long)mana[j];
            }
        }
        
        // The finish time of the last wizard on the last potion is the answer.
        return prev[n - 1];
    }
};
