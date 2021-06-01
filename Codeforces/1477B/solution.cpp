#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair

int t[1000010], lazy[1000010];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
		t[v] = a[tl];
		lazy[v] = -1;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        lazy[v] = -1;
		t[v] = t[v*2] + t[v*2+1];
    }
}

void push(int v, int tl, int tr) {
	if (lazy[v] != -1){
		lazy[v*2] = lazy[v];
		lazy[v*2+1] = lazy[v];
		int tm = (tl + tr) / 2;
		t[v*2] = (tm - tl + 1) * lazy[v];
		t[v*2+1] = (tr - tm) * lazy[v];
	}
    lazy[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int change) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = change * (tr - tl + 1);
        lazy[v] = change;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), change);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, change);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
	t[v] = t[v * 2] + t[v * 2 + 1];
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}


int main(){
	int test;
	cin >> test;
	forn(T, 0, test){
		ll n, q;
		cin >> n >> q;
		pair<int, int> queries[q];
		int start[n], end[n];
		forn(i, 0, n) {
			char temp;
			cin >> temp;
			if (temp == '1') start[i] = 1;
			else start[i] = 0;
		}
		forn(i, 0, n) {
			char temp;
			cin >> temp;
			if (temp == '1') end[i] = 1;
			else end[i] = 0;
		}
		build(end, 1, 0, n-1);
		forn(i, 0, q) cin >> queries[i].fi >> queries[i].se;
		bool poss = true;
		for (int i = q-1; i >= 0; i--){
			if (query(1, 0, n-1, queries[i].fi-1, queries[i].se-1) == (queries[i].se - queries[i].fi + 1) / 2 && (queries[i].se - queries[i].fi + 1) % 2 == 0){
				poss = false;
				break;
			} else if (query(1, 0, n-1, queries[i].fi-1, queries[i].se-1) > (queries[i].se - queries[i].fi + 1) / 2){
				update(1, 0, n-1, queries[i].fi-1, queries[i].se-1, 1);
			} else {
				update(1, 0, n-1, queries[i].fi-1, queries[i].se-1, 0);
			}
		}
		forn(i, 0, n){
			if (query(1, 0, n-1, i, i) != start[i]) poss = false;
		}
		if (poss) cout << "YES\n";
		else cout << "NO\n";
	}
}