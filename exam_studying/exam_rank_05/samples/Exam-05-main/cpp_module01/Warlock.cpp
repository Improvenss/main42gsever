#include "Warlock.hpp"

Warlock::Warlock(const std::string & name, const std::string & title) : name(name), title(title){
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const{
	return (this->name);
}

const std::string& Warlock::getTitle() const{
	return (this->title);
}

void Warlock::setTitle(const std::string& title){
	this->title = title;
}

void Warlock::introduce() const{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *src){
	if (src != NULL)
		spell.insert(std::pair<std::string, ASpell*>(src->getName(), src->clone()));
}

void Warlock::forgetSpell(std::string name){
	std::map<std::string, ASpell*>::iterator it = spell.find(name);
	if (it != spell.end())
		delete it->second;
	spell.erase(name);
}

void Warlock::launchSpell(std::string name, const ATarget& src){
	std::map<std::string, ASpell*>::iterator it = spell.find(name);
	if (it != spell.end())
		it->second->launch(src);
}