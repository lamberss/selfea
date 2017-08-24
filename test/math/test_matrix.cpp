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

#include "selfea/math/matrix.hpp"

#include <sstream>

#include <gtest/gtest.h>


TEST(MathMatrixTest, ConstructorDefault) {
    ASSERT_NO_THROW(selfea::math::Matrix m);
}


TEST(MathMatrixTest, ConstructorSquare) {
    const int m = 5;
    const int n = m;
    selfea::math::Matrix A(m);
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }
}


TEST(MathMatrixTest, ConstructorValue) {
    const int m = 3;
    const int n = 5;
    const Real_t v = -0.87;
    selfea::math::Matrix A(m, n, v);
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(v, A(i,j));
	}
    }
}


TEST(MathMatrixTest, AssignElement) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    const Real_t v2 = 1.49;
    const int I = 2;
    const int J = 4;
    selfea::math::Matrix A(m, n, v1);
    A(I,J) = v2;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    if (I == i && J == j)
	    {
		EXPECT_EQ(v2, A(i,j));
	    }
	    else
	    {
		EXPECT_EQ(v1, A(i,j));
	    }
	}
    }
}


TEST(MathMatrixTest, AccessorColumnOutOfBounds) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    selfea::math::Matrix A(m, n, v1);
#ifndef NDEBUG
    // In "Debug" mode we do bounds checking on the accessor.
    std::stringstream msg("");
    msg << "column index '" << n << "' out of bounds [0," << n-1 << "]";
    EXPECT_THROW(
	{
	    try
	    {
		A(m-1,n);
	    }
	    catch ( const std::range_error& e )
	    {
		EXPECT_EQ(msg.str(), e.what());
		throw;
	    }
	},
	std::range_error);
#else // ifndef NDEBUG
    // In "Release" mode we do not do bounds checking on the accessor.
    EXPECT_NE(v1, A(m-1,n));
#endif // ifndef NDEBUG
}


TEST(MathMatrixTest, AccessorRowOutOfBounds) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    selfea::math::Matrix A(m, n, v1);
#ifndef NDEBUG
    // In "Debug" mode we do bounds checking on the accessor.
    std::stringstream msg("");
    msg << "row index '" << m << "' out of bounds [0," << m-1 << "]";
    EXPECT_THROW(
	{
	    try
	    {
		A(m,n-1);
	    }
	    catch ( const std::range_error& e )
	    {
		EXPECT_EQ(msg.str(), e.what());
		throw;
	    }
	},
	std::range_error);
#else // ifndef NDEBUG
    // In "Release" mode we do not do bounds checking on the accessor.
    EXPECT_NE(v1, A(m,n-1));
#endif // ifndef NDEBUG
}


TEST(MathMatrixTest, Minus) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, v1);
    selfea::math::Matrix C(m, m, v1);
    selfea::math::Matrix D(m, n);

    D = A - B;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(0.0, D(i,j));
	}
    }

    D = A - B - v2;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(-v2, D(i,j));
	}
    }

    EXPECT_THROW( D = A - C, std::length_error );
}


TEST(MathMatrixTest, MinusEqual) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, v1);
    selfea::math::Matrix C(m, m, v1);

    A -= B;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }

    A -= v2;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(-v2, A(i,j));
	}
    }

    EXPECT_THROW( A -= C, std::length_error );
}


TEST(MathMatrixTest, Plus) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, -v1);
    selfea::math::Matrix C(m, m, v1);
    selfea::math::Matrix D(m, n);

    D = A + B;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(0.0, D(i,j));
	}
    }

    D = A + B + v2;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(v2, D(i,j));
	}
    }

    EXPECT_THROW( D = A + C, std::length_error );
}


TEST(MathMatrixTest, PlusEqual) {
    const int m = 3;
    const int n = 5;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, -v1);
    selfea::math::Matrix C(m, m, v1);

    A += B;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }

    A += v2;
    for (auto i=0; i<m; ++i)
    {
	for (auto j=0; j<n; ++j)
	{
	    EXPECT_EQ(v2, A(i,j));
	}
    }

    EXPECT_THROW( A += C, std::length_error );
}
