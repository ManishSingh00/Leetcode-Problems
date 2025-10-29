class Solution {
public:
    int smallestNumber(int n) {
        int bits = floor(log2(n)) + 1;

        // if((1<<bits) - 1 == n) bits++; if only greater number than n is asked to return

        return (1<<bits) - 1;
    }
};