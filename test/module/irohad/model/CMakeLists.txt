# Copyright 2017 Soramitsu Co., Ltd.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

addtest(command_converter_test converters/pb_commands_test.cpp)
target_link_libraries(command_converter_test
    model
    )

addtest(transaction_converter_test converters/pb_transaction_test.cpp)
target_link_libraries(transaction_converter_test
    model
    )

addtest(block_converter_test converters/pb_block_test.cpp)
target_link_libraries(block_converter_test
    model
    )

addtest(model_operators_test operators/model_operators_test.cpp)
target_link_libraries(model_operators_test
    model
    )