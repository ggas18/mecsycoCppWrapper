/*
 * @author bcamus, jvaubourg
 *
 */

#ifndef SIMULEVENT_H_
#define SIMULEVENT_H_

#include "SimulData.h"

#include <iostream>
#include "Json.h"

namespace mecsyco {

	class SimulEvent;
	typedef std::shared_ptr<SimulEvent> SimulEventPtr;

	/*
	 * Represent an external event exchanged between models.
	 *
	 * @author bcamus
	 * @author jvaubourg
	 * @author Victorien Elvinger
	 *
	 */
	class SimulEvent {
	private:
		/**
		 * SimulEvent::getTime()
		 */
		double time;

		/**
		 * SimulEvent::getData()
		 */
		SimulDataPtr data;

	public: // Creation
		/**
		 * @param aData
		 *        SimulEvent::getData()
		 * @param aTime
		 *        SimulEvent::getTime()
		 */
		SimulEvent(SimulDataPtr aData, double aTime);

		/**
		 * Create an event without data.
		 *
		 * @param aTime
		 *        SimulEvent::getTime()
		 */
		explicit SimulEvent(double aTime);

	public: // Derivation
		/**
		 *
		 * @param aData
		 * @return Event with `aData' as data and SimulEvent::getTime() as time.
		 */
		SimulEventPtr withData(SimulDataPtr aData) const;

		/**
		 *
		 * @param aTime
		 * @return Event with `aTime' as time and SimulEvent::getData() as data.
		 */
		SimulEventPtr withTime(double aTime) const;

	public: // Access
		/**
		 * @return time-stamp of the event.
		 */
		double getTime() const;

		/**
		 * @return events's data.
		 */
		SimulDataPtr getData() const;

	};
}

#endif
