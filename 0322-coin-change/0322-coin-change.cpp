class Solution {
public:
    int solve(int amount ,vector<int>& coins,vector<int>& dp){
    if (amount == 0){
        return 0;

    }
    if (amount<0) return 1e9;
    if (dp[amount]!=-1){
        return dp[amount];
    }
    int minimum_coins=1e9;
    for (auto& coin:coins){
    int result = solve(amount- coin, coins, dp);
    minimum_coins = min(minimum_coins, result+1);
    }
    return dp[amount]=minimum_coins;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int result= solve(amount, coins , dp);
        if (result >= 1e9) return -1;
        return result;
    }
};