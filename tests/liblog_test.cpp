// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest

#include <gtest/gtest.h>

namespace Everest {
namespace Logging {

class LibLogUnitTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(LibLogUnitTest, test_truth) {
    ASSERT_TRUE(1==1);
}

}
}