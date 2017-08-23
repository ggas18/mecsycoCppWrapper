/*
 * @author Victorien Elvinger
 *
 */

#ifndef TUPLE3_H_
#define TUPLE3_H_

#include "Tuple2.h"
#include "UnsupportedJsonException.h"

namespace mecsyco {
/**
 * Template class representing data
 * Default implementation is made for int, double, std::string and bool)
 * When inheriting this class, you don't have anything special to do.
 * Just define any constructor, setter or getter you need and reeimplement any
 * method you want.
 */
template <typename T, typename T2, typename T3>
class Tuple3 : public Tuple2<T, T2> {
protected: // Implementation
  T3 item3;

public: // Creation
        /**
         * 1) Empty constructor is mandatory.
         * 2) Getter and setter are mandatory for each variable.
         */
  explicit Tuple3() : Tuple2<T, T2>() {}

  explicit Tuple3(T aItem1, T2 aItem2, T3 aItem3);

public: // Access
  virtual T3 getItem3() const;

  virtual int count() const;

protected: // debugging
  virtual std::string innerToString() const;

public: // Json
  virtual void toJson(mecsyco::Json &json) const;
  virtual void loadFromJson(mecsyco::Json &json);
};

template <typename T, typename T2, typename T3>
using Tuple3Ptr = std::shared_ptr<Tuple3<T, T2, T3>>;

template <typename T, typename T2, typename T3>
Tuple3<T, T2, T3>::Tuple3(T aItem1, T2 aItem2, T3 aItem3)
    : Tuple2<T, T2>(aItem1, aItem2), item3(aItem3) {}

// Access
template <typename T, typename T2, typename T3>
T3 Tuple3<T, T2, T3>::getItem3() const {
  return this->item3;
}

template <typename T, typename T2, typename T3>
int Tuple3<T, T2, T3>::count() const {
  return 3;
}

// Debugging
template <typename T, typename T2, typename T3>
std::string Tuple3<T, T2, T3>::innerToString() const {
  std::stringstream ss;
  ss << ", ";
  ss << item3;

  return Tuple2<T, T2>::innerToString() + ss.str();
}

// Json
template <typename T, typename T2, typename T3>
void Tuple3<T, T2, T3>::toJson(Json &aJson) const {
  aJson.add("item1", this->item1);
  aJson.add("item2", this->item2);
  aJson.add("item3", item3);
}

template <typename T, typename T2, typename T3>
void Tuple3<T, T2, T3>::loadFromJson(Json &aJson) {
  aJson.get("item1", this->item1);
  aJson.get("item2", this->item2);
  aJson.get("item3", item3);
}
}

#endif
