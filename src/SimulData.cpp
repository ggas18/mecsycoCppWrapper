/*
 * @author jvaubourg
 * @author nkirchner
 * @author bsegault
 *
 */

#include "SimulData.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace mecsyco;

// Json

std::string SimulData::toJsonStr() const {
	Json jsonObj;
	toJson(jsonObj);
	return jsonObj.toString();
}

void SimulData::loadFromJsonStr(std::string json) {
	Json jsonObj(json);
	loadFromJson(jsonObj);
}
