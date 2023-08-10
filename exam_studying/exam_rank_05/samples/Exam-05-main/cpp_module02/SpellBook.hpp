#ifndef SPELLBOOK_HPP
 #define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class SpellBook{
	private:
		SpellBook(const SpellBook& src);
		SpellBook& operator=(const SpellBook& src);
		std::map<std::string, ASpell*> spell;
	public:

		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* src);
		void forgetSpell(std::string const & name);
		ASpell* createSpell(std::string const &name);
};

#endif