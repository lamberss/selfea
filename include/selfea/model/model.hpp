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

#ifndef SELFEA_MODEL_MODEL_H_
#define SELFEA_MODEL_MODEL_H_

#include "selfea/config.hpp"
#include "selfea/model/node.hpp"

#include <map>

namespace selfea { namespace model {


class Model {
public:
    void addNode(Id_t id, Real_t x=0.0, Real_t y=0.0, Real_t z=0.0);
    Node& node(Id_t id) { return nodes_[id]; } 
    Id_t numberOfNodes() { return nodes_.size(); }

private:
    std::map<Id_t, Node> nodes_;
};


}  // namespace model
}  // namespace selfea

#endif  // SELFEA_MODEL_MODEL_H_
