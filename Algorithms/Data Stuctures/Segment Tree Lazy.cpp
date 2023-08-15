#include <bits/stdc++.h>
using namespace std;



/*
Segment tree with lazy propagation
lazy[index] - array for updating the values.
tree[index] - array for finding the sum of elements in a particular range.
Basic technique used - update the array elements range when they are required to be updated 
					   till then keep hold the sum which is to be updated in that range .
qs - query starting
qe - query ending
ss - segment starting
se - segment ending
2*index+1 and 2*index+2 as childs and index as their parent.
*/

#define ll long long 
			
#define MAX 200010
ll a[MAX] , t[4*MAX] , lazy[4*MAX];
void propagate(int ss ,int se, int idx)
{
    t[idx] += lazy[idx]*(se-ss+1);
    // *(se-ss+1) to add the inc value of children nodes to curr node
    // only in sum or similar queries
    if(ss!=se)
    {
        lazy[2*idx+1]+= lazy[idx];
        lazy[2*idx+2]+= lazy[idx];
    }
    lazy[idx] = 0 ;
}
void update(int ss, int se, int qs, int qe, int idx ,ll value)
{
    if(lazy[idx]!=0)
        propagate(ss, se, idx);
    if(qs>se || qe<ss)
        return;
    if(qs<=ss && qe>=se)
    {
        lazy[idx] = value;
        propagate(ss, se, idx);
        return ;
    }
    int mid = (ss+se)/2;
    update(ss, mid , qs, qe, 2*idx+1 , value);
    update(mid+1, se, qs ,qe ,2*idx+2 , value);
    t[idx] = t[2*idx+1] + t[2*idx+2];
}
ll get(int ss, int se, int qs, int qe, int idx)
{
    if(lazy[idx]!=0)
        propagate(ss, se, idx);
    if(qs>se || qe<ss)
        return 0;
    if(qs<=ss && qe>=se)
        return t[idx];

    int mid = (ss+se)/2;
    return get(ss, mid, qs ,qe , 2*idx+1) + get(mid+1 , se, qs , qe, 2*idx+2);
}
void build(int ss, int se, int idx)
{
    if(ss==se)
    {
        t[idx] = a[ss];
        return;
    }
    int mid= (ss+se)/2;
    build(ss , mid , 2*idx+1);
    build(mid+1, se,2*idx+2);
    t[idx] = t[2*idx+1] + t[2*idx+2];
}

int main()
{


    int n, q;
    cin >> n >> q;
	for(int i  = 0; i < 4*MAX; i++)
			lazy[i] = 0 ;
	for(int i =0; i < n; i++)
		cin >> a[i];
	build(0 , n-1, 0);
    while(q--)
    {
		int x; cin >> x;
		if(x == 1)
		{
			int l, r, v;
			cin >> l >> r >> v;
			update(0, n-1, l - 1, r -1, 0, v);
		}
		else
		{
			int ind; cin >> ind;
			cout << get(0, n-1, ind - 1, ind -1, 0) <<  '\n';
		}
	}
	
}
