#pragma once
#include "allClients.h"
class Machine
{
public:
	Machine(int _id);
	void ChangeMachineOccupacy();
	void ChangeTimeToChangeClient(int i, int serviceTime);
	virtual void ProvideSevice(shared_ptr<Client> client, shared_ptr <Worker> worker);
	bool GetIsTaken();
	int GetTimeToChangeClient();
private:
	int id;
	bool isTaken = false;
	int timeToChangeClient=0;
};
