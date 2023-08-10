#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : name(name), effects(effects){

}

const std::string &ASpell::getName() const{
	return (this->name);
}

const std::string &ASpell::getEffects() const{
	return (this->effects);
}

void ASpell::launch(const ATarget& src) const{
	src.getHitBySpell(*this);
}