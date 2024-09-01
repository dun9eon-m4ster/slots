#ifndef FPSEVENT_H
#define FPSEVENT_H

#include "event.h"

class FpsEvent : public Event
{
public:
	FpsEvent(size_t _new_count);
	size_t count() const;

private:
	size_t _count;
};

#endif // FPSEVENT_H
