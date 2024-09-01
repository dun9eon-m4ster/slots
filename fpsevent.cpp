#include "fpsevent.h"

FpsEvent::FpsEvent(size_t _new_count)
	: _count(_new_count)
{
}

size_t FpsEvent::count() const
{
	return _count;
}
