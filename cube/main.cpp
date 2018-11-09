#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;

class MyShape: public Shape
{
    public:
    MyShape(float radius = 0, std::size_t pointCount = 30):
        m_radius    (radius),
        m_pointCount(pointCount)
    {
        update();
    }
    Vector2f getPoint(std::size_t index) const
    {
        float pi = 3.141592654f;

        float angle = index * 2 * pi / m_pointCount - pi / 2;
        std::cout <<index <<std::endl;
        float x = std::cos(angle) * m_radius;
        float y = std::sin(angle) * m_radius;

        return Vector2f(m_radius + x, m_radius + y);
    }
    void setPointCount(std::size_t count)
    {
        m_pointCount = count;
        update();
    }
    std::size_t getPointCount() const
{
    return m_pointCount;
}
    private:
    float       m_radius;     ///< Radius of the circle
    std::size_t m_pointCount; ///< Number of points composing the circle
};
int main()
{
    // Create the main window
    ContextSettings ctx;
    ctx.antialiasingLevel = 8;
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window", Style::Default, ctx);
    int cosp=20;
    // Load a sprite to display
    CircleShape sp[cosp];
    for(int i=0; i<cosp; i++)
        sp[i]=CircleShape(10, 4);
    for(int i=0; i<cosp; i++)
    {
        sp[i].setFillColor(Color::Green);
        sp[i].setRotation(45);
        sp[i].setPosition(150+30*i, 300);

//        sp[i].
    }
    int p=0;
    while (app.isOpen())
    {
        // Process events
        if(p%100>=50)
        {
            for(int i=0; i<cosp; i++)
            {
          //  std::cout << sp[i].getPosition().x<< std::endl;
            sp[i].move(0, (float)i/4+1);
            }
        }
        else
        {
            for(int i=0; i<cosp; i++)
            {
          //  std::cout << sp[i].getPosition().x<< std::endl;
            sp[i].move(0, -(float)i/4-1);
            }
        }
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();
        for(int i=0; i<cosp; i++)
        {
            app.draw(sp[i]);
        }
        // Draw the sprite
        // Update the window
//        MyShape ms(50);
//        ms.setFillColor(Color::White);
//        ms.setPosition(50,500);
//        //ms.setPointCount(128);
//      ms.setScale(2,2);
//        app.draw(ms);
        app.display();
       // sleep(milliseconds(5));
        p++;
    }

    return EXIT_SUCCESS;
}
