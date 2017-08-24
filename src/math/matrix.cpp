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

#include <sstream>
#include <stdexcept>

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
#ifndef NDEBUG
    // The Matrix accessor could be called many, many times, and therefore
    // the bounds checking will only be done when build in "Debug" mode.
    if (i >= num_rows_)
    {
	std::stringstream msg("");
	msg << "row index '" << i << "' out of bounds [0," << num_rows_-1 << "]";
	throw std::range_error(msg.str());
    }
    if (j >= num_cols_)
    {
	std::stringstream msg("");
	msg << "column index '" << j << "' out of bounds [0," << num_cols_-1 << "]";
	throw std::range_error(msg.str());
    }
#endif // ifndef NDEBUG
    return matrix_[i + j*num_rows_];
}


Matrix& Matrix::operator+=(const Real_t& rhs)
{
    for (std::size_t i = 0; i < num_rows_*num_cols_; i++)
    {
	matrix_[i] += rhs;
    }
    return *this;
}


Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if ( num_rows_ != rhs.num_rows_ || num_cols_ != rhs.num_cols_ )
    {
	std::stringstream msg("");
	msg << "lhs and rhs matrices incompatible sizes: ";
	msg << num_rows_ << "x" << num_cols_ << " != ";
	msg << rhs.num_rows_ << "x" << rhs.num_cols_;
	throw std::length_error(msg.str());
    }

    for (std::size_t i = 0; i < num_rows_*num_cols_; i++)
    {
	matrix_[i] += rhs.matrix_[i];
    }
    
    return *this;
}


}}  // namespace selfea::math
