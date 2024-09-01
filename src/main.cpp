#include "application.h"
#include "gamewindow.h"

int main(int argc, char* argv[])
{
    Application app;

    auto window = new GameWindow(1200, 800, std::string("Game"));

    app.setApplicationWindow(window);

    return app.exec();
}