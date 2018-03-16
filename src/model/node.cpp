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
#include <sstream>
#include <stdexcept>

namespace selfea { namespace model {

const unsigned int nDim = 3;

Node::Node() : xyz_(nDim) {}


Node::Node(std::initializer_list<Real_t> l) : xyz_(nDim)
{
    if (l.size() > nDim)
    {
        std::stringstream msg("");
        msg << "Initializing Node with too many coordinates (" << l.size() << ")";
        throw std::range_error(msg.str());
    }
    unsigned int i = 0;
    for (auto&& li: l)
    {
        xyz_[i++] = li;
    }
}

Node::Node(Real_t x, Real_t y, Real_t z) : xyz_{x, y, z} {}


}  // namespace model
}  // namespace selfea
