class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while(l < r){
            int m = l + (r - l) / 2;
            int opr = 0;

            for(int b: nums){
                opr += (b - 1) / m;
            }

            if(opr <= maxOperations){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};