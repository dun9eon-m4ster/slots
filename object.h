#ifndef OBJECT_H
#define OBJECT_H

class Event;

class Object
{
public:
	virtual ~Object();
	virtual void handleEvent(Event *event) = 0;
};

#endif // OBJECT_H
