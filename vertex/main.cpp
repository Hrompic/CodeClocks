#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/OpenGL.hpp>
using namespace sf;
int main()
{
    srand(time(NULL));
    VertexArray triangl(Triangles,3);
    triangl[0].position = Vector2f(10, 10);
    triangl[1].position = Vector2f(550, 10);
    triangl[2].position = Vector2f(150, 450);
    for(int i=0; i<3; i++)
        triangl[i].color = Color(rand()%255, rand()%255, rand()%255);
    RenderWindow app(VideoMode(800, 600), "My window");
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            else if(event.type == Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

    //  app.clear();
      app.draw(triangl);
     // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      app.display();
    }

    return EXIT_SUCCESS;
}
