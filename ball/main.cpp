#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>
    int height = 800, width = 600;
using namespace sf;
class Circle
{
private:
    int x,y;
    RenderWindow * wnd;
    CircleShape circ;
    int _speed;
    float angle;
public:
    Circle(RenderWindow * _wnd, int size = 10)
    {
        wnd = _wnd;
        circ.setRadius(size);
        circ.setFillColor(Color::Green);
        circ.setPosition(rand()%width,rand()%height);
        _speed =3;

    }
    void draw()
    {
            do
        {
            angle = (rand() % 360) * 2 * M_PI / 360;
        }
        while (abs(cos(angle)) < 0.7f);
       // if(circ.getPosition().x < height-circ.getRadius()&&circ.getPosition().y <width-circ.getRadius())
            circ.move(cos(angle),sin(angle));
        wnd->draw(circ);
    }
};
int main()
{
    // Create the main window
    srand(time(0));
    sf::RenderWindow app(sf::VideoMode(height, width), "SFML window");
    app.setVerticalSyncEnabled(true);
    // Load a sprite to display
    sf::Texture texture;
    Font font;
    if(!font.loadFromFile("C:\\Windows\\Fonts\\segoepr.ttf"))
        return EXIT_FAILURE;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    Text text;
    text.setFont(font);
    text.setString("Simple text");
    text.setFillColor(Color::Black);
	// Start the game loop
	Circle crl(&app);
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))

        {
            // Close window : exit
        switch (event.type)
        {

            case Event::KeyPressed:
                switch(event.key.code)
                {
                    case Keyboard::Z:
                    case Keyboard::Q:
                        app.close(); break;
                    default: break;
                }
            case Event::Closed:
                app.close();
            default: break;
        }
        }

        // Clear screen
        app.clear(Color::White);
        crl.draw();
        app.draw(text);
        app.display();
    }

    return EXIT_SUCCESS;
}
