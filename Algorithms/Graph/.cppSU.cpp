struct dsu {
    vt<int> par, sz;
    explicit dsu(int n)
    {
        par.assign(n+1, 0);
        iota(all(par), 0);
        sz.assign(n+1, 1);
    
    }
    int get_par(int x) {
        if (par[x] == x) return x;
        return par[x] = get_par(par[x]);
    }
    bool join(int a, int b) {
        a = get_par(a), b = get_par(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        par[a] = par[b];
        sz[b] += sz[a];
        return true;
    }
};
