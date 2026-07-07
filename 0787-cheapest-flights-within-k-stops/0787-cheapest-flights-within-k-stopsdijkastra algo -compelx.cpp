class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : flights){
            int from = edge[0];
            int to = edge[1];
            int price = edge[2];
            graph[from].push_back({to, price});

        }
       int maxFlights = k + 1;
        vector<vector<int>> dist(n, vector<int>(maxFlights + 1, INT_MAX));
        dist[src][0] = 0;
        priority_queue<tuple<int , int, int >, vector<tuple<int, int , int>>, greater<tuple <int, int, int>>> pq;
        pq.push({0, src, 0});
        while(!pq.empty()){
            auto [cost, city, flights_used] = pq.top();
            pq.pop();
            if (city == dst) return cost;
            if (flights_used == maxFlights) continue;
            for ( auto& [next_node, price]: graph[city]){
                int nextFlights = flights_used + 1;
                int newCost = cost + price;

                if (newCost < dist[next_node][nextFlights]) {
                    dist[next_node][nextFlights] = newCost;
                    pq.push({newCost, next_node, nextFlights});

                   }           
                 }
        }
         return -1;
    }
};