//~ The Z-function for this string is an array of length  
//~ $n$  where the  
//~ $i$ -th element is equal to the greatest number of characters starting from the position  
//~ $i$  that coincide with the first characters of  
//~ $s$ .

//~ In other words,  
//~ $z[i]$  is the length of the longest string that is, at the same time, a prefix of  
//~ $s$  and a prefix of the suffix of  
//~ $s$  starting at  
//~ $i$ .
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

//~ String compression
//~ Given a string 	 
//~ $s$  of length  
//~ $n$ . Find its shortest "compressed" representation, that is: find a string  
//~ $t$  of shortest length such that  
//~ $s$  can be represented as a concatenation of one or more copies of  
//~ $t$ .

//~ A solution is: compute the Z-function of  
//~ $s$ , loop through all  
//~ $i$  such that  
//~ $i$  divides  
//~ $n$ . Stop at the first  
//~ $i$  such that  
//~ $i + z[i] = n$ . Then, the string  
//~ $s$  can be compressed to the length  
//~ $i$ .
