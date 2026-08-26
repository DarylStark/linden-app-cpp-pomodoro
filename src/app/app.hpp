#pragma once

#include <SFML/Graphics.hpp>
#include <linden/graphics/timed_transition_manager.hpp>
#include <pomodoro.hpp>
#include <vector>

namespace pomodoro::app
{
    struct PomodoroTimeBox
    {
        const pomodoro::core::TimeBox &timebox;
        sf::RectangleShape shape;
    };

    class App
    {
    private:
        // SFML attributes
        sf::RenderWindow _window;
        sf::Color _windowBackground;

        // Timing
        linden::system::StlClockUs _clock;
        linden::graphics::TimedTransitionManagerUs _transitionManager;

        // Backend
        pomodoro::core::Pomodoro _pomodoro;

        // Elements
        std::vector<PomodoroTimeBox> _timeBoxes;

        // Set up operations
        void _setUpBoxes();

        // Loop operations
        void _handleEvents();
        void _drawBoxes();
        void _mainLoop();

    public:
        App(uint32_t width, uint32_t height);
        int main();
    };
} // namespace pomodoro::app