/**
 * Author: kactl
 * Description: Bit tricks for bitmasking or SOS DP
 */
#pragma once

#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define pow2(i) (1LL << (i))
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off

int m = some_mask;
for (int x = m; x;) { // loops over all submasks of m except m itself
  --x &= m;
  ...
}

int c = m & -m;
int r = m + c;
int next = ((((r ^ m) >> 2) / c) |
            r); // gives the number greater than m with same set bit count
#define SZ 1e5
bitset<SZ> bit;
bit.all();               // checks whether all bits are set or not
bit.any();               // checks whether >= 1 bit is on
bit.none();              // checks if all bits are off
bit.count();             // counts no of set bits
bit.flip();              // flips all bits
bit.flip(1);             // flips 1st bit
bit.reset();             // resets all bits to 0
bit.reset(1);            // resets 1st bit
bit.set();               // sets all bits to 1
bit.set(1);              // sets 1st bit to 1
bit.size();              // return size of bitset
bit.test(1);             // check if 1st bit is on or not
cout << bit.to_string(); // converts to string