/*
 * @author jvaubourg
 * @author nkirchner
 * @author Victorien Elvinger
 */

#ifndef SIMULDATA_H_
#define SIMULDATA_H_

#define WIN32_LEAN_AND_MEAN
#include <boost/foreach.hpp>
#include <list>

#include "Json.h"
#include "UnsupportedJsonException.h"

namespace mecsyco {

	class SimulData {
	public: // Debugging
		virtual std::string toString() const = 0;

	public: // json
		virtual std::string toJsonStr() const;
		virtual void loadFromJsonStr(std::string json);

		virtual void toJson(mecsyco::Json& json) const = 0;
		virtual void loadFromJson(mecsyco::Json& json) = 0;

	};

	typedef std::shared_ptr<SimulData> SimulDataPtr;

}


#endif
