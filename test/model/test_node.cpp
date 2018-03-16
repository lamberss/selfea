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

#include "selfea/model/node.hpp"

#include <initializer_list>
#include <stdexcept>
#include <vector>

#include <gtest/gtest.h>


TEST(NodeTest, ConstructorDefault) {
    selfea::model::Node n;
    std::vector<Real_t> expected{0.0, 0.0, 0.0};
    EXPECT_EQ(expected, n.coordinates());
}


TEST(NodeTest, ConstructorInitializerList) {
    selfea::model::Node n{1.0, 2.4, -3.2};
    std::vector<Real_t> expected{1.0, 2.4, -3.2};
    EXPECT_EQ(expected, n.coordinates());
}


TEST(NodeTest, ConstructorInitializerListBig) {
    std::initializer_list<Real_t> l = {1.0, 2.0, 3.0, 4.0};
    EXPECT_THROW(selfea::model::Node n = l, std::range_error);
}


TEST(NodeTest, ConstructorInitializerListSmall) {
    selfea::model::Node n{1.0, -3.2};
    std::vector<Real_t> expected{1.0, -3.2, 0.0};
    EXPECT_EQ(expected, n.coordinates());
}


TEST(NodeTest, ConstructorThreeReals) {
    selfea::model::Node n(1.0, 2.4, -3.2);
    std::vector<Real_t> expected{1.0, 2.4, -3.2};
    EXPECT_EQ(expected, n.coordinates());
}
