#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        deque<int> dq; // Stores indices with nums[idx] in non-increasing order
        int j = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            // Update cost as nums[i] becomes the new maximum for smaller elements to its right
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                cost += 1LL * (r - l) * (nums[i] - nums[l]);
            }
            dq.push_back(i);

            // Shrink window from the right if total operations exceed k
            while (cost > k) {
                cost -= (nums[dq.front()] - nums[j]);
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }

            // Every subarray [i ... end] with i <= end <= j is valid
            ans += (j - i + 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna