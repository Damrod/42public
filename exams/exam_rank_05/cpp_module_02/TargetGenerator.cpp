#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) : _targets() {
}

TargetGenerator::~TargetGenerator(void){
	std::map<std::string, ATarget *>::iterator it = _targets.begin();
	for(; it != _targets.end(); ++it)
		delete it->second; // it is like a poiinter to arrow
	_targets.clear(); // clear them all!!
}

void TargetGenerator::learnTargetType(ATarget *target){
	if (target && _targets.find(target->getType()) == _targets.end())
		_targets[target->getType()] = target->clone();
}
void TargetGenerator::forgetTargetType(const std::string &target){
	try {
		delete _targets.at(target);
		_targets.erase(target); // _targets.erase(target)!!
	} catch (...){}
}

ATarget* TargetGenerator::createTarget(const std::string &target){
	try {
		return _targets.at(target);
	} catch (...){}
	return NULL;
}