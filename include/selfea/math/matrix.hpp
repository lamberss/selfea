// Copyright 2018 Steven E. Lamberson, Jr. <steven.lamberson@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SELFEA_MATH_MATRIX_H_
#define SELFEA_MATH_MATRIX_H_

#include <initializer_list>
#include <vector>

#include "selfea/config.hpp"

namespace selfea { namespace math {


class Matrix {
public:
    Matrix();
    Matrix(std::initializer_list<Real_t> l);
    Matrix(std::size_t num_rows, std::size_t num_cols=0, Real_t value=0.0);

    Real_t& operator()(std::size_t i, std::size_t j);
    const Real_t& operator()(std::size_t i, std::size_t j) const;

    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const { return !(*this == rhs); }

    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator+=(const Real_t& rhs);
    // TODO: see if the below implementation makes too many copies.
    friend Matrix operator+(Matrix lhs, const Matrix& rhs)
    {
        lhs+=rhs;
        return lhs;
    }
    friend Matrix operator+(Matrix lhs, const Real_t& rhs)
    {
        lhs+=rhs;
        return lhs;
    }

    Matrix& operator-=(const Matrix& rhs);
    Matrix& operator-=(const Real_t& rhs);
    // TODO: see if the below implementation makes too many copies.
    friend Matrix operator-(Matrix lhs, const Matrix& rhs)
    {
        lhs-=rhs;
        return lhs;
    }
    friend Matrix operator-(Matrix lhs, const Real_t& rhs)
    {
        lhs-=rhs;
        return lhs;
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, const Real_t& rhs);
    friend Matrix operator*(const Real_t& lhs, const Matrix& rhs)
    {
        return rhs * lhs;
    }

    std::size_t cols() const { return num_cols_; }
    std::size_t rows() const { return num_rows_; }

    void reshape(std::size_t i, std::size_t j);

private:
    std::size_t num_cols_;
    std::size_t num_rows_;
    std::vector<Real_t> matrix_;
};


}  // namespace math
}  // namespace selfea

#endif  // SELFEA_MATH_MATRIX_H_
