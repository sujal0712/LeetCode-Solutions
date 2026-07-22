class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target==0) {
            return 1;
        }
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][target] != -1) return dp[i][target];
        int skip = solve(i + 1, target, nums, dp);
        int take =0;
        if (nums[i] <= target){
         take = solve(i + 1, target-nums[i], nums, dp);
        }
        return dp[i][target] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum = sum + num;
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1 ,-1));

        return solve(0, target, nums, dp);
    }
};