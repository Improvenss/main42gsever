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
		const std::string &getName() const;
		const std::string &getEffects() const;

		virtual ASpell* clone() const = 0;
		ASpell(std::string name, std::string effects);
		virtual ~ASpell(){};

		void launch(ATarget const &atarget_ref) const;



};

#endif