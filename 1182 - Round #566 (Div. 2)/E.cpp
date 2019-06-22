#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

// Constants
typedef long long ll;
const ll R = 1e9 + 7; // a^(R-1) = 1 (mod R)
const ll MATRIX_REMAINDER = R - 1;

// Matrix class
class Matrix {
public:
  // Attributes
  int row, col;
  vec<vec<ll> > num;
  
  // Constructors
  Matrix (int row, int col, int defaultValue = 0) {
    this->num = vec<vec<ll> >(row, vec<ll>(col, defaultValue));
    this->row = row, this->col = col;
  }
  Matrix (vec<vec<ll> > num) {
    this->num = num;
    this->row = this->num.size();
    this->col = this->num[0].size();
  }
  
  // Multiplication
  Matrix operator *(Matrix &other) {
    if (this->col != other.row) {
      printf("Wrong size: %d*%d X %d*%d\n", 
             this->row, this->col, other.row, other.col);
      throw "Wrong size";
    }
    Matrix res(this->row, other.col);
    FOR(r, 0, res.row) FOR(c, 0, res.col) {
      FOR(k, 0, this->col) {
        (res.num[r][c] += this->num[r][k] * other.num[k][c]) %= MATRIX_REMAINDER;
      }
    }
    return res;
  }
  
  // Power
  Matrix operator ^(ll x) {
    if (x == 0) {
      printf("Not implemented yet.\n");
      throw "Not implemented";
    }
    if (x == 1) {
      return *this;
    }
    Matrix res = (*this) ^ (x/2);
    res = res * res;
    if (x % 2){
      res = res * (*this);
    }
    return res;
  }
};

// Prime related
const int limit = 1 << 20;
bool isPrime[limit] = {false, };
vec<ll> primes;

// Decompose given value to primes
vec<ll> primeDecomposition(ll x) {
  vec<ll> answer;
  for (ll p : primes) {
    if (x <= 1) {
      break;
    }
    if (x % p == 0) {
      answer.push_back(p);
      while (x % p == 0) {
        x /= p;
      }
    } else if (p * p > x) {
      answer.push_back(x);
      break;
    }
  }
  return answer;
}

// Return a^x % R
ll modPow(ll a, ll x) {
  if (x == 0) {
    return 1;
  }
  ll res = modPow(a, x / 2);
  (res *= res) %= R;
  if (x % 2) {
    (res *= a) %= R;
  }
  return res;
}

// Main fucntion
int main() {
  
  // Matrix functionality testing
  Matrix a1({{1, 2}, 
             {0, 1}});
  Matrix a2({{3, 2},
             {-1, 0}});
  Matrix b = a1 * a2;
  printf("a1*a2 = \n  %lld %lld\n  %lld %lld\n",
         b.num[0][0], b.num[0][1],
         b.num[1][0], b.num[1][1]);
  
  return 0;
}
