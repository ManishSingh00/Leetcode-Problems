class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int spr=startPos[0],spc=startPos[1];
        int epr=homePos[0],epc=homePos[1];
        int ans=0;
        if(spr>epr){
            for(int i=spr-1;i>=epr;i--){
                ans+=rowCosts[i];
            }
        }
        else{//epr>spr
            for(int i=spr+1;i<=epr;i++){
                ans+=rowCosts[i];
            }
        }

        
        if(spc>epc){
            for(int i=spc-1;i>=epc;i--){
                ans+=colCosts[i];
            }
        }
        else{//epr>spr
            for(int i=spc+1;i<=epc;i++){
                ans+=colCosts[i];
            }
        }
        return ans;
    }
};