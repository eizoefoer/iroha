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

#ifndef IROHA_CONSENSUS_HPP
#define IROHA_CONSENSUS_HPP

#include <consensus.grpc.pb.h>
#include <atomic>
#include <model/converters/pb_transaction_factory.hpp>
#include <peer_service/peer_service.hpp>
#include "model/model_crypto_provider.hpp"
#include "network/consensus_gate.hpp"

namespace consensus {

  namespace role {
    class Member;
  }

  // TODO: change all this so that consensus does not know about transmission
  // protocol or data format.
  class Consensus : public proto::Sumeragi::Service,
                    public iroha::network::ConsensusGate {
   public:
    /** **/
    Consensus(peerservice::PeerServiceImpl& chain,
              iroha::model::ModelCryptoProvider& crypto_provider);
    void vote(iroha::model::Block block) override;
    rxcpp::observable<iroha::model::Block> on_commit() override;
    void on_next(iroha::model::Block&& block);

   public:
    /** GRPC SERVICE IMPLEMENTATION **/
    virtual grpc::Status SendProposal(grpc::ServerContext* context,
                                      const proto::Proposal* request,
                                      proto::Void* response) override;

    virtual grpc::Status SendVote(grpc::ServerContext* context,
                                  const proto::Vote* request,
                                  proto::Void* response) override;

    virtual grpc::Status SendCommit(grpc::ServerContext* context,
                                    const proto::Commit* request,
                                    proto::Void* response) override;

    virtual grpc::Status SendAbort(grpc::ServerContext* context,
                                   const proto::Abort* request,
                                   proto::Void* response) override;
    // view = the order of peers
    // any peer can request current view of other peer
    virtual grpc::Status GetView(grpc::ServerContext* context,
                                 const proto::Void* request,
                                 proto::View* response) override;

    // leader can set view for the cluster
    virtual grpc::Status SetView(grpc::ServerContext* context,
                                 const proto::View* request,
                                 proto::Void* response) override;

   private:
    /** order or peers **/
    peerservice::PeerServiceImpl& chain_;

    /** current state  (idle, busy) **/
    std::atomic<bool> round_started;

    /** and role (member, validator, leader, proxy_tail) **/
    std::unique_ptr<role::Member> role_;

    /** to verify messages */
    iroha::model::ModelCryptoProvider& crypto_provider_;

    iroha::model::converters::PbTransactionFactory tx_factory_;

    rxcpp::subjects::subject<iroha::model::Block> commits_;
  };
}

#endif  // IROHA_CONSENSUS_HPP
