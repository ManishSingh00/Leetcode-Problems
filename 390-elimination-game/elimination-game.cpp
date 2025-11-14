class Solution {
public:
    int lastRemaining(int n) {
        int rem = n;
        int step = 1;
        bool left = true;
        int head = 0;

        while(rem > 1){
            if(left == true || (rem %2 ==1)){
                head += step;
            }

            rem /= 2;
            step *= 2;
            left = !left;
        }

        return head+1;
    }
};