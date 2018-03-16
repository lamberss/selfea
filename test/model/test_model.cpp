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

#include "selfea/model/model.hpp"

#include <gtest/gtest.h>


TEST(ModelTest, ConstructorDefault) {
    selfea::model::Model m;
    EXPECT_EQ(0u, m.numberOfNodes());
}


TEST(ModelTest, AddNode) {
    const Id_t id = 1u;
    selfea::model::Model m;
    std::vector<Real_t> n{15.0, 14.0, 13.0};
    m.addNode(id, n[0], n[1], n[2]);
    EXPECT_EQ(1u, m.numberOfNodes());
    EXPECT_EQ(n, m.node(id).coordinates());
}
