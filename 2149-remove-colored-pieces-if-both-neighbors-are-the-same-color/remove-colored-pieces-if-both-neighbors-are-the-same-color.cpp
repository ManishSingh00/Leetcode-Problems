class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();

        vector<int>a;
        vector<int>b;

        int i=0,j=0;

        while(i<n){
            int len = 0;
            while(colors[i] == colors[j]){
                j++;
            }
            
            if(colors[i]=='A'){
                a.push_back(j-i);
            } 
            else b.push_back(j-i);
            i=j;
        }

        int x=0;
        int y=0;
        for(auto z:a){
            if(z>=3){
                x+=(z-2);
            }
        }
        for(auto z:b){
            if(z>=3){
                y+=(z-2);
            }
        }
        if(x>y) return true;
        else return false;
    }
};