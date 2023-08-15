vt<ll>T;
void update(ll node, ll val){
	T[node] = val;
	for(int i = node/2 ; i > 0; i /= 2) 
		T[i] = min(T[i*2], T[i * 2 + 1]);
}
ll range_min (ll node, ll ql, ll qr, ll node_l, ll node_r){
		if(node_l>= ql && node_r <= qr) return T[node];
		if(node_l > qr || node_r < ql) return LONG_LONG_MAX;
		ll mid  = (node_l + node_r) / 2;
		return  min(range_min(2*node, ql, qr, node_l, mid),
		 range_min(2*node + 1, ql, qr, mid + 1, node_r));
}
void Solve()   	
{
	ll n, q;
	 cin >> n >> q;
	int temp = 1;
	int in_size = n;
	while(temp <= n)
		temp <<= 1;
	n = temp;
	T.assign(2 * n, LONG_LONG_MAX);
	for(int i = 0; i  < in_size; i++) cin >> T[i + n];
	for(int i = n - 1 ; i >= 1; i--) T[i] = min(T[2*i], T[2*i + 1]);
 
	while(q--)
	{	
		ll x, l, r;
		cin >> x >> l >> r;
		if(x == 1) update(l + n - 1, r); // point update set v[l] = r
		if(x == 2)
		cout << range_min(1, l, r, 1, n) << nl;
	}		
 
}
