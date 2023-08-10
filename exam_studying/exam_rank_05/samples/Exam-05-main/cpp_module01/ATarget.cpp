#include "ATarget.hpp"

ATarget::ATarget(std::string type) : type(type){

}

const std::string& ATarget::getType() const{
	return (this->type);
}

void ATarget::getHitBySpell(const ASpell& src) const{
	std::cout << this->getType() << " has been " << src.getEffects() << "!" << std::endl;
}
