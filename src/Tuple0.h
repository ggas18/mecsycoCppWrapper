/*
 * @author jvaubourg
 * @author nkirchner
 * @author Victorien Elvinger
 */

#ifndef TUPLE0_H_
#define TUPLE0_H_

#define WIN32_LEAN_AND_MEAN
#include <boost/foreach.hpp>
#include <ostream>

#include "SimulData.h"
#include "Json.h"
#include "UnsupportedJsonException.h"
// les strings c++11
typedef std::__cxx11::string string;

namespace mecsyco {

	class Tuple0;
	typedef std::shared_ptr<Tuple0> Tuple0Ptr;


	class Tuple0 :public SimulData {
	public: // Constant
		static Tuple0 Instance;

	public: // Creation
		explicit Tuple0() {}

	public: // Access
		/**
		 * @return Item count.
		 */
		virtual int count () const;

	public: // Debugging
        virtual string toString() const;

		std::ostream& operator<< (std::ostream& stream) const;

	protected:
		/**
		 *
		 * @return Representation of current without enclosing characters.
		 */
		virtual std::string innerToString() const;

	public: // Json
		virtual void toJson(mecsyco::Json& aJson) const;
		virtual void loadFromJson(mecsyco::Json& aJson);

	};

}


#endif
