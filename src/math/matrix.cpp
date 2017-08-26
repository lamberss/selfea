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

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace selfea { namespace math {


Matrix::Matrix() : num_cols_(0), num_rows_(0), matrix_(0)
{
}


Matrix::Matrix(std::initializer_list<Real_t> l)
    : num_cols_(1), num_rows_(l.size()), matrix_(l)
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


const Real_t& Matrix::operator()(const std::size_t i, const std::size_t j) const
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


bool Matrix::operator==(const Matrix& rhs) const
{
    bool same = true;
    same = same && (num_cols_ == rhs.num_cols_);
    same = same && (num_rows_ == rhs.num_rows_);
    if (same)
    {
	for (std::size_t i=0; i < num_rows_; ++i)
	{
	    for (std::size_t j=0; j < num_cols_; ++j)
	    {
		same = same && (*this)(i,j) == rhs(i,j);
	    }
	}
    }
    return same;
}


Matrix& Matrix::operator-=(const Real_t& rhs)
{
    for (std::size_t i = 0; i < num_rows_*num_cols_; i++)
    {
	matrix_[i] -= rhs;
    }
    return *this;
}


Matrix& Matrix::operator-=(const Matrix& rhs)
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
	matrix_[i] -= rhs.matrix_[i];
    }
    
    return *this;
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


Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
    const std::size_t m = lhs.rows();
    const std::size_t n = rhs.cols();
    const std::size_t p = lhs.cols();

    if ( lhs.cols() != rhs.rows() )
    {
	std::stringstream msg("");
	msg << "cannot multiply matrices with sizes";
	msg << lhs.rows() << "x" << lhs.cols() << " and ";
	msg << rhs.rows() << "x" << rhs.cols();
	throw std::length_error(msg.str());
    }

    Matrix result(m, n);
    for (std::size_t j = 0; j < n; ++j)
    {
	for (std::size_t i = 0; i < m; ++i)
	{
	    for (std::size_t k = 0; k < p; ++k)
	    {
		result(i,j) += lhs(i,k) * rhs(k,j);
	    }
	}
    }

    return result;
}


Matrix operator*(const Matrix& lhs, const Real_t& rhs)
{
    const std::size_t m = lhs.rows();
    const std::size_t n = lhs.cols();
    Matrix result(m, n);
    for (std::size_t j = 0; j < n; ++j)
    {
	for (std::size_t i = 0; i < m; ++i)
	{
	    result(i,j) = lhs(i,j) * rhs;
	}
    }
    return result;
}


void Matrix::reshape(const std::size_t i, const std::size_t j)
{
    if ( (i * j) != (num_rows_*num_cols_) ) 
    {
	std::stringstream msg("");
	msg << "Cannot reshape to (" << i << "," << j << ").";
	throw std::length_error(msg.str());
    }
    num_rows_ = i;
    num_cols_ = j;
}


}}  // namespace selfea::math
