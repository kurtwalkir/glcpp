#include <iostream>
#include "inc/server.h"

int main(int argc, char *argv[])
{

	Server *obj = new Server();
	obj->run();
	delete obj;
}