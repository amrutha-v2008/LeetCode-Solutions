
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests have finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            int server = i % k;

            // Find the next available server
            auto it = available.lower_bound(server);

            if (it == available.end()) {
                it = available.begin();
            }

            server = *it;
            available.erase(it);

            count[server]++;

            // Store finishing time and server ID
            busy.push({(long long)arrival[i] + load[i], server});
        }

        int maxRequests = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna