/**
 * Author: EnEm
 * Description: A basis is a set of pairwise indepedent vectors that span the
 * space.
 *
 * Here every integer is considered a vector and xor is the operation used. So a
 * basis is a set of integers whose subset xor gives every other integer. Most
 * problems deal with finding the size of the basis, which is $\text{dim()}$
 * in the code. Sometimes you would need a segment tree of basisxor.
 *
 * Assuming that every integer in input is less than $2^{60}$. chk(t)
 * return true iff we can get an integer t as xor of some subset. dim() returns
 * the number of integers required to span all other integers.
 * Time: $O(1)$ per operation.
 */

class basisxor {
public:
  ll bs[60];
  basisxor() {
    for (int i = 0; i < 60; i++)
      bs[i] = 0;
  }

  bool chk(ll t) {
    while (t != 0 && bs[leftmost_bit(t)] != 0) {
      t ^= bs[leftmost_bit(t)];
    }

    if (t == 0)
      return true;
    return false;
  }

  bool add(ll t) {
    while (t != 0 && bs[leftmost_bit(t)] != 0) {
      t ^= bs[leftmost_bit(t)];
    }

    if (t == 0)
      return false;
    bs[leftmost_bit(t)] = t;
    return true;
  }

  int dim() {
    int ans = 0;
    for (int i = 0; i < 60; i++) {
      if (bs[i] != 0)
        ans++;
    }
    return ans;
  }
};