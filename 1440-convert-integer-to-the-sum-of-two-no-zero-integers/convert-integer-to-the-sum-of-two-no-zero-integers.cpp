class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            int a = i;
            int b = n-i;
            bool flag = true;
            while(a>0){
                int rem = a%10;
                if(rem == 0){
                    flag = false;
                    break;
                }
                a/=10;
            }
            if(flag == false) continue;

            bool flag2 = true;
            while(b>0){
                int rem = b%10;
                if(rem == 0){
                    flag2 = false;
                    break;
                }
                b/=10;
            }

            if(flag2 == true){
                return {i,n-i};
            }

            
        }

        return {};
    }
};