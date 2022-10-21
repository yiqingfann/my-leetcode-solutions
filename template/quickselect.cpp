// https://www.acwing.com/problem/content/submission/code_detail/17606410/
// https://www.acwing.com/problem/content/submission/code_detail/17606689/

#include <bits/stdc++.h>

using namespace std;

int qselect(vector<int> &a, int l, int r, int k) {
    if (l == r) return a[l];

    int x = a[l], i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < x)
            ;
        while (a[--j] > x)
            ;
        if (i < j) swap(a[i], a[j]);
    }

    int sl = j - l + 1;
    if (k <= sl) qselect(a, l, j, k);
    else qselect(a, j + 1, r, k - sl);
}


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << qselect(a, 0, n - 1, k) << endl;

    return 0;
}