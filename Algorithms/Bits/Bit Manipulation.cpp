y  =  (x & (1 << i)) // Get the i-th bit
x |=  (1 << i)       // Set the i-th bit
x &= ~(1 << i)       // Clear the i-th bit
(x && !(x &(x-1)))   // if power of 2
1 << (32 - __builtin_clz (n - 1)) // Next power of 2
n & (-n)              // LSB 
