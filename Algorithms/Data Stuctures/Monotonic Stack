for(int i = n- 1; i >= 0; i--)
{
		if (!s.empty()) 
			while (!s.empty() && v[s.top()] <= v[i]) 
				s.pop();
	  next[i] = s.empty() ? -1 : s.top();
	  s.push(i);
}
