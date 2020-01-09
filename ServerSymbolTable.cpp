//
// Created by חן גולדשטיין on 06/01/2020.
//

#include "ServerSymbolTable.h"

ServerSymbolTable::ServerSymbolTable() {
	this->m = new std::map<std::string, std::list<std::string> *>();
	// INITIALIZING THE 36 KEYS - PATHS, OF THE SERVER SYMBOL TABLE.
	this->add("/instrumentation/airspeed-indicator/indicated-speed-kt", "");
	this->add("/sim/time/warp", "");
	this->add("/controls/switches/magnetos", "");
	this->add("/instrumentation/heading-indicator/offset-deg", "");
	this->add("/instrumentation/altimeter/indicated-altitude-ft", "");
	this->add("/instrumentation/altimeter/pressure-alt-ft", "");
	this->add("/instrumentation/attitude-indicator/indicated-pitch-deg", "");
	this->add("/instrumentation/attitude-indicator/indicated-roll-deg", "");
	this->add("/instrumentation/attitude-indicator/internal-pitch-deg", "");
	this->add("/instrumentation/attitude-indicator/internal-roll-deg", "");
	this->add("/instrumentation/encoder/indicated-altitude-ft", "");
	this->add("/instrumentation/encoder/pressure-alt-ft", "");
	this->add("/instrumentation/gps/indicated-altitude-ft", "");
	this->add("/instrumentation/gps/indicated-ground-speed-kt", "");
	this->add("/instrumentation/gps/indicated-vertical-speed", "");
	this->add("/instrumentation/heading-indicator/indicated-heading-deg", "");
	this->add("/instrumentation/magnetic-compass/indicated-heading-deg", "");
	this->add("/instrumentation/slip-skid-ball/indicated-slip-skid", "");
	this->add("/instrumentation/turn-indicator/indicated-turn-rate", "");
	this->add("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "");
	this->add("/controls/flight/aileron", "");
	this->add("/controls/flight/elevator", "");
	this->add("/controls/flight/rudder", "");
	this->add("/controls/flight/flaps", "");
	this->add("/controls/engines/engine/throttle", "");
	this->add("/controls/engines/current-engine/throttle", "");
	this->add("/controls/switches/master-avionics", "");
	this->add("/controls/switches/starter", "");
	this->add("/engines/active-engine/auto-start", "");
	this->add("/controls/flight/speedbrake", "");
	this->add("/sim/model/c172p/brake-parking", "");
	this->add("/controls/engines/engine/primer", "");
	this->add("/controls/engines/current-engine/mixture", "");
	this->add("/controls/switches/master-bat", "");
	this->add("/controls/switches/master-alt", "");
	this->add("/engines/engine/rpm", "");


}
ServerSymbolTable::~ServerSymbolTable() {
	delete this->m;
}

void ServerSymbolTable::add(std::string path, std::string varName) {
	using namespace std;
	if (path.empty()) {
		// Do Nothing, even if we have a varName or not, we can't do anything.
	} else if (!path.empty() && varName.empty()) {
		// the path isn't in the map
		if (this->m->find(path) == this->m->end()) {
			this->m->insert({path, nullptr});
		}
		// else do nothing because there is nothing to insert.
	} else if (!path.empty() && !varName.empty()) {
		// the path isn't in the map
		if (this->m->find(path) == this->m->end()) {
			auto insert_list = new list<string>();
			insert_list->push_front(varName);
			this->m->insert({path, insert_list});
		} else {
			auto list_at_path = this->m->at(path);
			// the list isn't null
			if (list_at_path != nullptr) {
				// but the list doesn't contain the varName
				if (find(list_at_path->begin(), list_at_path->end(), varName) == list_at_path->end()) {
					list_at_path->push_front(varName);
				}
				// else do nothing because the varName is in the list already.
			} else {
				// the path exist but the list is null, so we need to create the new list.
				auto insert_list = new list<string>();
				insert_list->push_front(varName);
				this->m->at(path) = insert_list;
			}
		}
	}
	/**
	 * That was the previous version
	 */
	// Checking if the path - the key exist already in the map
//	if (this->m->find(path) != this->m->end()) {
//		list<std::string> *list_at_path = this->m->at(path);
//		// if the variable doesn't exist then we need to do add it. If it exist we aren't going to add it again.
//		if (list_at_path == nullptr){
//			auto insert = new std::list<std::string>;
//			insert->push_front(varName);
//		}
//
//		if (std::find(list_at_path->begin(), list_at_path->end(), varName) == list_at_path->end()) {
//			this->m->at(path)->push_front(varName);
//		}
//	} else {
//		auto insert_list = new std::list<std::string>;
//		insert_list->push_front(varName);
//		this->m->insert({path, insert_list});
//	}
}

void ServerSymbolTable::updateAtSymbolTable(std::string path, double value, SymbolTable *symbol_table) {
	using namespace std;
	// If this path exists
	if (this->m->find(path) != this->m->end()) {
		list<std::string> *list_at_path = this->m->at(path);
		for (auto iterator = list_at_path->begin(); iterator != list_at_path->end(); ++iterator) {
			//If the value exist in the symbol_table, otherwise there is nothing to update.
			if (symbol_table->getMap()->find(*iterator) != symbol_table->getMap()->end()) {
				symbol_table->setVal(*iterator, value);
			}
		}
	}
}
std::map<std::string, std::list<std::string> *> *ServerSymbolTable::GetM() const {
	return m;
}


//std::list<std::string>* ServerSymbolTable::getList(std::string path) {
//	return this->m->at(path);
//}
//
//double ServerSymbolTable::getVal(std::string name) {
//	return m->at(name).GetValue();
//}
//
//std::string ServerSymbolTable::getSim(std::string name) {
//	return m->at(name).GetSim();
//}