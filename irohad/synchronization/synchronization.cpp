/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//
// Created by Takumi Yamashita on 2017/04/28.
//

#include <datetime/time.hpp>
#include <synchronization/synchronization.hpp>

//#include <ametsuchi/ametsuchi.hpp>

namespace iroha {
  namespace synchronization {

    // When commit block after consensus, invoke this function
    void Synchronizer::trigger(const Block &commited_block) {
      /* TODO
      if in the case synced
        if You could add commited block at the end of my block-chain.
          Continue without doing anything
        else
          Change state of my peer to unsynced
          To issue transaction that changes state of my peer to unsynced
      if in the case unsynced
        if You could add commited block at the end of my block-chain.
          Change state of my peer to synced
          To issue transaction that changes state of my peer to synced
          Call exit() of StreamingSyncSystem
        else
          if StreamingSyncSystem is running
            Continue without doing anything
          else
            Call startSync() of StreamingSyncSystem
            At this time, synced peer is specified fromsigns of commited block.
       */
    }

    void Synchronizer::startSync(const Block &commited_block) {
      /* TODO
       std::string ip = getSurviveIpFromSign(commited_block);
       std::uint64_t offset = Ametsuchi.Top().height();

       thread.start(syncObserve(offset));
       thread.start(fetchBlock( ip, offset ));
      */
    }

    void Synchronizer::fetchBlock(std::string ip, uint64_t offset) {
      // Invoke SyncClient
      /*
      client_.fetchBlocks(ip,offset)subscribe(
        [&](Block &block) { this->temp_block_.emplace(std::move(block)); };
      );
       */
    }

    void Synchronizer::syncObserve(uint64_t offset) {
      clearCache();
      current_ = offset;
      while (true /*iroha::demon::self::getStatus()==UnSynced*/) {
        if (temp_block_.empty()) {
          if (iroha::time::now64() - upd_time_ > 2) break;
          continue;
        }
        auto &ap_tx = temp_block_.top();
        // ametsuchi::append(ap_tx);
        // ametsuchi::commit();
        current_++;
        upd_time_ = iroha::time::now64();
      }
      clearCache();
    }

    void Synchronizer::exit() {
      // kill thread syncObserve
      // kill thread fetchBlock
    }

    void Synchronizer::clearCache() {
      while (temp_block_.empty()) temp_block_.pop();
      upd_time_ = iroha::time::now64();
      current_ = 0;
    }

  }  // namespace synchronization
}  // namespace iorha}  // namespace peer