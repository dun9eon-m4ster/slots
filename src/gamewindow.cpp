#include "gamewindow.h"
#include "button.h"
#include "iostream"
#include "buttonclickevent.h"
#include "barrel.h"
#include "fpswidget.h"

struct BarrelInit
{
    BarrelInit(uint32_t s, uint32_t d)
        :   _s(s),
            _d(d)
    {
    }

    uint32_t _s;
    uint32_t _d;
};

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

    std::vector<BarrelInit> init_data;
    init_data.push_back(BarrelInit(30, 4000));
    init_data.push_back(BarrelInit(60, 4250));
    init_data.push_back(BarrelInit(50, 4500));
    init_data.push_back(BarrelInit(30, 4750));
    init_data.push_back(BarrelInit(70, 5000));

    for (Uint16 i = 0; i < init_data.size(); i++)
    {
        addObject(new Barrel(Rect(  padding_left + i * spacing + i * element_width,
                                    padding_top,
                                    element_width,
                                    element_height), 
            init_data.at(i)._s,
            init_data.at(i)._d));
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
