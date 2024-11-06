#include <iostream>
#include <vector>
using namespace std;

long long computeXOR(long long n) {
    switch(n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0; 
}

long long rangeXOR(long long l, long long r) {
    return computeXOR(r) ^ computeXOR(l - 1);
}

long long xorificator(long long l, long long r, int i, long long k) {
    long long modValue = 1LL << i; // 2^i
    long long excludeStart = (k % modValue == 0) ? l : k;
    long long result = 0;
    
    for (long long x = l; x <= r; ++x) {
        if (x % modValue != k % modValue) {
            result ^= x;
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t; 
    vector<long long> results;
    
    for (int q = 0; q < t; ++q) {
        long long l, r, k;
        int i;
        cin >> l >> r >> i >> k;
        
        long long result = xorificator(l, r, i, k);
        results.push_back(result);
    }
    
    for (long long res : results) {
        cout << res << endl;
    }
    
    return 0;
}
