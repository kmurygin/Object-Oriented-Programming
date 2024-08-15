#include "randomData.h"
#include <random>
#include <chrono>
int RandomValueToPayment(int max_balance)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, max_balance);
	return distribution(generator);
}

int RandomTimeToHandle(int worker_rating)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(2, (20 - worker_rating));
	return distribution(generator);
}

int RandomClientId(int max_clients)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(0, (max_clients));
	return distribution(generator);
}

int RandomDurationMonth()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(0, 24);
	return distribution(generator);
}

int RandomInterestRate()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(0, 5);
	return distribution(generator);
}
