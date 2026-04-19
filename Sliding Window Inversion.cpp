#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree)
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        coords.push_back(a[i]);
    }

    // Coordinate Compression
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto get_rank = [&](int val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
    };

    FenwickTree ft(coords.size());
    long long current_inversions = 0;

    for (int i = 0; i < n; i++) {
        int rank = get_rank(a[i]);
        
        // 1. Add new element and count how many existing elements are GREATER than it
        // Inversions added = (elements currently in window) - (elements <= current rank)
        int elements_in_window = (i < k) ? i : k - 1; 
        current_inversions += (elements_in_window - ft.query(rank));
        ft.update(rank, 1);

        // 2. Once window is full, handle sliding
        if (i >= k - 1) {
            cout << current_inversions << " ";

            // 3. Remove the element that is sliding out (at index i - k + 1)
            int out_idx = i - k + 1;
            int out_rank = get_rank(a[out_idx]);
            
            // Subtract inversions caused by the element leaving the window
            // Those are elements to its RIGHT that are smaller than it
            current_inversions -= ft.query(out_rank - 1);
            
            ft.update(out_rank, -1);
        }
    }

    return 0;
}
