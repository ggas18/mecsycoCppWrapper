#ifndef GENERICMODELARTEFACT_H_
#define GENERICMODELARTEFACT_H_

#include "SimulEvent.h"
#include <string.h>

// les strings c++11
typedef std::__cxx11::string string;

namespace mecsyco {
/**
 * This interface represents a model-artefact.
 */
class ModelArtifact {
public:

	/**
	 * Process the model's internal event at the corresponding simulation time
	 * @param the simulation time of the internal event to be processed (may be useful only with pure DEVS formalism simulator)
	 */
	virtual void processInternalEvent(double time) = 0;

	/**
	 * Return the time of the next event to be processed
	 * @return Time of the next event
	 */
	virtual double getNextInternalEventTime() = 0;

	/**
	 * Return the time of the last event to have been processed
	 *
	 * @deprecated Planned to be removed. (2015 May)
	 *
	 * @return Time of the last event
	 */
	virtual double getLastEventTime() = 0;

	/**
	 * Set the model input event into the corresponding port.
	 * @param event the external event
	 * @param port the port where the event has to be send
	 */
    virtual void processExternalInputEvent(SimulEventPtr event, string port) = 0;

	/**
	 * Get the model output event (to exchange with another model)
	 * @param port the model output port where data has to be collected
	 * @return the model event for the port
	 */
    virtual SimulEventPtr getExternalOutputEvent(string port) = 0;

	/**
	 * Create a simulator instance, load
	 * the model and initiate it.
	 */
	virtual void initialize() = 0;

	/**
	 * Do something when simulation is done
	 */
	virtual void finishSimulation() = 0;

	/**
	 * Set the initial parameters.
	 * @param args the initial parameters
	 */
	virtual void setInitialParameters(char** args) = 0;
};
}

#endif
