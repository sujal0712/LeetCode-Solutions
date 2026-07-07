class Solution {
public:
    vector<int> dp;

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1, -1);

        return f(n, cost);
    }

    int f(int i, vector<int>& cost) {
        if (i == 0 || i == 1) return 0;

        if (dp[i] != -1) return dp[i];

        int oneStep = f(i - 1, cost) + cost[i - 1];
        int twoStep = f(i - 2, cost) + cost[i - 2];

        return dp[i] = min(oneStep, twoStep);
    }
};