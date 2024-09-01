#ifndef BUTTONCLICKEVENT_H
#define BUTTONCLICKEVENT_H

#include "callbackevent.h"

class Button;

class ButtonClickEvent : public CallbackEvent
{
public:
	ButtonClickEvent(Button *button);
};

#endif // BUTTONCLICKEVENT_H
