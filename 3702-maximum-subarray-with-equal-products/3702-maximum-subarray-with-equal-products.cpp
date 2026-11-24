
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                g = gcd(g, nums[j]);

                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > 25200)
                    break;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna