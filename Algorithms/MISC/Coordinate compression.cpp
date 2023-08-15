

//method 1

void compress(vector<ll>&a,int start)
{
    int n=a.size();
    vector<pair<ll,ll>>pairs(n);
    for(int i=0;i<n;i++)
    {
        pairs[i]={a[i],i};
    }
    sort(pairs.begin(),pairs.end());
    int nxt=start;
    for(int i=0;i<n;i++)
    {
        if(i>0&&pairs[i-1].first!=pairs[i].first)
        {
            nxt++;
        }
        a[pairs[i].second]=nxt;
    }
}

//method 2
int getCompressedIndex(int a) {
	return lower_bound(v.begin(), v.end(), a) - v.begin();
}

	//========= COORDINATE COMPRESSION =======
	sort(v.begin(), v.end());
	indices.erase(unique(v.begin(), v.end()), v.end());
	
//  another method :

// use map to store value of ind and map to store ind of val	
	
