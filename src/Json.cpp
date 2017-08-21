/*
 * @author nkirchner, jvaubourg
 *
 */

#include <stdexcept>

#include "Json.h"

using namespace std;
using namespace mecsyco;
using namespace boost::property_tree;

Json::Json(): m_pt() { }

Json::Json(const string& str): m_pt() {
    string new_str(str);
    istringstream iss(new_str);

    try{
        read_json(iss, m_pt);

    } catch(json_parser_error &error) {
        throw runtime_error(error.message());
    }
}

Json::Json(const ptree& pt) {
    m_pt.insert(m_pt.end(), pt.begin(), pt.end());
}

void Json::reset() {
    m_pt.clear();
}

template<>
void Json::toPtree<int>(ptree& pt, const int& value) {
    pt.put_value(to_string(value));
}

template<>
void Json::toPtree<double>(ptree& pt, const double& value) {
    pt.put_value(to_string(value));
}

template<>
void Json::toPtree<string>(ptree& pt, const string& value) {
    pt.put_value(value);
}

template<>
void Json::toPtree<bool>(ptree& pt, const bool& value) {
    pt.put_value(to_string(value) == "true");
}

template<>
void Json::fromPtree<int>(ptree& pt, int& value) {
    value = strtol(pt.data().c_str(), NULL, 10);
}

template<>
void Json::fromPtree<double>(ptree& pt, double& value) {
    value = strtod(pt.data().c_str(), NULL);
}

template<>
void Json::fromPtree<string>(ptree& pt, string& value) {
    value = (string) pt.data();
}

template<>
void Json::fromPtree<bool>(ptree& pt, bool& value) {
    value = (pt.data() == "true");
}

string Json::toString() {
    ostringstream oss;
    write_json(oss, m_pt);

    return oss.str();
}
