int josephus(int n, int k) {
    if (n == 1) 
        return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n) return 2 * k % n;
        else return 2 * k;
    }
    int c = josephus(n >> 1, k - ( n + 1) / 2);
    if (n & 1) return 2 * c + 1;
    else return 2 * c - 1;
}
