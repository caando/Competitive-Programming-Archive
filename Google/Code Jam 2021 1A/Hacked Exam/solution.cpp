#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

using Int = __int128;

Int gcd(Int x, Int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 123;
Int CC[N][N];
int n, m;
char s[3][N];
int d[3];
char ans[N];
Int val[4];

void printInt(Int x) {
	if (x == 0) {
		printf("0");
		return;
	}
	vector<int> w;
	while(x > 0) {
		w.push_back(x % 10);
		x /= 10;
	}
	reverse(all(w));
	for (int z : w)
		printf("%d", z);
}
void printAns(Int p, Int q) {
	Int g = gcd(p, q);
	p /= g;
	q /= g;
	p = m * q - p;
	ans[m] = '\0';
	printf("%s ", ans);
	printInt(p);
	printf("/");
	printInt(q);
	printf("\n");
}

void solve1() {
	if (2 * d[0] < m) {
		for (int i = 0; i < m; i++)
			ans[i] = s[0][i];
		printAns(d[0], 1);
	} else {
		for (int i = 0; i < m; i++)
			ans[i] = s[0][i] ^ ('F' ^ 'T');
		printAns(m - d[0], 1);
	}
}

void solve2() {
	int X = 0, Y = 0;
	for (int i = 0; i < m; i++) {
		if (s[0][i] == s[1][i]) {
			X++;
		} else {
			Y++;
		}
	}
	int x = d[0] + d[1] - Y;
	if (x < 0 || x > 2 * X || x % 2 == 1) throw;
	x /= 2;
	int y = d[0] - x;
	if (y < 0 || y > Y) throw;
	if (2 * x < X) {
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i]) {
				ans[i] = s[0][i];
			}
		}
	} else {
		x = X - x;
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i]) {
				ans[i] = s[0][i] ^ ('F' ^ 'T');
			}
		}
	}
	if (2 * y < Y) {
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i]) {
				ans[i] = s[0][i];
			}
		}
	} else {
		y = Y - y;
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i]) {
				ans[i] = s[0][i] ^ ('F' ^ 'T');
			}
		}
	}
	printAns(x + y, 1);
}

void solve3() {
	int A = 0, B = 0, C = 0, D = 0;
	for (int i = 0; i < m; i++) {
		if (s[0][i] == s[1][i]) {
			if (s[0][i] == s[2][i]) {
				A++;
			} else {
				B++;
			}
		} else {
			if (s[0][i] == s[2][i]) {
				C++;
			} else {
				D++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		val[i] = 0;
	Int Q = 0;
	for (int a = 0; a <= A; a++) {
		int b = d[0] + d[1] - C - D;
		if (b % 2 == 1) continue;
		b /= 2;
		b -= a;
		if (b < 0 || B < b) continue;
		int c = d[0] + d[2] - B - D;
		if (c % 2 == 1) continue;
		c /= 2;
		c -= a;
		if (c < 0 || C < c) continue;
		int e = d[0] - a - b - c;
		if (e < 0 || D < e) continue;
		Int cur = CC[A][a] * CC[B][b] * CC[C][c] * CC[D][e];
		Q += cur;
		val[0] += a * cur;
		val[1] += b * cur;
		val[2] += c * cur;
		val[3] += e * cur;
	}
	for (int i = 0; i < m; i++)
		ans[i] = s[0][i];
	if (2 * val[0] > A * Q) {
		val[0] = A * Q - val[0];
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i] && s[0][i] == s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[1] > B * Q) {
		val[1] = B * Q - val[1];
		for (int i = 0; i < m; i++) {
			if (s[0][i] == s[1][i] && s[0][i] != s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[2] > C * Q) {
		val[2] = C * Q - val[2];
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i] && s[0][i] == s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	if (2 * val[3] > D * Q) {
		val[3] = D * Q - val[3];
		for (int i = 0; i < m; i++) {
			if (s[0][i] != s[1][i] && s[0][i] != s[2][i])
				ans[i] ^= ('F' ^ 'T');
		}
	}
	printAns(val[0] + val[1] + val[2] + val[3], Q);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", s[i], &d[i]);
		d[i] = m - d[i];
	}
	if (n == 1)
		solve1();
	else if (n == 2)
		solve2();
	else
		solve3();
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		CC[i][0] = CC[i][i] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 1; j < i; j++)
			CC[i][j] = CC[i - 1][j - 1] + CC[i - 1][j];

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
