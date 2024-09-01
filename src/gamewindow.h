#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "window.h"

class Button;

class GameWindow : public Window
{
public:
	GameWindow(const unsigned int& width, const unsigned int& height, const std::string& window_title = std::string(""));
	virtual void processSelfEvent(CallbackEvent* event) override;

private:
	Button* button;
};

#endif // GAMEWINDOW_H
