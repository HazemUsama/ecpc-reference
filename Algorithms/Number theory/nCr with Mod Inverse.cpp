ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod);
}

ll nCr(ll n, ll r, ll mod)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    return (fac[n] * modInverse(fac[r], mod) % mod
            * modInverse(fac[n - r], mod) % mod)
        % mod;
}
