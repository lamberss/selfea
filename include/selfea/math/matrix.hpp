// Copyright 2017 Steven E. Lamberson, Jr. <steven.lamberson@gmail.com>
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

#include <cstddef>
#include <vector>

#include "selfea/config.hpp"

namespace selfea { namespace math {


class Matrix {
public:
    Matrix();
    Matrix(const std::size_t num_rows, const std::size_t num_cols=0,
	   const Real_t value=0.0);

    Real_t& operator()(const std::size_t i, const std::size_t j);
    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator+=(const Real_t& rhs);
    friend Matrix operator+(Matrix lhs, const Matrix& rhs) { lhs+=rhs; return lhs; }
    friend Matrix operator+(Matrix lhs, const Real_t& rhs) { lhs+=rhs; return lhs; }

private:
    std::size_t num_cols_;
    std::size_t num_rows_;
    std::vector<Real_t> matrix_;
};


}}  // namespace selfea::math

#endif  // SELFEA_MATH_MATRIX_H_
