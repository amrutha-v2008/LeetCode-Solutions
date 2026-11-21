
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), tree(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int prev = last[c];

            newParent[u] = (prev == -1 ? parent[u] : prev);
            last[c] = u;

            for (int v : adj[u]) {
                dfs(v);
            }

            last[c] = prev;
        };

        dfs(0);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<void(int)> calc = [&](int u) {
            for (int v : tree[u]) {
                calc(v);
                ans[u] += ans[v];
            }
        };

        calc(0);

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna