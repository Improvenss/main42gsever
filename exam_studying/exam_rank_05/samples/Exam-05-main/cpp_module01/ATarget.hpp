#ifndef ATARGET_HPP
 #define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget{
	private:
		std::string type;
	public:
		const std::string& getType() const;

		virtual ATarget* clone() const = 0;
		ATarget(std::string type);

		void getHitBySpell(const ASpell& src) const;
		ATarget();
		ATarget(const ATarget& src);
		ATarget& operator=(const ATarget& src);
		~ATarget(){};
};


#endif
