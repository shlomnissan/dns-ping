// Copyright 2022 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <string>
#include <limits>
#include <cstdint>
#include <gtest/gtest.h>

#include "common/buffer.h"
#include "common/exception.h"

using namespace std;
using namespace Common;

TEST(DnsLookupBuffer, ThrowsExceptionBufferOutOfRange) {
    auto size { numeric_limits<uint16_t>::max() };
    string data(size, ' ');

    Buffer buffer {};
    buffer.write(data.c_str(), size);

    EXPECT_THROW({
        buffer.write(data.c_str(), 1);
    }, Common::BufferOutOfRange);
}