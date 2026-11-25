#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Two large primes and bases to prevent hash collisions
        const long long MOD1 = 1e9 + 7, BASE1 = 131313;
        const long long MOD2 = 1e9 + 9, BASE2 = 13131;

        // Precompute powers of BASE1 and BASE2
        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }

        // Helper lambda to check if a unique subarray of length L exists
        auto hasUnique = [&](int L) -> bool {
            long long h1 = 0, h2 = 0;
            
            // Compute hash for the first window [0 ... L-1]
            for (int i = 0; i < L; ++i) {
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;
            }

            // Combine both hashes into a single 64-bit integer key
            unordered_map<unsigned long long, int> freq;
            freq.reserve(n - L + 1);
            
            unsigned long long key = (static_cast<unsigned long long>(h1) << 32) | h2;
            freq[key]++;

            // Slide the window across the rest of the array
            for (int i = L; i < n; ++i) {
                // Remove leftmost element nums[i - L] and add rightmost element nums[i]
                h1 = (h1 - (nums[i - L] * pow1[L - 1]) % MOD1 + MOD1) % MOD1;
                h1 = (h1 * BASE1 + nums[i]) % MOD1;

                h2 = (h2 - (nums[i - L] * pow2[L - 1]) % MOD2 + MOD2) % MOD2;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;

                key = (static_cast<unsigned long long>(h1) << 32) | h2;
                freq[key]++;
            }

            // Check if any subarray hash occurred exactly once
            for (const auto& [hash_val, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };

        // Binary search on the subarray length
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid length
            } else {
                low = mid + 1;  // Need a larger length to make it unique
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna