#include "randomWorkers.h"
#include <random>
#include <chrono>
AllWorkers createRandomWorkers(int number_of_workers)
{
	AllWorkers AllWorkers;
	for (int i = 0; i < number_of_workers; i++)
	{
		AllWorkers.addWorker(i, getRandomRating());
	}
	return AllWorkers;
}

int getRandomRating()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, 10);
	return distribution(generator);
}


