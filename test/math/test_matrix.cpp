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

#include "selfea/math/matrix.hpp"

#include <sstream>

#include <gtest/gtest.h>


TEST(MathMatrixTest, ConstructorDefault) {
    ASSERT_NO_THROW(selfea::math::Matrix m);
}


TEST(MathMatrixTest, ConstructorInitializerList) {
    const unsigned int m = 3u;
    const unsigned int n = 1u;
    selfea::math::Matrix A = {1.0, 2.0, 3.0};

    EXPECT_EQ(m, A.rows());
    EXPECT_EQ(n, A.cols());
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(static_cast<Real_t>(i+1), A(i,j));
	}
    }
}


TEST(MathMatrixTest, ConstructorSquare) {
    const unsigned int m = 5u;
    const unsigned int n = m;
    selfea::math::Matrix A(m);
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }
}


TEST(MathMatrixTest, ConstructorValue) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v = -0.87;
    selfea::math::Matrix A(m, n, v);
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(v, A(i,j));
	}
    }
}


TEST(MathMatrixTest, AssignElement) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v1 = -0.87;
    const Real_t v2 = 1.49;
    const unsigned int I = 2u;
    const unsigned int J = 4u;
    selfea::math::Matrix A(m, n, v1);
    A(I,J) = v2;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
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
    const unsigned int m = 3u;
    const unsigned int n = 5u;
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
    const unsigned int m = 3u;
    const unsigned int n = 5u;
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


TEST(MathMatrixTest, Compare) {
    selfea::math::Matrix A = { 1.0, 2.0, 3.0 };
    selfea::math::Matrix B = { 1.0, 2.0, 3.0 };
    selfea::math::Matrix C = { 1.0, 2.0, 5.0 };
    EXPECT_EQ(A, B);
    EXPECT_NE(A, C);
}


TEST(MathMatrixTest, Minus) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, v1);
    selfea::math::Matrix C(m, m, v1);
    selfea::math::Matrix D(m, n);

    D = A - B;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(0.0, D(i,j));
	}
    }

    D = A - B - v2;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(-v2, D(i,j));
	}
    }

    EXPECT_THROW( D = A - C, std::length_error );
}


TEST(MathMatrixTest, MinusEqual) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, v1);
    selfea::math::Matrix C(m, m, v1);

    A -= B;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }

    A -= v2;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(-v2, A(i,j));
	}
    }

    EXPECT_THROW( A -= C, std::length_error );
}


TEST(MathMatrixTest, Multiply) {
    const unsigned int m = 2u;
    const unsigned int n = 3u;
    selfea::math::Matrix A = { 1.0, 4.0, 2.0, 5.0, 3.0, 6.0 };
    selfea::math::Matrix B = { 7.0, 9.0, 11.0, 8.0, 10.0, 12.0 };
    selfea::math::Matrix C = { 58.0, 139.0, 64.0, 154.0 };

    A.reshape(m, n);
    B.reshape(n, m);
    C.reshape(m, m);

    selfea::math::Matrix D = A * B;
    EXPECT_EQ(C, D);

    const Real_t v = 2.0;
    for (auto i = 0u; i<m; ++i)
    {
	for ( auto j = 0u; j<m; ++j)
	{
	    C(i,j) = C(i,j) * v;
	}
    }
    selfea::math::Matrix E = v * D;
    EXPECT_EQ(C, E);

    EXPECT_THROW( A * C, std::length_error );
}


TEST(MathMatrixTest, Plus) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, -v1);
    selfea::math::Matrix C(m, m, v1);
    selfea::math::Matrix D(m, n);

    D = A + B;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(0.0, D(i,j));
	}
    }

    D = A + B + v2;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(v2, D(i,j));
	}
    }

    EXPECT_THROW( D = A + C, std::length_error );
}


TEST(MathMatrixTest, PlusEqual) {
    const unsigned int m = 3u;
    const unsigned int n = 5u;
    const Real_t v1 = -0.87;
    const Real_t v2 =  1.0;
    selfea::math::Matrix A(m, n, v1);
    selfea::math::Matrix B(m, n, -v1);
    selfea::math::Matrix C(m, m, v1);

    A += B;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(0.0, A(i,j));
	}
    }

    A += v2;
    for (auto i=0u; i<m; ++i)
    {
	for (auto j=0u; j<n; ++j)
	{
	    EXPECT_EQ(v2, A(i,j));
	}
    }

    EXPECT_THROW( A += C, std::length_error );
}


TEST(MathMatrixTest, Reshape) {
    selfea::math::Matrix A = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
    EXPECT_EQ(6u, A.rows());
    EXPECT_EQ(1u, A.cols());

    const unsigned int m = 2u;
    const unsigned int n = 3u;
    A.reshape(m, n);
    selfea::math::Matrix B(m, n);
    B(0,0) = 1.0; B(0,1) = 3.0; B(0,2) = 5.0;
    B(1,0) = 2.0; B(1,1) = 4.0; B(1,2) = 6.0;
    EXPECT_EQ(A, B);

    EXPECT_THROW(A.reshape(m+5,n), std::length_error);
}
