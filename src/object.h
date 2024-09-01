#ifndef OBJECT_H
#define OBJECT_H

#include "vector"

class Event;
class CallbackEvent;


class Object
{
public:
	virtual ~Object();
	virtual void handleEvent(Event *event) = 0;
};

#endif // OBJECT_H
