// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditio

//METHOD 1:- using two array   T.C = O(3N)   &&    S.C = O(2N)
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
       vector<int>left(n);
       vector<int>right(n);
       left[0] = 1;
       right[n-1] = 1;

       for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1]) {
                left[i] = left[i-1] + 1;
            }
            else left[i] = 1;
       }
        // for(int i = 0; i < n; i++) cout<<left[i];
       for(int i = n-2; i >= 0; i--){
            if(arr[i] > arr[i+1]) {
                right[i] = right[i+1] + 1;
            }
            else right[i] = 1;
       }
        // for(int i = 0; i < n; i++) cout<<right[i];
       int ans = 0;
       for(int i = 0; i < n; i++){
            ans += max(left[i],right[i]);
       }

       return ans;
    }
};

//METHOD 2:- SLOPE APPROACH       T.C=O(n)  &&  S.C = O(1)
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        int i = 1;
        int sum = 1;
        while(i < n){
            if(arr[i] == arr[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && arr[i] > arr[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && arr[i] < arr[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak) sum += (down - peak);
        }
        return sum;
    }
};
 

