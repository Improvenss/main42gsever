#ifndef WARLOCK_HPP
 #define WARLOCK_HPP

#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class ASpell;
class ATarget;
class SpellBook;

class Warlock{
	private:
		std::string name;
		std::string title;
		Warlock(const Warlock& src);
		Warlock& operator=(const Warlock& src);

		SpellBook spell;
	public:
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string & title);

		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		void introduce() const;

		void learnSpell(ASpell *src);
		void forgotSpell(std::string name);
		void launchSpell(std::string name, const ATarget& src);
};

#endif