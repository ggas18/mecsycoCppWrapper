/*
 * @author Victorien Elvinger
 *
 */

#ifndef TUPLE2_H_
#define TUPLE2_H_

#include "Tuple1.h"
#include "UnsupportedJsonException.h"
#include <sstream>

namespace mecsyco {
/**
 * Template class representing data
 * Default implementation is made for int, double, std::string and bool)
 * When inheriting this class, you don't have anything special to do.
 * Just define any constructor, setter or getter you need and reeimplement any
 * method you want.
 */
template <typename T, typename T2> class Tuple2 : public Tuple1<T> {
protected: // Implementation
  T2 item2;

public: // Creation
        /**
         * 1) Empty constructor is mandatory.
         * 2) Getter and setter are mandatory for each variable.
         */
  explicit Tuple2() : Tuple1<T>() {}

  explicit Tuple2(T aItem1, T2 aItem2);

public: // Access
  virtual T2 getItem2() const;

  virtual int count() const;

protected: // Debugging
  virtual std::string innerToString() const;

public: // Json
  virtual void toJson(mecsyco::Json &json) const;
  virtual void loadFromJson(mecsyco::Json &json);
};

template <typename T, typename T2>
using Tuple2Ptr = std::shared_ptr<Tuple2<T, T2>>;

template <typename T, typename T2>
Tuple2<T, T2>::Tuple2(T aItem1, T2 aItem2) : Tuple1<T>(aItem1), item2(aItem2) {}

// Access
template <typename T, typename T2> T2 Tuple2<T, T2>::getItem2() const {
  return this->item2;
}

template <typename T, typename T2> int Tuple2<T, T2>::count() const {
  return 2;
}

// Debugging
template <typename T, typename T2>
std::string Tuple2<T, T2>::innerToString() const {
  std::stringstream ss;
  ss << ", ";
  ss << item2;

  return Tuple1<T>::innerToString() + ss.str();
}

// Json
template <typename T, typename T2>
void Tuple2<T, T2>::toJson(Json &aJson) const {
  aJson.add("item1", this->item1);
  aJson.add("item2", item2);
}

template <typename T, typename T2>
void Tuple2<T, T2>::loadFromJson(Json &aJson) {
  aJson.get("item1", this->item1);
  aJson.get("item2", item2);
}
}

#endif
