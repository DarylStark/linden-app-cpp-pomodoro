#pragma once

#include "timebox.hpp"
#include <linden/system/clock.hpp>
#include <vector>

namespace pomodoro::core
{
    enum class PomodoroStatus
    {
        Pending,
        Started,
        Paused
    };

    class Pomodoro
    {
    private:
        std::vector<TimeBox> _timeBoxes;
        PomodoroStatus _status;
        linden::system::StlClock<std::chrono::seconds> _clock;

    public:
        Pomodoro() noexcept;

        // Data retrieval
        const std::vector<TimeBox> &getTimeBoxes() const noexcept;
        const std::optional<uint32_t> getActiveBox() const noexcept;
        const PomodoroStatus getStatus() const noexcept;

        // Operations
        void start() noexcept;
        void pause() noexcept;
        void stop() noexcept;
    };
} // namespace pomodoro::core