#ifndef TARGETGENERATOR_HPP
 #define TARGETGENERATOR_HPP

#include <iostream>
#include "ATarget.hpp"
#include <map>

class ATarget;

class TargetGenerator{
	private:
		TargetGenerator(const TargetGenerator& src);
		TargetGenerator& operator=(const TargetGenerator& src);
		std::map<std::string, ATarget*> target;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* type);
		void forgetTargetType(std::string const& name);
		ATarget* createTarget(std::string const & name);
};

#endif