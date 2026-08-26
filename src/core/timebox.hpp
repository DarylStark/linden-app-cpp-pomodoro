#pragma once

#include <chrono>

namespace pomodoro::core
{
    enum class TimeBoxType
    {
        Break,
        Work
    };

    struct TimeBox
    {
        std::chrono::seconds duration;
        TimeBoxType type;
    };
} // namespace pomodoro::core