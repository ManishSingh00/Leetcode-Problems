class Solution {
public:
    vector<int>prime_num;
    void sieveOfEratosthenes(int n,int left,int right) {
        vector<bool> isPrime(n + 1, true); // Create a boolean array and initialize all entries as true
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false; // Mark multiples of i as non-prime
                }
            }
        }

        // Print all prime numbers
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                prime_num.push_back(i);
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        int x=-1,y=-1;
        int diff=INT_MAX;
        sieveOfEratosthenes(right,left,right);
        if(prime_num.size()==0) return {x,y};
        for(int i=0;i<prime_num.size()-1;i++){
            if(prime_num[i+1]-prime_num[i]<diff){
                x=prime_num[i];
                y=prime_num[i+1];
                diff=prime_num[i+1]-prime_num[i];
            }
        }
        return {x,y};
    }
};