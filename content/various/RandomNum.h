/**
 * Author: CF
 * Description: Getting a random number
 */
#pragma once

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) {
  uniform_int_distribution<int> dist(l, r);
  return dist(rng);
}
