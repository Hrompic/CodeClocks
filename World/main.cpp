#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
enum moves{up, down, left, right};
Clock t = Clock();
int Height = 600;
int Width = 780;
class Bot
{
private:
    RectangleShape body;
    static const int size = 12;
    void mv(moves mv)
    {
      switch(mv)
        {
        case left:
            body.move(-size, 0); break;
        case right:
            body.move(size, 0); break;
        case up:
            body.move(0, -size); break;
        case down:
            body.move(0, size); break;
          // body.setPosition(body.getPosition().x, body.getPosition().y+size);
        }
    }
protected:
    Vector2f pos;
public:
    Bot()
    {
        body.setSize(Vector2f(size,size));
        body.setFillColor(Color::Green);
        body.setPosition(24*10, 24*10);
        body.setOutlineThickness(1);
        body.setOutlineColor(Color::Black);
    }
        Bot(int posx, int posy)
    {
        body.setSize(Vector2f(size,size));
        body.setFillColor(Color::Green);
        body.setPosition(posx, posy);
        body.setOutlineThickness(1);
        body.setOutlineColor(Color::Black);
    }
    void draw(RenderWindow *wnd)
    {
        wnd->draw(body);
        std::cout <<body.getPosition().x <<' ' <<body.getPosition().y <<' ' <<t.getElapsedTime().asMilliseconds() <<std::endl;
    }
    void move(moves mo)
    {
      //  mo = (moves)(rand()%4);
        if(mo==up)
        {

           if(!(body.getPosition().y>0)) {body.setPosition(body.getPosition().x,Height); return;}
            mv(mo);
        }
        else if(mo==down)
        {
            if(!(body.getPosition().y<Height-size)){body.setPosition(body.getPosition().x,0); return;}
            mv(mo);
        }
        else if(mo==left)
        {
            if(!(body.getPosition().x>=0)){body.setPosition(Width, body.getPosition().y); return;}
            mv(mo);
        }
        else if(mo==right)
        {
            if(!(body.getPosition().x<Width)){body.setPosition(0, body.getPosition().y); return;}
            mv(mo);
        }
        //mv();
    }

};
class World
{
private:
    Bot *bots;
    Bot bot;
    RenderWindow *wnd;
    int height;
    int width;
    int maxbot;
public:
    World(RenderWindow *_wnd, int _height, int _width):
        wnd(_wnd),
        height(_height),
        width(_width)
    {
        maxbot = width*height;
        bots = new Bot[50];
    }
//    void lines()
//    {
//        for(int i=0; i<width/Bot::size; i++)
//        {
//            wnd.d
//        }
// sf::Vertex vertices[] =
// {
//     sf::Vertex(sf::Vector2f(  0,   0), sf::Color::Blue, sf::Vector2f( 0,  Height)),
//     sf::Vertex(sf::Vector2f(  100, 100), sf::Color::Green, sf::Vector2f( 0, 10)),
//     sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red, sf::Vector2f(10, 10)),
//     sf::Vertex(sf::Vector2f(100,   0), sf::Color::Red, sf::Vector2f(10,  0))
// };
//
//  draw it
// wnd->draw(vertices, 2, sf::Lines);
//    }
    void draw()
    {
//        if(Keyboard::isKeyPressed(Keyboard::Right))
//            bot.move(right);
//        else if(Keyboard::isKeyPressed(Keyboard::Up))
//            bot.move(up);
//        else if(Keyboard::isKeyPressed(Keyboard::Down))
//            bot.move(down);
//        else if(Keyboard::isKeyPressed(Keyboard::Left))
//            bot.move(left);
        //for(int i=0; i<100; i++)
            bot.move(right);
            bot.move(down);
        bot.draw(wnd);
    }
};
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(Width, Height), "SFML window");
    World wr(&app, 100, 100);
	// Start the game loop;
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
                        app.close();
                    default: break;
                } break;
            case Event::Closed:
                app.close();
            default: break;
        }
        }
        app.clear(Color::White);
        wr.draw();
       // wr.lines();
        app.display();
        sleep(milliseconds(100));
    }

    return EXIT_SUCCESS;
}
