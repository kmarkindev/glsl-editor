#pragma once

#include <wx/wx.h>

class Time
{
public:

	static Time* GetInstance();

	int GetMilisCountFromStart();

	Time(Time& other) = delete;
	void operator=(const Time&) = delete;

private:

	long long _startedAt;

	Time();

};