/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef IROHA_BLOCK_PUBLISHER_HPP
#define IROHA_BLOCK_PUBLISHER_HPP

#include <memory>
#include <block.pb.h>
#include <endpoint.pb.h>
#include <endpoint.grpc.pb.h>

namespace network {

    /*
     * Send confirmed block to other server without Iroha,
     * This is only interface
     */
    class BlockPublisherClient{

        virtual iroha::protocol::ApiResponse sendBlock(
          const iroha::protocol::Block& block,
          const std::string& targetIp
        ) = 0;

    };

}  // namespace consensus


#endif //IROHA_BLOCK_PUBLISHER_HPP