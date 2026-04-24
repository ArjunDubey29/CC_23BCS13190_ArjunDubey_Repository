class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> bitCount(32,0);
        for(int num : nums){
            for(int b = 0; b < 32; b++){
                if(num & (1 << b))
                    bitCount[b]++;
            }
        }
        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long val = 0;
            for(int b = 0; b < 32; b++){
                if(bitCount[b] > 0){
                    val |= (1LL << b);
                    bitCount[b]--;
                }
            }
            ans = (ans + (val * val) % MOD) % MOD;
        }
        return ans;
    }
};