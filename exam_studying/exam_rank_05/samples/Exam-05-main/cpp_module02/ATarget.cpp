#include "ATarget.hpp"

ATarget::ATarget(const std::string type){
	this->type = type;
}

std::string const &ATarget::getType() const { return (this->type);}


void ATarget::getHitBySpell(const ASpell& src) const{
	std::cout << this->getType() << " has been " << src.getEffects() << "!" << std::endl;
}
