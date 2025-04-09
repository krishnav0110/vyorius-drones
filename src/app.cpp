#include <iostream>
#include <thread>
#include <chrono>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm/ext.hpp>

#include "graphics/Renderer.hpp"

#include "Camera.hpp"
#include "Shape2d.hpp"
#include "Shape2dGenerator.hpp"
#include "Shape2dRenderer.hpp"

int main(int argv, char **args) {
    glm::ivec2 windowSize(768, 512);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    settings.minorVersion = 3;
    sf::Window window(sf::VideoMode(windowSize.x, windowSize.y), "ForestWalk", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setActive(true);

    if (GLEW_OK != glewInit()) {
        std::cout << "GLEW initialization failed";
        exit(1);
    }

    Camera camera(glm::radians(45.0f), (float)windowSize.x / windowSize.y, 0.1f, 10.0f);

    Shader shapeShader;
    shapeShader.LoadFromFile("shaders/shape.vert", "shaders/shape.frag");
    shapeShader.SetUniform("projection", camera.ProjectionMatrix());
    shapeShader.SetUniform("tex1", 0);

    Texture shapeTexture("res/tex/sample.png");

    uint8_t currentShapeIndex = 0;
    std::vector<Shape2d> shapes(3);

    Shape2dGenerator::generateTriangle(shapes.at(0).model, 0.5f);
    Shape2dGenerator::generateRectangle(shapes.at(1).model, 0.5f, 0.5f);
    Shape2dGenerator::generateCircle(shapes.at(2).model, 0.5f, 30);

    std::cout << "Change Shape: Space\n";
    std::cout << "Elevation: E(Up) / Q(Down)\n";
    std::cout << "Rotation: D(Clockwise) / A(AntiClockwise)\n";
    std::cout << "Scaling: W(Scale Up) / S(Scale Down)\n";

    bool running = true;
    float dt = 1.0f / 60.0f;
    float delta = 0.0;
    sf::Clock now;

    while (running) {
        sf::Time elapsedTime = now.restart();
        delta += elapsedTime.asSeconds();

        if (delta < dt) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            continue;
        }
        delta = 0.0f;

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                running = false;
                break;
            case sf::Event::Resized:
                glViewport(0, 0, event.size.width, event.size.height);
                break;
            case sf::Event::KeyPressed:
                Shape2d &shape = shapes.at(currentShapeIndex);
                if (event.key.code == sf::Keyboard::Space) {
                    currentShapeIndex = ++currentShapeIndex % static_cast<uint8_t>(shapes.size());
                }
                else if (event.key.code == sf::Keyboard::E) {
                    shape.IncreaseElevation(3.0f * dt);
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    shape.DecreaseElevation(3.0f * dt);
                }
                else if (event.key.code == sf::Keyboard::D) {
                    shape.DecreaseRotation(20.0f * dt);
                }
                else if (event.key.code == sf::Keyboard::A) {
                    shape.IncreaseRotation(20.0f * dt);
                }
                else if (event.key.code == sf::Keyboard::W) {
                    shape.IncreaseScale(2.0f * dt);
                }
                else if (event.key.code == sf::Keyboard::S) {
                    shape.DecreaseScale(2.0f * dt);
                }
                break;
            }
        }

        // rendering to the screen
        glClear(GL_COLOR_BUFFER_BIT);
        Shape2dRenderer::render(shapes.at(currentShapeIndex), shapeTexture, shapeShader);

        window.display();
    }

    return 0;
}