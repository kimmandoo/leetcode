class Solution {
public:
    vector<int> p;

    int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    void union_group(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0);

        for (const auto& swap : allowedSwaps) {
            union_group(swap[0], swap[1]);
        }

        unordered_map<int, unordered_map<int, int>> group_counts;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            group_counts[root][source[i]]++;
        }
        int matches = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (group_counts[root][target[i]] > 0) {
                matches++;
                group_counts[root][target[i]]--;
            }
        }

        return n - matches;
    }
};