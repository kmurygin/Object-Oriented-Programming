#pragma once
#include <stdexcept>

class NegativeServiceTime : public std::invalid_argument
{
public:
	NegativeServiceTime(int wrong_service_time);
};