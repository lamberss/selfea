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
