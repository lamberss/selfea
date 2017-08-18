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

#include <algorithm>

namespace selfea { namespace material {


Isotropic::Isotropic() : Material(), E_(0.0), nu_(0.0) {}

Isotropic::Isotropic(const std::string name, const Real_t p1, const Real_t p2,
		     const Real_t density) :
    Material(name, density), E_(p1), nu_(p2) {}


}}  // namespace selfea::material
