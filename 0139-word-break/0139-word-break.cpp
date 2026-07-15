class Solution {
public:
    bool solve(int i, string& s, unordered_set<string>& words , vector<int>& dp){
        if (i==s.size()) return true;
        if (dp[i]!= -1) return dp[i];
        string currentword = "";
        for (int j=i;j<s.size();j++){
            currentword += s[j];
            if (words.count(currentword) && solve(j+1, s, words, dp)){
                return dp[i]= true;
                }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> words(wordDict.begin(), wordDict.end());
         vector<int> dp(s.size(), -1);
         return solve(0,s,words, dp);
    }
};