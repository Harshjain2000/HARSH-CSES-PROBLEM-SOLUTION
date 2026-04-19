#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to balance the two multisets
void balance(multiset<ll> &sl, multiset<ll> &sr, ll &s1, ll &s2, ll k) {
    ll target_sl = (k + 1) / 2;
    
    // If sl is too small
    while (sl.size() < target_sl && !sr.empty()) {
        ll val = *sr.begin();
        s1 += val;
        s2 -= val;
        sl.insert(val);
        sr.erase(sr.begin());
    }
    // If sl is too large
    while (sl.size() > target_sl) {
        ll val = *sl.rbegin();
        s2 += val;
        s1 -= val;
        sr.insert(val);
        sl.erase(prev(sl.end()));
    }
}

void insert(multiset<ll> &sl, multiset<ll> &sr, ll &s1, ll &s2, ll x, ll k) {
    if (sl.empty() || x <= *sl.rbegin()) {
        sl.insert(x);
        s1 += x;
    } else {
        sr.insert(x);
        s2 += x;
    }
    balance(sl, sr, s1, s2, k);
}

void remove1(multiset<ll> &sl, multiset<ll> &sr, ll &s1, ll &s2, ll x, ll k) {
    auto it = sl.find(x);
    if (it != sl.end()) {
        s1 -= x;
        sl.erase(it);
    } else {
        s2 -= x;
        sr.erase(sr.find(x));
    }
    balance(sl, sr, s1, s2, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 1) {
        for (int i = 0; i < n; i++) cout << 0 << " ";
        return 0;
    }

    multiset<ll> sl, sr;
    ll s1 = 0, s2 = 0;

    for (int i = 0; i < n; i++) {
        insert(sl, sr, s1, s2, a[i], k);
        
        if (i >= k - 1) {
            ll median = *sl.rbegin();
            // formula: (median * sl.size() - s1) + (s2 - median * sr.size())
            ll cost = (median * (ll)sl.size() - s1) + (s2 - median * (ll)sr.size());
            cout << cost << " ";
            
            remove1(sl, sr, s1, s2, a[i - k + 1], k);
        }
    }
    return 0;
}
