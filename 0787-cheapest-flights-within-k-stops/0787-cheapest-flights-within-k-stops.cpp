class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> dist(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (auto &f : flights) {
                int from = f[0];
                int to = f[1];
                int price = f[2];

                if (dist[from] == INF) continue;

                if (dist[from] + price < temp[to]) {
                    temp[to] = dist[from] + price;
                }
            }

            dist = temp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};