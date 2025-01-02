#include "bits/stdc++.h"
#ifndef ALGO
#define DUMP(...)
#endif
using i64 = long long;
template<typename T, typename U>
inline bool enlarge(T& a, U b) {
  return a < b ? (a = b, true) : false;
}
template<typename T, typename U>
inline bool minify(T& a, U b) {
  return a > b ? (a = b, true) : false;
}



template<typename T>
struct Matrix final : public std::vector<std::vector<T>> {
  using std::vector<std::vector<T>>::vector;

  Matrix(int n, int m) : std::vector<std::vector<T>>(n, std::vector<T>(m)) {}
  Matrix(int n, int m, T val) : std::vector<std::vector<T>>(n, std::vector<T>(m, val)) {}
  Matrix(int n, std::vector<T> row_vals) : std::vector<std::vector<T>>(n, row_vals) {}
  template<typename GenFunc>
  Matrix(int n, int m, GenFunc&& gen) : Matrix(n, m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        (*this)[i][j] = gen(i, j);
      }
    }
  }

  static Matrix eye(int n, int m, int diagonal_index = 0) {
    Matrix ret(n, m);
    for (int i = 0; i < n; ++i) {
      int j = i + diagonal_index;
      if (0 <= j && j < m) ret[i][j] = T{1};
    }
    return ret;
  }
  static Matrix identity(int n) { return eye(n, n); }

  static Matrix diagonal(const std::vector<T>& arr) {
    const int n = arr.size();
    Matrix ret(n, n);
    for (int i = 0; i < n; ++i) ret[i][i] = arr[i];
    return ret;
  }
  static Matrix diagonal(const Matrix& mat, int diagonal_index = 0) {
    const int n = mat.num_rows();
    const int m = mat.num_cols();
    Matrix ret(n, m);
    for (int i = 0; i < n; ++i) {
      int j = i + diagonal_index;
      if (0 <= j && j < m) ret[i][j] = mat[i][j];
    }
    return ret;
  }

  T operator()(int i, int j) const {
    return (*const_cast<Matrix*>(this))(i, j);
  }
  T& operator()(int i, int j) {
    return (*this)[i][j];
  }

  int num_rows() const { return this->size(); }
  int num_cols() const { assert(num_rows() > 0); return (*this)[0].size(); }

  T trace(int diagonal_index = 0) const {
    T ret{};
    for (int i = 0; i < num_rows(); ++i) {
      int j = i + diagonal_index;
      if (0 <= j && j < num_cols()) ret += (*this)[i][j];
    }
    return ret;
  }

  Matrix transposed() const {
    Matrix ret(num_cols(), num_rows());
    for (int j = 0; j < num_cols(); ++j) {
      for (int i = 0; i < num_rows(); ++i) {
        ret[j][i] = (*this)[i][j];
      }
    }
    return ret;
  }

  // In counter-clockwise.
  Matrix rotated90() const {
    Matrix ret = this->transposed();
    for (int i = 0, ii = ret.num_rows() - 1; i < ii; ++i, --ii) {
      std::swap(ret[i], ret[ii]);
    }
    return ret;
  }

  // A^t * B.
  Matrix power_with(long long t, Matrix B) const {
    assert(t >= 0);
    Matrix A = *this;
    for (; t; t >>= 1, A = A * A) if (t & 1) B = A * B;
    return B;
  }
  Matrix power(long long t) const {
    return power_with(t, identity(num_cols()));
  }
};

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
  assert(lhs.num_cols() == rhs.num_rows());
  Matrix<T> ret(lhs.num_rows(), rhs.num_cols());
  static std::vector<T> buffer;
  buffer.resize(rhs.num_rows());
  for (int j = 0; j < rhs.num_cols(); ++j) {
    for (int k = 0; k < rhs.num_rows(); ++k) {
      buffer[k] = rhs[k][j];
    }
    for (int i = 0; i < lhs.num_rows(); ++i) {
      T val = 0;
      for (int k = 0; k < rhs.num_rows(); ++k) {
        val += lhs[i][k] * buffer[k];
      }
      ret[i][j] = val;
    }
  }
  return ret;
}

template<typename T>
Matrix<T>& operator*=(Matrix<T>& mat, T scale) {
  for (int i = 0; i < mat.num_rows(); ++i) {
    for (int j = 0; j < mat.num_cols(); ++j) {
      mat[i][j] *= scale;
    }
  }
  return mat;
}
template<typename T>
Matrix<T> operator*(Matrix<T> mat, T scale) { return mat *= scale; }
template<typename T>
Matrix<T> operator*(T scale, Matrix<T> mat) { return mat *= scale; }

template<typename T>
Matrix<T>& operator+=(Matrix<T>& lhs, const Matrix<T>& rhs) {
  assert(lhs.num_rows() == rhs.num_rows());
  assert(lhs.num_cols() == rhs.num_cols());
  for (int i = 0; i < lhs.num_rows(); ++i) {
    for (int j = 0; j < lhs.num_cols(); ++j) {
      lhs[i][j] += rhs[i][j];
    }
  }
  return lhs;
}
template<typename T>
Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>& rhs) { return lhs += rhs; }

template<typename T>
Matrix<T>& operator-=(Matrix<T>& lhs, const Matrix<T>& rhs) {
  assert(lhs.num_rows() == rhs.num_rows());
  assert(lhs.num_cols() == rhs.num_cols());
  for (int i = 0; i < lhs.num_rows(); ++i) {
    for (int j = 0; j < lhs.num_cols(); ++j) {
      lhs[i][j] -= rhs[i][j];
    }
  }
  return lhs;
}
template<typename T>
Matrix<T> operator-(Matrix<T> lhs, const Matrix<T>& rhs) { return lhs -= rhs; }

template<typename T>
struct MatrixCommaInitializer {
  Matrix<T>& mat;
  const int strip = 0;
  int i = 0, j = 0;
  explicit MatrixCommaInitializer(Matrix<T>& mat) : mat(mat), strip(mat.num_cols()) {}
  template<typename R>
  MatrixCommaInitializer operator,(R x) {
    mat(i, j) = x;
    if (++j == strip) {
      ++i;
      j = 0;
    }
    return *this;
  }
};

template<typename T, typename R>
MatrixCommaInitializer<T> operator<<(Matrix<T>& mat, R x) {
  return (MatrixCommaInitializer<T>{mat}, x);
}

template<typename T>
struct MatrixPower {
  std::vector<Matrix<T>> table{};

  MatrixPower() = default;
  explicit MatrixPower(Matrix<T> A, int num_bits = 64) : table(num_bits) {
    table[0] = std::move(A);
    for (int i = 1; i < table.size(); ++i) table[i] = table[i - 1] * table[i - 1];
  }
  Matrix<T> power(long long t) const {
    return power_with(t, Matrix<T>::identity(table[0].num_cols()));
  }
  Matrix<T> power_with(long long t, Matrix<T> B) const {
    assert(t >= 0);
    for (int i = 0; i < table.size() && t >> i; ++i) if (t >> i & 1) B = table[i] * B;
    return B;
  }
};

//-#include "matrix.hpp"



namespace power_details {
template<typename T, typename Enable = void>
struct Identity { static constexpr T get() { return T{1}; } };
template<typename T>
struct Identity<T, std::void_t<decltype(T::identity())>> {
  static constexpr T get() { return T::identity(); }
};
}  // namespace power_details

template<typename T,
         typename MulFunc = std::function<T(T,T)>,
         typename SqrFunc = std::function<T(T)>>
constexpr T power(T a, long long b, MulFunc&& mul, SqrFunc&& sqr) {
  T ret = sqr(power_details::Identity<T>::get());
  for (; b; b >>= 1, a = sqr(a)) if (b & 1) ret = mul(ret, a);
  return ret;
}
template<typename T, typename MulFunc = std::function<T(T,T)>>
constexpr T power(T a, long long b, MulFunc&& mul) {
  return power(a, b, std::forward<MulFunc>(mul), [&](T x) { return mul(x, x); });
}
template<typename T, typename IT = T>
constexpr T power(T a, long long b, T mod) {
  return power(a, b, [&mod](T x, T y) { return static_cast<IT>(x) * y % mod; });
}
template<typename T>
constexpr T power(T a, long long b) {
  return power(a, b, [](T x, T y) { return x * y; });
}

template<typename T>
struct PowerTable final : public std::vector<T> {
  PowerTable() = default;
  PowerTable(int n, const T& g)
    : PowerTable(n, g, [](const T& lhs, const T& rhs) -> T { return lhs * rhs; }) {}
  template<typename MulFunc = std::function<T(T,T)>>
  PowerTable(int n, const T& g, MulFunc&& mul) {
    static_assert(sizeof(PowerTable) == sizeof(std::vector<T>), "");
    this->resize(n + 1);
    this->at(0) = power_details::Identity<T>::get();
    for (int i = 1; i < this->size(); ++i) this->at(i) = mul(this->at(i - 1), g);
  }
};

//-#include "power.hpp"


// using Float = long double;
using Float = __float128;

struct Solver {

  void solve(int ca, std::istream& reader) {
    int N;
    Float P;
    reader >> N;
    {
      int tmp;
      reader >> tmp;
      P = (Float)tmp / 1e9;
    }

    constexpr int BAR = 50;

    auto prob = [&](int pre, int cur, int rest) -> Float {
      if (cur <= 0 || cur > BAR) return 0;
      if (rest <= 0 || cur > rest + 1) return 0;
      if (pre == cur) return 0;
      if (pre > 1 && pre <= cur) return 0;
      if (cur == 1) {
        return P;
      }
      if (cur == 2) {
        if (pre == 1 || rest == 1) return 1 - P;
        return 1.0 - P + P * P;
      }
      Float ret = power<Float>((1 - P + P * P), (1ll << (cur - 2)) - 2);
      ret *= pre == 1 ? 1 - P : 1 - P + P * P;
      ret *= rest + 1 == cur ? 1 - P : 1 - P + P * P;
      return ret;
    };

    constexpr int DIM = (BAR + 1) * 2;
    Matrix<Float> B(DIM, 1);
    B[0][0] = 1.;

    auto make_matrix = [&](int rest) -> Matrix<Float> {
      Matrix<Float> A(DIM, DIM);
      for (int i = 0; i <= BAR; ++i) {
        for (int j = 1; j <= BAR; ++j) if (i != j && (i <= 1 || j < i)) {
          Float w = prob(i, j, rest);
          A[j][i] += w;
          A[j + BAR + 1][i + BAR + 1] += w;
          A[j + BAR + 1][i] += w * j;
        }
      }
      return A;
    };
    if (N > BAR) {
      B = make_matrix(BAR + 1).power_with(N - BAR, B);
      N = BAR;
    }
    for (; N > 0; --N) {
      B = make_matrix(N) * B;
    }
    Float result = 0.0;
    for (int i = 0; i <= BAR; ++i) {
      result += B[i + BAR + 1][0];
    }
    printf("%.13f\n", (double)result);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

