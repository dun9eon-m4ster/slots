#ifndef APPLICATION_H
#define APPLICATION_H

#include "memory"

class Window;

class Application
{
	enum class State
	{
		Waiting = 0,
		Running,
		Stopping
	};

public:
	Application();

	int exec();

private:
	int init();
	int mainEventLoop();
	void processEvents();
	void processRender();

	State application_state;
	std::shared_ptr<Window> application_window;
};



#endif // APPLICATION_H
