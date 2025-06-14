#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    cout << t << endl;
    while (t--) {
        ll h;
        int n;
        cin >> h >> n;
        
        vector<ll> damage(n);
        vector<ll> cooldown(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> damage[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> cooldown[i];
        }
        
        priority_queue<pair<ll, int>> pq; // (damage, index)
        for (int i = 0; i < n; ++i) {
            pq.push({damage[i], i});
        }
        
        ll turns = 0;
        vector<ll> nextAvailable(n, 0); // when each attack will be available
        
        while (h > 0) {
            turns++;
            ll totalDamage = 0;
            vector<pair<ll, int>> usedAttacks; // to track used attacks this turn
            
            // Use all available attacks
            while (!pq.empty()) {
                auto [dmg, idx] = pq.top();
                if (nextAvailable[idx] <= turns) {
                    totalDamage += dmg;
                    usedAttacks.push_back({dmg, idx});
                    pq.pop(); // remove it from the queue
                } else {
                    break; // No more available attacks
                }
            }
            
            // Apply total damage to the boss
            h -= totalDamage;
            
            // Reinsert used attacks with updated next available times
            for (auto [dmg, idx] : usedAttacks) {
                nextAvailable[idx] = turns + cooldown[idx];
                pq.push({dmg, idx});
            }
            
            // If no attacks were used, we can skip turns
            if (totalDamage == 0) {
                // All attacks are on cooldown; skip to the next available turn
                ll nextTurn = LLONG_MAX;
                for (int i = 0; i < n; ++i) {
                    if (nextAvailable[i] > turns) {
                        nextTurn = min(nextTurn, nextAvailable[i]);
                    }
                }
                turns = nextTurn; // Jump to the next available attack
            }
        }
        
        cout << turns << '\n'; // Output the number of turns needed
    }
    
    return 0;
}
