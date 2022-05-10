#pragma once
#include "Socket.h"


class MyServer
{

public:
	MyServer();
	~MyServer();

	void StartServer();
	void MainCycle();
	
private:


	MySocket msoc;
	
};