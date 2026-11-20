class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        // Sort the array to process elements in non-decreasing order
        sort(nums.begin(), nums.end());
        
        // dp[x] stores the max length of a consecutive sequence ending at x
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int num : nums) {
            // Update dp[num + 1] first so we don't reuse the current element
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num - 1] + 1;
            
            max_len = max({max_len, dp[num], dp[num + 1]});
        }
        
        return max_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna