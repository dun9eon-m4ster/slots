#include "callbackevent.h"

CallbackEvent::CallbackEvent(Object* _new_caller)
	: _caller(_new_caller)
{
}

Object* CallbackEvent::caller()
{
	return _caller;
}
