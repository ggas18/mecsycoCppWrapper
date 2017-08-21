/*
 * @author nkirchner, jvaubourg
 *
 */

#ifndef JSON_H_
#define JSON_H_

#define BOOST_SPIRIT_THREADSAFE

#include <string>
#include <map>
#include <vector>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace mecsyco {

class Json {
private:
	boost::property_tree::ptree m_pt;

	template<class T> T getNativeFromString(const std::string& str);
	template<class T> void toPtree(boost::property_tree::ptree& pt, const T& value);
	template<class T> void toPtree(boost::property_tree::ptree& pt, const std::vector<T>& value);
	template<class T> void toPtree(boost::property_tree::ptree& pt, const std::map<std::string, T>& value);
	template<class T> void fromPtree(boost::property_tree::ptree& pt, T& value);
	template<class T> void fromPtree(boost::property_tree::ptree& pt, std::vector<T>& value);
	template<class T> void fromPtree(boost::property_tree::ptree& pt, std::map<std::string, T>& value);

public:
	Json();
	Json(const std::string& str);
	Json(const boost::property_tree::ptree& pt);

	void reset();

	template<class T> void add(std::string name, const T& data);
	template<class T> void get(std::string name, T& data);

	std::string toString();
};

template<>
void Json::toPtree<int>(boost::property_tree::ptree& pt, const int& value);

template<>
void Json::toPtree<double>(boost::property_tree::ptree& pt, const double& value);

template<>
void Json::toPtree<std::string>(boost::property_tree::ptree& pt, const std::string& value);

template<>
void Json::toPtree<bool>(boost::property_tree::ptree& pt, const bool& value);

template<class T>
void Json::toPtree(boost::property_tree::ptree& pt, const std::vector<T>& value) {
	for(const T& element : value) {
		boost::property_tree::ptree buffer;
		buffer.clear();
		toPtree(buffer, element);
		pt.push_back(std::make_pair("", buffer));
	}
}

template<class T>
void Json::toPtree(boost::property_tree::ptree& pt, const std::map<std::string, T>& value) {
	for(const auto& element : value) {
		boost::property_tree::ptree buffer;
		buffer.clear();
		toPtree(buffer, element.second);
		pt.push_back(std::make_pair(element.first, buffer));
	}
}

template<class T>
void Json::toPtree(boost::property_tree::ptree& pt, const T& value) {
	Json buffer;
	value.toJson(buffer);
	pt.insert(pt.end(), buffer.m_pt.begin(), buffer.m_pt.end());
}

template<>
void Json::fromPtree<int>(boost::property_tree::ptree& pt, int& value);

template<>
void Json::fromPtree<double>(boost::property_tree::ptree& pt, double& value);

template<>
void Json::fromPtree<std::string>(boost::property_tree::ptree& pt, std::string& value);

template<>
void Json::fromPtree<bool>(boost::property_tree::ptree& pt, bool& value);

template<class T>
void Json::fromPtree(boost::property_tree::ptree& pt, std::vector<T>& value) {
	for(const auto& elem : pt) {
		T translated_elem;
		boost::property_tree::ptree second = elem.second;
		fromPtree(second, translated_elem);
		value.push_back(translated_elem);
	}
}

template<class T>
void Json::fromPtree(boost::property_tree::ptree& pt, std::map<std::string, T>& value) {
	using namespace boost;

	for(const auto& elem : pt) {
		T translated_second;
		boost::property_tree::ptree second = elem.second;
		fromPtree(second, translated_second);
		std::pair<std::string, T> translated_elem(elem.first, translated_second);
		value.insert(translated_elem);
	}
}

template<class T>
void Json::fromPtree(boost::property_tree::ptree& pt, T& value) {
	Json jsonObj(pt);
	value.loadFromJson(jsonObj);
}

template<class T>
void Json::add(std::string name, const T& data) {
	m_pt.put_child(name, boost::property_tree::ptree());
	boost::property_tree::ptree& subTree = m_pt.get_child(name);
	toPtree(subTree, data);
}

template<class T>
void Json::get(std::string name, T& data) {
	boost::property_tree::ptree& subTree = m_pt.get_child(name);
	fromPtree(subTree, data);
}
}

#endif
