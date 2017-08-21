/*
 * @author Victorien Elvinger
 *
 */

#ifndef UNSUPPORTEDJSONEXCEPTION_H_
#define UNSUPPORTEDJSONEXCEPTION_H_

#include <stdexcept>
#include <typeinfo>

namespace mecsyco {

	template<typename T>
	class UnsupportedJsonException : public std::runtime_error {
	public: // Creation
		explicit UnsupportedJsonException();

	};

	template<typename T>
	UnsupportedJsonException<T>::UnsupportedJsonException(): runtime_error(std::__cxx11::string("The type ") + typeid(T).name() + std::__cxx11::string(" doesn't support Json serialization or deserialization.")) {}

}

#endif
