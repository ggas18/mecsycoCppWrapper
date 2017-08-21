/*
 * @author jvaubourg
 * @author nkirchner
 * @author Victorien Elvinger
 */

#ifndef TUPLE1_H_
#define TUPLE1_H_

#define WIN32_LEAN_AND_MEAN
#include <sstream>

#include <boost/foreach.hpp>


#include "Tuple0.h"
#include "Json.h"
#include "UnsupportedJsonException.h"

namespace mecsyco {

	/**
	 * Template class representing data
	 * Default implementation is made for int, double, std::string and bool)
	 * When inheriting this class, you don't have anything special to do.
	 * Just define any constructor, setter or getter you need and reeimplement any method you want.
	 */
	template<typename T> class Tuple1 :public Tuple0 {
	protected: // Implementation
		T item1;

	public: // Creation
		/**
		 * 1) Empty constructor is mandatory.
		 * 2) Getter and setter are mandatory for each variable.
		 */
		explicit Tuple1(): Tuple0() {}

		explicit Tuple1(T data);

	public: // Access
		virtual T getItem1() const;

		virtual int count () const;

	protected: // Debugging
		virtual std::string innerToString() const;

	public: // json
		virtual void toJson(mecsyco::Json& json) const;
		virtual void loadFromJson(mecsyco::Json& json);

	};

	template<typename T>
	using Tuple1Ptr = std::shared_ptr<Tuple1<T>>;

	template<typename T>
	Tuple1<T>::Tuple1(T aItem1): Tuple0(), item1(aItem1) {}

// Access
	template<typename T>
	T Tuple1<T>::getItem1() const {
		return this->item1;
	}

	template<typename T>
	int Tuple1<T>::count() const {
		return 1;
	}

// Debugging
	template<typename T>
	std::string Tuple1<T>::innerToString() const {
		std::stringstream ss;
		ss << this->item1;

		return ss.str();
	}

// Json
	template<typename T> void Tuple1<T>::toJson(Json& aJson) const {
		aJson.add("item1", item1);
	}

	template<typename T> void Tuple1<T>::loadFromJson(Json& aJson) {
		aJson.get("item1", item1);
	}

}


#endif
