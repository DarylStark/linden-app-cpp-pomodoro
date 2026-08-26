#include "app.hpp"

#include <linden/graphics.hpp>
#include <linden/math.hpp>
#include <linden/system.hpp>

namespace pomodoro::app
{
    App::App(uint32_t width, uint32_t height)
        : _window(sf::VideoMode({width, height}), "Pomodoro"),
          _transitionManager(_clock)
    {
        _window.setFramerateLimit(60);
        _windowBackground = sf::Color(80, 0, 0);
    }

    void App::_setUpBoxes()
    {
        using namespace std::chrono_literals;
        using namespace linden::graphics;
        using namespace pomodoro::core;
        using namespace linden::math;

        std::unordered_map<TimeBoxType, sf::Color> colors;
        colors[TimeBoxType::Break] = sf::Color(0, 128, 0);
        colors[TimeBoxType::Work] = sf::Color(192, 0, 0);

        const auto &timeboxes = _pomodoro.getTimeBoxes();

        // Clear the current boxes
        _timeBoxes.clear();
        _timeBoxes.reserve(timeboxes.size());

        for (size_t idx = 0; idx < timeboxes.size(); ++idx)
        {
            const auto &box = timeboxes[idx];

            auto rect = sf::RectangleShape({100.f, 80.f});
            rect.setOrigin({50.f, 40.f});
            rect.setFillColor(sf::Color::Transparent);
            rect.setPosition({33.f + 50.f + (idx * (110.f + 11.f)), 640.0f});
            rect.setOutlineColor(colors[box.type]);
            rect.setOutlineThickness(-5);

            // Add it to the vector
            _timeBoxes.emplace_back(PomodoroTimeBox{timeboxes[idx], rect});

            // Intro transition
            _transitionManager.addTransition<CallbackTransitionUs>(
                easing::outElastic, 1250ms, [this, idx](float n)
                { _timeBoxes[idx].shape.setScale({n, n}); },
                500ms + idx * 20ms);
        }
    }

    void App::_handleEvents()
    {
        while (const std::optional event = _window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                _window.close();
            }
        }
    }

    void App::_drawBoxes()
    {
        for (const auto &box : _timeBoxes)
        {
            _window.draw(box.shape);
        }
    }

    void App::_mainLoop()
    {
        while (_window.isOpen())
        {
            _handleEvents();

            // Do all transitions
            _transitionManager.updateAll();

            // Clear the window
            _window.clear(sf::Color(_windowBackground));

            // Draw the needed boxes
            _drawBoxes();

            _window.display();
        }
    }

    int App::main()
    {
        // Box connection
        _setUpBoxes();

        // Main loop
        _mainLoop();

        return 0;
    }
} // namespace pomodoro::app