#include "Time.h"

Time* Time::GetInstance()
{
	static Time* instance = new Time();
	return instance;
}

int Time::GetMilisCountFromStart()
{
	long long curr = wxGetLocalTimeMillis().GetValue();

	return (int)(curr - _startedAt);
}

Time::Time()
{
	_startedAt = wxGetLocalTimeMillis().GetValue();
}