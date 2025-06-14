#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
// geckforgeck 

void solve(){
    string s; cin >> s; 
    string pat; cin >> pat;
    int has_s[256] = {0};
    int has_pat[256] = {0};
    for (char x : pat){
        has_pat[x]++;
    }
    int n = s.size();
    int start = 0;
    int start_index = -1;
    int min_lenght = 1e9;
    int i = 0;
    // Count the number !
    int cnt = 0;
    while (i < n){
        has_s[s[i]]++;
        if (has_s[s[i]] < has_pat[s[i]]){
            cnt++;
        }
        if (cnt == pat.size()){
            while (has_s[s[start]] > has_pat[s[start]] || has_pat[s[start]] == 0){
                if (has_s[s[start]] > has_pat[s[start]]){
                    has_s[s[start]]--;
                }
                start++;
            }
        }
        if (min_lenght > i-start+1){
            min_lenght = min(i-start+1, min_lenght);
            start_index = start;
        }
        i++;
    }
    if (start_index == -1){
        cout << -1;
    }
    else {
        string result = s.substr(start, min_lenght);
        cout << result << endl;
    }
}

int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
