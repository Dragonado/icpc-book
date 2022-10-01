#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define pow2(i) (1LL << (i))
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
