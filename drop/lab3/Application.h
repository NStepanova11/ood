#pragma once
#include <iostream>

using namespace std;

class Application
{
private:
	static Application * p_instance;
	Application() {}
	Application(const Application&);
	Application& operator=(Application&);

public:
	static Application * getInstance() {
		if (!p_instance)
			p_instance = new Application();
		return p_instance;
	}
};

