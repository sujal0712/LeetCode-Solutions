class Solution {
public:
    int solve(int i,int prev_idx,vector<int>& nums, vector<vector<int>>& dp){
        if (i==nums.size()){
            return 0;
        }
        if (dp[i][prev_idx+1]!=-1){
            return dp[i][prev_idx+1];
        }
        int skip = solve(i+1, prev_idx, nums, dp);
        int take= 0;
        if (prev_idx ==-1 || nums[i]>nums[prev_idx] ){
         take = 1+solve(i+1, i, nums, dp);
        }
        return dp[i][prev_idx + 1] = max(take, skip);
    }
     int lengthOfLIS(vector<int>& nums) {
         int n= nums.size();
         vector<vector<int>> dp(n, vector<int>(n+1,-1));
         int result=solve(0,-1, nums, dp);
         return result;

    }
};