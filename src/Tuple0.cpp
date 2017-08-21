/*
 * @author jvaubourg
 * @author nkirchner
 * @author bsegault
 *
 */

#include "Tuple0.h"

using namespace std;
using namespace mecsyco;

// Access

int Tuple0::count() const {
	return 0;
}


// Debugging

string Tuple0::toString() const {
	return "Tuple(" + innerToString() + ")";
}

string Tuple0::innerToString() const {
	return "";
}

ostream& Tuple0::operator <<(ostream& aStream) const {
	aStream << toString();
	return aStream;
}

// Json

void Tuple0::toJson(Json &aJson) const {}
void Tuple0::loadFromJson(Json &aJson) {}
