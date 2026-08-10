class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Prefix sum 0 has occurred once
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;

            // Check if a previous prefix sum was sum - k
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};