#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
	Event() = default;
	Event(const Event& other) = delete;
	virtual ~Event();
};


#endif // EVENT_H
