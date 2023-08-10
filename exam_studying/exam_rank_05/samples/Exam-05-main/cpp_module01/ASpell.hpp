#ifndef ASPELL_HPP
 #define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
	
	private:
		std::string name;
		std::string effects;

	public:
		ASpell();
		ASpell(const ASpell& src);
		ASpell& operator=(const ASpell& src);
		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell* clone() const = 0;
		ASpell(std::string name, std::string effects);
		virtual ~ASpell(){};

		void launch(const ATarget& src);



};

#endif