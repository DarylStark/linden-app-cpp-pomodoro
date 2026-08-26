#include "pomodoro.hpp"
#include <chrono>
#include <iostream>

namespace pomodoro::core
{
    Pomodoro::Pomodoro() noexcept : _status(PomodoroStatus::Pending)
    {
        using namespace std::chrono_literals;

        _clock.stop();

        _timeBoxes.emplace_back(TimeBox({25min, TimeBoxType::Work}));
        _timeBoxes.emplace_back(TimeBox({5min, TimeBoxType::Break}));
        _timeBoxes.emplace_back(TimeBox({25min, TimeBoxType::Work}));
        _timeBoxes.emplace_back(TimeBox({5min, TimeBoxType::Break}));
        _timeBoxes.emplace_back(TimeBox({25min, TimeBoxType::Work}));
        _timeBoxes.emplace_back(TimeBox({5min, TimeBoxType::Break}));
        _timeBoxes.emplace_back(TimeBox({25min, TimeBoxType::Work}));
        _timeBoxes.emplace_back(TimeBox({15min, TimeBoxType::Break}));
    }

    const std::vector<TimeBox> &Pomodoro::getTimeBoxes() const noexcept
    {
        return _timeBoxes;
    }

    const std::optional<uint32_t> Pomodoro::getActiveBox() const noexcept
    {
        return std::nullopt;
    }

    const PomodoroStatus Pomodoro::getStatus() const noexcept
    {
        return _status;
    }

    void Pomodoro::start() noexcept
    {
        _status = PomodoroStatus::Started;
    }

    void Pomodoro::pause() noexcept
    {
        _status = PomodoroStatus::Paused;
    }

    void Pomodoro::stop() noexcept
    {
        _status = PomodoroStatus::Pending;
    }
} // namespace pomodoro::core