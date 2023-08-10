#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget* type){
	if (type)
		target.insert(std::pair<std::string, ATarget*>(type->getType(), type->clone()));
}

void TargetGenerator::forgetTargetType(std::string const& name){
	target.erase(name);
}

ATarget* TargetGenerator::createTarget(std::string const& name){
	std::map<std::string, ATarget*>::iterator it = target.find(name);
	if (it != target.end())
		return (target[name]);
	return (NULL);
}

TargetGenerator::TargetGenerator(){

}

TargetGenerator::~TargetGenerator(){
	std::map<std::string, ATarget*>::iterator it = target.begin();
	std::map<std::string, ATarget*>::iterator ite = target.end();
	if (it != ite)
	{
		delete it->second;
		++it;
	}
	target.clear();
}