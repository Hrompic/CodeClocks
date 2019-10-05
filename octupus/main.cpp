#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define SPEED 500.f
using namespace sf;
class octupus
{
private:
    Sprite octp;
    Texture tex;
    RenderWindow * wnd;
    Vector2f mpos;
    void move();
    bool moved;
    Clock clock;
    float speed;
    float delta;
public:
    octupus(RenderWindow* _wnd);
    void draw();
    void mmove();

};

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(1200, 800), "Octupus", Style::Fullscreen);
    octupus oct(&app);
    Texture tx;
    tx.loadFromFile("Water.jpg");
    Sprite bg(tx);
  //  Clock clock;

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            else if(event.type == Event::KeyPressed)
                if(event.key.code == Keyboard::Q)
                    app.close();
            if(event.type == Event::TouchBegan)
                oct.mmove();
        }

        app.clear(Color::Blue);
        app.draw(bg);
        oct.draw();
        app.display();
    }

    return EXIT_SUCCESS;
}

octupus::octupus(RenderWindow* _wnd)
: wnd(_wnd)
{
    tex.loadFromFile("octopus.png");
    octp.setTexture(tex);
    octp.setTextureRect(IntRect(0, 0, 144, 168));
    octp.setScale(0.4, 0.4);
    octp.setPosition(wnd->getSize().x/2, wnd->getSize().y/2);
    octp.setOrigin(octp.getGlobalBounds().width*1.2, octp.getGlobalBounds().height*1.2);
    moved = 0;
    speed = SPEED;
    //octp.rotate();
}

void octupus::mmove()
{
    mpos = wnd->mapPixelToCoords(Touch::getPosition(0));
    moved = true;
}

void octupus::draw()
{
    delta = clock.restart().asSeconds();
    if(moved)
    {
        move();
    }
    wnd->draw(octp);
}

void octupus::move()
{
    static float i;
    static float res = 0.75;
    Vector2f pos = mpos;
    Vector2f cpos = octp.getPosition();

    float dst = sqrt((pos.x-cpos.x)*(pos.x-cpos.x) + (pos.y-cpos.y)*(pos.y-cpos.y));
    static float tdst = dst;
    if(dst < 2)
    {
        speed = SPEED;
        i = 0;
        res = 0.75;
        moved = false;
    }
    pos.x = (pos.x-cpos.x)/dst*delta*speed;
    pos.y = (pos.y-cpos.y)/dst*delta*speed;
    speed -= i;
    i += res;
    if(speed < 10)
    {
        speed = SPEED;
        i=0;
        std::cout <<tdst-dst <<std::endl;
//        if(dst < 50)
//            speed = SPEED/2;
//            res = 0;
    }
   // std::cout <<pos.x <<" - " <<pos.y <<" - " <<dst <<std::endl;

    octp.move(pos);

}

