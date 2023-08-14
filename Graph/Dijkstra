vector<int> dist; // answer -> dist[destination]
vector<vector<pair<int,int>>> g;  // {cost, to}

void djikstra(int src = 1) { 
    dist.resize(g.size(), INFINITY);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[src] = 0, src});
    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        for(auto to : g[curr.second])
            if(dist[to.second] > curr.first + to.first)  
                pq.push({dist[to.second] = curr.first + to.first, to.second});
    }
}
