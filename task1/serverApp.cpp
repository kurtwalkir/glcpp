#include <iostream>
#include "inc/server.h"
#include "inc/serverException.h"

int main(int argc, char *argv[])
{

	Server *obj = new Server();
	try
	{
		obj->run();
	}
	catch(serverException &ex)
	{
		ex.display();
	}
	delete obj;
}