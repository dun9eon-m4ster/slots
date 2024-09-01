#ifndef CALLBACKEVENT_H
#define CALLBACKEVENT_H

#include "event.h"

class Object;

class CallbackEvent : public Event
{
public:
	CallbackEvent(Object *_new_caller);
	Object* caller();

private:
	Object* _caller;
};


#endif // CALLBACKEVENT_H
