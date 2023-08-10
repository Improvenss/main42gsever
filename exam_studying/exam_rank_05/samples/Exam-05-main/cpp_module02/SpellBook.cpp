#include "SpellBook.hpp"

void SpellBook::learnSpell(ASpell* src){
	if (src)
		spell.insert(std::pair<std::string, ASpell*>(src->getName(), src->clone()));
}

void SpellBook::forgetSpell(std::string const & name){
	std::map<std::string, ASpell*>::iterator it = spell.find(name);
	if (it != spell.end())
		delete it->second;
	spell.erase(name);
}

ASpell* SpellBook::createSpell(std::string const &name){
	std::map<std::string, ASpell*>::iterator it = spell.find(name);
	if (it != spell.end())
		return (spell[name]);
	return (NULL);
}

SpellBook::SpellBook(){

}

SpellBook::~SpellBook(){

}
