class Solution {
public:
   
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        //No of rows
        int cols = mat[0].size();
        //No of cols
        vector<int>ans;
        for(int i=0;i<rows;i++)
        //Traversing each row
        {
            int low =0;
            int high = cols-1;
            while(low<=high)
            //Applying BS in each row
            {
                int mid = (low+high)/2;

            //Checking all 4 directions
                int upper = i>0?mat[i][mid]:-1;
                int lower = i<rows-1?mat[i+1][mid]:-1;
                int left = mid>0?mat[i][mid-1]:-1;
                int right = mid<cols-1?mat[i][mid+1]:-1;

            //Checking max of vertical and horizonta direction
            //Not so imp steps
                int maxVertical = max(upper,lower);
                int maxHorizontal = max(left,right);

            //Finding max Half values
                int maxLeftHalf = max(left,mat[i][0]);
                int maxRightHalf = max(right,mat[i][cols-1]);

            //If our peak elem has been found
                if(mat[i][mid]>=max(maxVertical,maxHorizontal))
                {
                    ans.push_back(i);
                    ans.push_back(mid);
                    return ans;
                }
                else if(maxLeftHalf > maxRightHalf)
                //If left half is greater than right half then our peak elem
                //has greater prob of being in left half
                {
                    high = mid-1;
                }
                else
                //Greater prob of being in right half
                low=mid+1;
            }
        }
        return ans;
    }
};