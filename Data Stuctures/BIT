struct BIT {
    vector<int> T;
    int n;

    BIT(int n) {
        this->n = n + 1;
        T.assign(n + 1, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += T[idx];
        return ret;
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            T[idx] += delta;
    }
};
