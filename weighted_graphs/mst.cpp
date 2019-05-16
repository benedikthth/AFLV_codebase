struct Edge { 
    int u, int v;
    int weight;

    Edge(int _u, int _v, int _w){
        u = _u;
        v = _v; 
        w = _w;
    }
}

bool edge_cmp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

vector<Edge> mst(int n, vector<Edge> edges) {
    union_find uf(n);

    sort(edges.begin(), edges.end(), edge_cmp);

    vector<Edge> res;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u,
            v = edges[i].v;

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}