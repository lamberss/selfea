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

#ifndef SELFEA_MODEL_NODE_H_
#define SELFEA_MODEL_NODE_H_

#include <initializer_list>
#include <vector>

#include "selfea/config.hpp"

namespace selfea { namespace model {


class Node {
public:
    Node();
    Node(std::initializer_list<Real_t>);
    Node(Real_t x, Real_t y=0.0, Real_t z=0.0);

    std::vector<Real_t>& coordinates() { return xyz_; }
    const std::vector<Real_t>& coordinates() const { return xyz_; }

private:
    std::vector<Real_t> xyz_;
};


}  // namespace model
}  // namespace selfea

#endif  // SELFEA_MODEL_NODE_H_
