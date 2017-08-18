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

#ifndef SELFEA_MATERIAL_ISOTROPIC_H_
#define SELFEA_MATERIAL_ISOTROPIC_H_

#include <string>

#include "selfea/config.hpp"
#include "selfea/material/material.hpp"

namespace selfea { namespace material {


class Isotropic : public Material {
public:
    Isotropic();
    Isotropic(const std::string name, const Real_t p1, const Real_t p2,
	      const Real_t density=0.0);

    const Real_t& get_elastic_modulus() const { return E_; };
    const Real_t& get_poissons_ratio() const { return nu_; };

private:
    Real_t E_;
    Real_t nu_;
};


}}  // namespace selfea::material

#endif  // SELFEA_MATERIAL_ISOTROPIC_H_
