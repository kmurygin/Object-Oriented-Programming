#include "randomClients.h"
#include <random>
#include <chrono>
AllClients createRandomClients(int number_of_private_clients, int number_of_bussines_clients)
{
	AllClients allClients;
	int k;
	for (k = 0; k < number_of_bussines_clients; k++)
	{
		Account account = Account(getRandomAccountNumber(), getRandomAccountBalance());
		allClients.addBusinessClient(k, account);
	}
	for (k = number_of_bussines_clients; k  < number_of_bussines_clients + number_of_private_clients; k++)
	{
		Account account = Account(getRandomAccountNumber(), getRandomAccountBalance());
		allClients.addPrivateClient(k, account);
	}
	return allClients;
}

int getRandomAccountNumber()
{
	int accountNumber=0;
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(1, 9);
	// Generacja 6 cyfrowego numeru konta
	for (int i = 0; i < 6; i++)
	{
		accountNumber *= 10;
		accountNumber += distribution(generator);
	}
	return accountNumber;
}

int getRandomAccountBalance()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(0, 1000000);
	return distribution(generator);
}
