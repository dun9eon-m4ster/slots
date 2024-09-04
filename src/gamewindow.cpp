#include "gamewindow.h"
#include "button.h"
#include "iostream"
#include "buttonclickevent.h"
#include "barrel.h"
#include "fpswidget.h"

GameWindow::GameWindow(const unsigned int& width, const unsigned int& height, const std::string& window_title)
	:	Window(width, height, window_title),
		button(new Button(Rect(500, 700, 200, 50)))
{
    addObject(button);
    addObject(new FpsWidget(Rect(5,height - 55, 200, 50)));

    int padding_top = 50;
    int padding_left = 50;
    int spacing = 20;
    int element_width = 200;
    int element_height = 600;

    for (Uint16 i = 0; i < 1; i++)
    {
        addObject(new Barrel(Rect(  padding_left + i * spacing + i * element_width,
                                    padding_top,
                                    element_width,
                                    element_height)));
    }
}

void GameWindow::processSelfEvent(CallbackEvent* event)
{
	if (auto button_click_event = dynamic_cast<ButtonClickEvent*>(event))
	{
		if (button != nullptr && button == button_click_event->caller())
		{
            notify(button_click_event);
		}
	}
}
