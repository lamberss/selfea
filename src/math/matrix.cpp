// Copyright 2016 Steven E. Lamberson, Jr. <steven.lamberson@gmail.com>
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

#include "selfea/math/matrix.hpp"

namespace selfea { namespace math {


Matrix::Matrix() : num_cols_(0), num_rows_(0), matrix_(0)
{
}


Matrix::Matrix(const std::size_t num_rows, const std::size_t num_cols,
	       const Real_t value)
    : num_cols_(num_cols), num_rows_(num_rows), matrix_(0)
{
    if (num_cols_ <= 0) num_cols_ = num_rows_;
    matrix_.resize(num_rows_ * num_cols_, value);
}


Real_t& Matrix::operator()(const std::size_t i, const std::size_t j)
{
    return matrix_[i*num_rows_ + j];
}


}}  // namespace selfea::math
