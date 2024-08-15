#include "NegativeServiceTime.h"
#include <string>

NegativeServiceTime::NegativeServiceTime(int wrong_service_time) :
	std::invalid_argument("Negative value of the service time" + std::to_string(wrong_service_time)) {}