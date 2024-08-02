#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

struct Flight {
    std::vector<sf::Vector2f> path;
};

void drawFlightPaths(sf::RenderWindow& window, const std::vector<Flight>& flights) {
    for (const auto& flight : flights) {
        sf::VertexArray line(sf::LinesStrip, flight.path.size());
        for (size_t i = 0; i < flight.path.size(); ++i) {
            line[i].position = flight.path[i];
            line[i].color = sf::Color::White; // Set color for flight path
        }
        window.draw(line);
    }
}

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flight Paths");

    // Define flight paths
    std::vector<Flight> flights = {
        { { {100, 100}, {200, 200}, {300, 300} } }, // Flight 1
        { { {100, 100}, {200, 400}, {300, 200} } }, // Flight 2
        { { {100, 100}, {400, 200}, {300, 400} } }  // Flight 3
    };

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // Clear the window with black color
        drawFlightPaths(window, flights); // Draw flight paths
        window.display(); // Display the contents of the window
    }

    return 0;
}


//Resource
/*https://www.sfml-dev.org/download.php
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
https://www.sfml-dev.org/tutorials/2.5/
https://en.cppreference.com/w/
https://en.sfml-dev.org/forums/
https://github.com/SFML/SFML*/
