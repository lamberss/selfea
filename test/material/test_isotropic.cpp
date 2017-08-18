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

#include "selfea/material/isotropic.hpp"

#include <gtest/gtest.h>


TEST(MaterialIsotropicTest, ConstructorDefault) {
    selfea::material::Isotropic m;
    EXPECT_EQ("", m.get_name());
    EXPECT_EQ(0.0, m.get_density());
    EXPECT_EQ(0.0, m.get_elastic_modulus());
    EXPECT_EQ(0.0, m.get_poissons_ratio());
}


TEST(MaterialIsotropicTest, ConstructorFull) {
    std::string material_name("aluminum");
    const Real_t density = 2700.0;
    const Real_t E = 68.9e9;
    const Real_t nu = 0.33;
    selfea::material::Isotropic m(material_name, E, nu, density);
    EXPECT_EQ(material_name, m.get_name());
    EXPECT_EQ(density, m.get_density());
    EXPECT_EQ(E, m.get_elastic_modulus());
    EXPECT_EQ(nu, m.get_poissons_ratio());
}
