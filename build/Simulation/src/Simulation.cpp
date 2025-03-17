#include "SIDT.h"


class Simulation : public SIDT::Application
{
public:
	Simulation() {}
	~Simulation() {}
};

SIDT::Application* SIDT::CreateApplication()
{
	return new Simulation();
}