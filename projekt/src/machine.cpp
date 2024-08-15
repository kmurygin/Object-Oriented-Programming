#include "machine.h"


Machine::Machine(int _id)
{
	id = _id;
}

void Machine::ChangeMachineOccupacy()
{
	isTaken = !isTaken;
}

void Machine::ChangeTimeToChangeClient(int i, int serviceTime)
{
	timeToChangeClient = i + serviceTime;
}

void Machine::ProvideSevice(shared_ptr<Client> client, shared_ptr <Worker> worker)
{
}

bool Machine::GetIsTaken()
{
	return isTaken;
}

int Machine::GetTimeToChangeClient()
{
	return timeToChangeClient;
}


