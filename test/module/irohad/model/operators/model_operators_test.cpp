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

#include <gtest/gtest.h>
#include <model/model_hash_provider_impl.hpp>
#include "model/block.hpp"
#include "model/commands/add_asset_quantity.hpp"
#include "model/commands/add_peer.hpp"
#include "model/commands/add_signatory.hpp"
#include "model/commands/assign_master_key.hpp"
#include "model/commands/create_account.hpp"
#include "model/commands/create_asset.hpp"
#include "model/commands/create_domain.hpp"
#include "model/commands/remove_signatory.hpp"
#include "model/commands/set_permissions.hpp"
#include "model/commands/set_quorum.hpp"
#include "model/commands/transfer_asset.hpp"
#include "model/transaction.hpp"

using namespace iroha::model;

// -----|AddPeer|-----

AddPeer createAddPeer() {
  AddPeer addPeer;
  addPeer.address = "localhost";
  std::fill(addPeer.peer_key.begin(), addPeer.peer_key.end(), 0x1);
  return addPeer;
}

TEST(ModelOperatorTest, AddPeerTest) {
  AddPeer first = createAddPeer();
  AddPeer second = createAddPeer();
  ASSERT_EQ(first, second);
  second.address = "127.0.0.1";
  ASSERT_NE(first, second);
}

// -----|AddAssetQuantity|-----

AddAssetQuantity createAddAssetQuantity() {
  AddAssetQuantity aaq;
  aaq.account_id = "123";
  aaq.amount.int_part = 10;
  aaq.amount.frac_part = 10;
  aaq.asset_id = "123";
  return aaq;
}

TEST(ModelOperatorTest, AddAssetQuantityTest) {
  auto first = createAddAssetQuantity();
  auto second = createAddAssetQuantity();

  ASSERT_EQ(first, second);
  second.asset_id = "22";
  ASSERT_NE(first, second);
}

// -----|AddSignatory|-----

AddSignatory createAddSignatory() {
  AddSignatory add_signatory;
  add_signatory.account_id = "123";
  std::fill(add_signatory.pubkey.begin(), add_signatory.pubkey.end(), 0x23);
  return add_signatory;
}

TEST(ModelOperatorTest, AddSignatoryTest) {
  auto first = createAddSignatory();
  auto second = createAddSignatory();

  ASSERT_EQ(first, second);
  second.account_id = "22";
  ASSERT_NE(first, second);
}

// -----|AssignMasterKey|-----

AssignMasterKey createAssignMasterKey() {
  AssignMasterKey assignMasterKey;
  assignMasterKey.account_id = "123";
  std::fill(assignMasterKey.pubkey.begin(), assignMasterKey.pubkey.end(), 0x23);
  return assignMasterKey;
}

TEST(ModelOperatorTest, AssignMasterKeyTest) {
  auto first = createAssignMasterKey();
  auto second = createAssignMasterKey();

  ASSERT_EQ(first, second);
  second.account_id = "22";
  ASSERT_NE(first, second);
}

// -----|CreateAccount|-----

CreateAccount createCreateAccount() {
  CreateAccount createAccount;
  createAccount.domain_id = "123";
  createAccount.account_name = "kek";
  std::fill(createAccount.pubkey.begin(), createAccount.pubkey.end(), 0x23);
  return createAccount;
}

TEST(ModelOperatorTest, CreateAccountTest) {
  auto first = createCreateAccount();
  auto second = createCreateAccount();

  ASSERT_EQ(first, second);
  second.account_name = "cheburek";
  ASSERT_NE(first, second);
}

// -----|CreateAsset|-----

CreateAsset createCreateAsset() {
  CreateAsset createAsset;
  createAsset.domain_id = "localhost";
  createAsset.asset_name = "rub";
  createAsset.precision = 2;
  return createAsset;
}

TEST(ModelOperatorTest, CreateAssetTest) {
  auto first = createCreateAsset();
  auto second = createCreateAsset();

  ASSERT_EQ(first, second);
  second.asset_name = "usd";
  ASSERT_NE(first, second);
}

// -----|CreateDomain|-----

CreateDomain createCreateDomain() {
  CreateDomain createDomain;
  createDomain.domain_name = "rus";
  return createDomain;
}

TEST(ModelOperatorTest, CreateDomainTest) {
  auto first = createCreateDomain();
  auto second = createCreateDomain();

  ASSERT_EQ(first, second);
  second.domain_name = "jp";
  ASSERT_NE(first, second);
}

// -----|RemoveSignatory|-----

RemoveSignatory createRemoveSignatory() {
  RemoveSignatory removeSignatory;
  removeSignatory.account_id = "123";
  std::fill(removeSignatory.pubkey.begin(), removeSignatory.pubkey.end(), 0x23);
  return removeSignatory;
}

TEST(ModelOperatorTest, RemoveSignatoryTest) {
  auto first = createRemoveSignatory();
  auto second = createRemoveSignatory();

  ASSERT_EQ(first, second);
  second.account_id = "22";
  ASSERT_NE(first, second);
}

// -----|SetAccountPermissions|-----

SetAccountPermissions createSetAccountPermissions() {
  SetAccountPermissions setAccountPermissions;
  setAccountPermissions.account_id = "123";
  setAccountPermissions.new_permissions.set_quorum = true;
  return setAccountPermissions;
}

TEST(ModelOperatorTest, SetAccountPermissionsTest) {
  auto first = createSetAccountPermissions();
  auto second = createSetAccountPermissions();
  ASSERT_EQ(first, second);
  second.account_id = "22";
  ASSERT_NE(first, second);
}

// -----|SetQuorum|-----

SetQuorum createSetQuorum() {
  SetQuorum setQuorum;
  setQuorum.account_id = "123";
  setQuorum.new_quorum = 23;
  return setQuorum;
}

TEST(ModelOperatorTest, SetQuorumTest) {
  auto first = createSetQuorum();
  auto second = createSetQuorum();

  ASSERT_EQ(first, second);
  second.account_id = "22";
  ASSERT_NE(first, second);
}

// -----|TransferAsset|-----

TransferAsset createTransferAsset() {
  TransferAsset transferAsset;
  transferAsset.asset_id = "123";
  transferAsset.amount.int_part = 10;
  transferAsset.amount.frac_part = 10;
  transferAsset.src_account_id = "1";
  transferAsset.dest_account_id = "2";
  return transferAsset;
}

TEST(ModelOperatorTest, TransferAssetTest) {
  auto first = createTransferAsset();
  auto second = createTransferAsset();

  ASSERT_EQ(first, second);
  second.asset_id = "22";
  ASSERT_NE(first, second);
}

// -----|Amount|-----

TEST(ModelOperatorTest, AmountTest) {
  iroha::Amount amount1;
  amount1.int_part = 10;
  amount1.frac_part = 10;

  iroha::Amount amount2;
  amount2.int_part = 10;
  amount2.frac_part = 10;

  ASSERT_EQ(amount1, amount2);
  amount2.frac_part = 11;
  ASSERT_NE(amount1, amount2);
}

// -----|Signature|-----

Signature createSignature() {
  Signature sig{};
  std::fill(sig.pubkey.begin(), sig.pubkey.end(), 0x1);
  std::fill(sig.signature.begin(), sig.signature.end(), 0x1);
  return sig;
}

TEST(ModelOperatorTest, SignatureTest) {
  auto sig1 = createSignature();
  auto sig2 = createSignature();

  ASSERT_EQ(sig1, sig2);
  sig1.signature[0] = 0x23;
  ASSERT_NE(sig1, sig2);
}

// -----|Transaction|-----

Transaction createTransaction() {
  Transaction transaction;
  transaction.created_ts = 1;
  transaction.creator_account_id = "132";
  transaction.tx_counter = 5;
  transaction.signatures.push_back(createSignature());

  // commands
  transaction.commands.push_back(
      std::make_shared<AddAssetQuantity>(createAddAssetQuantity()));
  transaction.commands.push_back(std::make_shared<AddPeer>(createAddPeer()));
  transaction.commands.push_back(
      std::make_shared<AddSignatory>(createAddSignatory()));
  transaction.commands.push_back(
      std::make_shared<AssignMasterKey>(createAssignMasterKey()));
  transaction.commands.push_back(
      std::make_shared<CreateAccount>(createCreateAccount()));
  transaction.commands.push_back(
      std::make_shared<CreateAsset>(createCreateAsset()));
  transaction.commands.push_back(
      std::make_shared<CreateDomain>(createCreateDomain()));
  transaction.commands.push_back(
      std::make_shared<RemoveSignatory>(createRemoveSignatory()));
  transaction.commands.push_back(
      std::make_shared<SetAccountPermissions>(createSetAccountPermissions()));
  transaction.commands.push_back(
      std::make_shared<TransferAsset>(createTransferAsset()));
  return transaction;
}

TEST(ModelOperatorTest, TransactionTest) {
  auto tx1 = createTransaction();
  auto tx2 = createTransaction();

  ASSERT_EQ(tx1, tx2);
  tx1.signatures.push_back(createSignature());
  ASSERT_NE(tx1, tx2);
}

// -----|Block|-----

Block createBlock(){
  Block block;
  block.created_ts = 1;
  block.txs_number = 2;
  std::fill(block.prev_hash.begin(), block.prev_hash.end(), 0x23);
  std::fill(block.merkle_root.begin(), block.merkle_root.end(), 0x23);
  block.sigs.push_back(createSignature());
  block.transactions.push_back(createTransaction());
  block.height = 123;

  HashProviderImpl hashProvider;
  block.hash = hashProvider.get_hash(block);
  return block;
}

TEST(ModelOperatorTest, BlockTest) {
  auto first = createBlock();
  auto second = createBlock();

  ASSERT_EQ(first, second);
  second.height += 1;
  ASSERT_NE(first, second);
}