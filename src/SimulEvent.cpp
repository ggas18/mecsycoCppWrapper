
#include "SimulEvent.h"

using namespace std;
using namespace mecsyco;

// Creation

SimulEvent::SimulEvent(SimulDataPtr aData, double aTime) :
	time(aTime),
	data(aData)
{}

SimulEvent::SimulEvent(double aTime) :
	time(aTime),
	data(nullptr)
{}

// Derivation

SimulEventPtr SimulEvent::withData(SimulDataPtr aData) const {
	SimulEventPtr result(new SimulEvent(aData, time));
	return result;
}

SimulEventPtr SimulEvent::withTime(double aTime) const {
	SimulEventPtr result(new SimulEvent(data, aTime));
	return result;
}

// Access
double SimulEvent::getTime() const {
	return time;
}

SimulDataPtr SimulEvent::getData() const {
	return data;
}
