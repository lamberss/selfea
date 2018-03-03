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

#include "selfea/material/material.hpp"

#include <gtest/gtest.h>


TEST(MaterialTest, ConstructorDefault) {
    selfea::material::Material m;
    EXPECT_EQ("", m.get_name());
    EXPECT_EQ(0.0, m.get_density());
}


TEST(MaterialTest, ConstructorName) {
    std::string material_name("aluminum");
    const Real_t density = 0.05;
    selfea::material::Material m(material_name, density);
    EXPECT_EQ(material_name, m.get_name());
    EXPECT_EQ(density, m.get_density());
}
