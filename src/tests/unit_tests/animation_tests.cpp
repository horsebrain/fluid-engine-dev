// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <jet/animation.h>
#include <gtest/gtest.h>

using namespace jet;

TEST(Frame, Constructors) {
    Frame frame;
    EXPECT_EQ(0u, frame.index);
    EXPECT_DOUBLE_EQ(1.0 / 60.0, frame.timeIntervalInSeconds);
}

TEST(Frame, TimeInSeconds) {
    Frame frame;

    frame.index = 180;

    EXPECT_DOUBLE_EQ(3.0, frame.timeInSeconds());
}

TEST(Frame, Advance) {
    Frame frame;

    frame.index = 45;

    for (int i = 0; i < 9; ++i) {
        frame.advance();
    }

    EXPECT_EQ(54u, frame.index);

    frame.advance(23);

    EXPECT_EQ(77u, frame.index);

    EXPECT_EQ(78u, (++frame).index);

    EXPECT_EQ(78u, (frame++).index);

    EXPECT_EQ(79u, frame.index);
}