
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        for (auto &it : items)
            freq[it[0]]++;

        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i)
                gain[i] += freq[j];

            gain[i]--;
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long minPrice = items[0][1];
        long long remaining = budget;
        long long ans = 0;

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            if (price >= 2 * minPrice)
                break;

            long long take = min(
                (long long)gain[factor],
                remaining / price
            );

            ans += 2 * take;
            remaining -= take * price;

            if (take < gain[factor])
                break;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna