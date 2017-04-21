// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ACCOUNT_IROHA_H_
#define FLATBUFFERS_GENERATED_ACCOUNT_IROHA_H_

#include "flatbuffers/flatbuffers.h"

#include "asset_generated.h"
#include "primitives_generated.h"

namespace iroha {

struct Account;

struct Message;

struct Account FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PUBKEY = 4,
    VT_ALIAS = 6,
    VT_SIGNATORIES = 8,
    VT_USEKEYS = 10
  };
  const flatbuffers::String *pubKey() const {
    return GetPointer<const flatbuffers::String *>(VT_PUBKEY);
  }
  flatbuffers::String *mutable_pubKey() {
    return GetPointer<flatbuffers::String *>(VT_PUBKEY);
  }
  const flatbuffers::String *alias() const {
    return GetPointer<const flatbuffers::String *>(VT_ALIAS);
  }
  flatbuffers::String *mutable_alias() {
    return GetPointer<flatbuffers::String *>(VT_ALIAS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *signatories() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_SIGNATORIES);
  }
  flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *mutable_signatories() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_SIGNATORIES);
  }
  uint16_t useKeys() const {
    return GetField<uint16_t>(VT_USEKEYS, 1);
  }
  bool mutate_useKeys(uint16_t _useKeys) {
    return SetField<uint16_t>(VT_USEKEYS, _useKeys, 1);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_PUBKEY) &&
           verifier.Verify(pubKey()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_ALIAS) &&
           verifier.Verify(alias()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SIGNATORIES) &&
           verifier.Verify(signatories()) &&
           verifier.VerifyVectorOfStrings(signatories()) &&
           VerifyField<uint16_t>(verifier, VT_USEKEYS) &&
           verifier.EndTable();
  }
};

struct AccountBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pubKey(flatbuffers::Offset<flatbuffers::String> pubKey) {
    fbb_.AddOffset(Account::VT_PUBKEY, pubKey);
  }
  void add_alias(flatbuffers::Offset<flatbuffers::String> alias) {
    fbb_.AddOffset(Account::VT_ALIAS, alias);
  }
  void add_signatories(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> signatories) {
    fbb_.AddOffset(Account::VT_SIGNATORIES, signatories);
  }
  void add_useKeys(uint16_t useKeys) {
    fbb_.AddElement<uint16_t>(Account::VT_USEKEYS, useKeys, 1);
  }
  AccountBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AccountBuilder &operator=(const AccountBuilder &);
  flatbuffers::Offset<Account> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<Account>(end);
    fbb_.Required(o, Account::VT_PUBKEY);
    return o;
  }
};

inline flatbuffers::Offset<Account> CreateAccount(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> pubKey = 0,
    flatbuffers::Offset<flatbuffers::String> alias = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> signatories = 0,
    uint16_t useKeys = 1) {
  AccountBuilder builder_(_fbb);
  builder_.add_signatories(signatories);
  builder_.add_alias(alias);
  builder_.add_pubKey(pubKey);
  builder_.add_useKeys(useKeys);
  return builder_.Finish();
}

inline flatbuffers::Offset<Account> CreateAccountDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *pubKey = nullptr,
    const char *alias = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *signatories = nullptr,
    uint16_t useKeys = 1) {
  return iroha::CreateAccount(
      _fbb,
      pubKey ? _fbb.CreateString(pubKey) : 0,
      alias ? _fbb.CreateString(alias) : 0,
      signatories ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*signatories) : 0,
      useKeys);
}

struct Message FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ACCPUBKEY = 4,
    VT_DATA = 6
  };
  const flatbuffers::String *accPubKey() const {
    return GetPointer<const flatbuffers::String *>(VT_ACCPUBKEY);
  }
  flatbuffers::String *mutable_accPubKey() {
    return GetPointer<flatbuffers::String *>(VT_ACCPUBKEY);
  }
  const flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>> *data() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>> *>(VT_DATA);
  }
  flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>> *mutable_data() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_ACCPUBKEY) &&
           verifier.Verify(accPubKey()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DATA) &&
           verifier.Verify(data()) &&
           verifier.VerifyVectorOfTables(data()) &&
           verifier.EndTable();
  }
};

struct MessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_accPubKey(flatbuffers::Offset<flatbuffers::String> accPubKey) {
    fbb_.AddOffset(Message::VT_ACCPUBKEY, accPubKey);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>>> data) {
    fbb_.AddOffset(Message::VT_DATA, data);
  }
  MessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MessageBuilder &operator=(const MessageBuilder &);
  flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Message>(end);
    fbb_.Required(o, Message::VT_ACCPUBKEY);
    return o;
  }
};

inline flatbuffers::Offset<Message> CreateMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> accPubKey = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::KeyValueObject>>> data = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_accPubKey(accPubKey);
  return builder_.Finish();
}

inline flatbuffers::Offset<Message> CreateMessageDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *accPubKey = nullptr,
    const std::vector<flatbuffers::Offset<iroha::KeyValueObject>> *data = nullptr) {
  return iroha::CreateMessage(
      _fbb,
      accPubKey ? _fbb.CreateString(accPubKey) : 0,
      data ? _fbb.CreateVector<flatbuffers::Offset<iroha::KeyValueObject>>(*data) : 0);
}

}  // namespace iroha

#endif  // FLATBUFFERS_GENERATED_ACCOUNT_IROHA_H_