#include <iostream>
#include <numeric>
#include <vector>

struct Fraction {
  long long numerator, denominator;

  void simplize() {
    if (denominator == 0) {
      return;
    }
    if (numerator == 0) {
      denominator = 1;
      return;
    }
    auto g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  Fraction(const Fraction &) = default;
  Fraction(Fraction &&) = default;
  Fraction &operator=(const Fraction &) = default;
  Fraction &operator=(Fraction &&) = default;
  Fraction(long long num = 0, long long den = 1)
      : numerator(num), denominator(den) {}

  Fraction operator*(const Fraction &other) const {
    Fraction res(numerator * other.numerator, denominator * other.denominator);
    res.simplize();
    return res;
  }

  Fraction operator/(const Fraction &other) const {
    Fraction res(numerator * other.denominator, denominator * other.numerator);
    res.simplize();
    return res;
  }

  bool operator<(const Fraction &other) const {
    return (__int128_t)numerator * other.denominator <
           (__int128_t)other.numerator * denominator;
  }
  bool operator>(const Fraction &other) const {
    return (__int128_t)numerator * other.denominator >
           (__int128_t)other.numerator * denominator;
  }
  bool operator<=(const Fraction &other) const {
    return (__int128_t)numerator * other.denominator <=
           (__int128_t)other.numerator * denominator;
  }
  bool operator>=(const Fraction &other) const {
    return (__int128_t)numerator * other.denominator >=
           (__int128_t)other.numerator * denominator;
  }
};

long long floor_div(const Fraction &f) {
  if (f.numerator >= 0) {
    return f.numerator / f.denominator;
  }
  return (f.numerator - f.denominator + 1) / f.denominator;
}

long long ceil_div(const Fraction &f) {
  return (f.numerator + f.denominator - 1) / f.denominator;
}

int main() {
  // Fast I/O
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long K_num, N_num, A, B, C, D;
    std::cin >> K_num >> N_num >> A >> B >> C >> D;

    Fraction K_div_N(K_num, N_num);
    Fraction L(A, B);
    Fraction R(C, D);

    std::vector<Fraction> candidates;

    Fraction val_at_R;
    {
      Fraction temp = K_div_N / R;
      long long c = floor_div(temp);
      val_at_R = R * Fraction(c + 1);
      candidates.push_back(val_at_R);
    }

    Fraction val_at_L;
    {
      Fraction temp = K_div_N / L;
      long long c = floor_div(temp);
      val_at_L = L * Fraction(c + 1);
      candidates.push_back(val_at_L);
    }

    Fraction K_div_NR = K_div_N / R;
    long long i_opt = ceil_div(K_div_NR);

    if (i_opt > 0) {
      Fraction X_opt = K_div_N / Fraction(i_opt);

      if (X_opt >= L) {
        Fraction val_at_X_opt = X_opt * Fraction(i_opt);
        candidates.push_back(val_at_X_opt);  // This is f(X_opt - epsilon)

        Fraction val_at_jump =
            (K_div_N / Fraction(i_opt)) * Fraction(i_opt + 1);
        candidates.push_back(val_at_jump);
      }
    }

    Fraction max_val = candidates[0];
    for (size_t i = 1; i < candidates.size(); ++i) {
      if (candidates[i] > max_val) {
        max_val = candidates[i];
      }
    }

    max_val.simplize();
    std::cout << max_val.numerator << '/' << max_val.denominator << '\n';
  }

  return 0;
}
