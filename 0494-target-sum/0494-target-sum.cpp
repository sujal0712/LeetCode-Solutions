class Solution {
public:
    int solve(int i,int current_sum,int target,vector<int>& nums, unordered_map<string, int>& dp ){
        if (i == nums.size()) {
            if (current_sum == target) {
                return 1;
            }
            return 0;
        }
        string key = to_string(i)+","+ to_string(current_sum);
        if (dp.count(key)) return dp[key];
        
        int add=solve(i+1,current_sum+nums[i],target, nums,dp);
        
        int subtract=solve(i+1, current_sum-nums[i],target, nums,dp);
        return dp[key]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> dp;
        return solve(0,0,target , nums,dp);    
    }
};