vector<int> dijkstra(int node,vector<vector<int>> graph, vector<vector<pair<int,int>>> adj){
	//construccion de la lista de adyacencia
	for(const auto& it: graph){
		int u=it[0];
		int v=it[1];
		int w=it[2];
		adj[u].emplace_back(w,v);
		adj[v].emplace_back(w,u); //grafo no dirigido
	}

	//vector para almacenar las distancias
	int n=adj.size();
	vector<int> dist(n,INT_MAX);
	dist[node]=0;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.emplace(0,node);

	while(!pq.empty()){
		int currentDist=pq.top().first;
		int u=pq.top().second;
		pq.pop();

		//si la distancia actual es mayor que la registrada, omitir
		if(currentDist >  dist[u]) continue;

		//revisar todos los vecinos de u
		for(auto& [weight,v]: adj[u]){
			if(dist[u]+weight < dist[v]){
				dist[v]=dist[u]+weight;
				pq.emplace(dist[v],v);
			}
		}
	}
	return dist;
}