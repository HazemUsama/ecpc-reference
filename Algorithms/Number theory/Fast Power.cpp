ll power(ll b,  ll p, ll mod) {
    ll res = 1;
    b = b % mod;
    if (b == 0) return 0;
    while (p)
    {
        if (p & 1)
            res = (res * b) % mod;
        p >>= 1; 
        b = (b * b) % mod;
    }
    return res;
}
