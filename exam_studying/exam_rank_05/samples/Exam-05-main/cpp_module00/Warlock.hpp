#ifndef WARLOCK_HPP
 #define WARLOCK_HPP

#include <iostream>

class Warlock{
	private:
		std::string name;
		std::string title;
		Warlock(const Warlock& src);
		Warlock& operator=(const Warlock& src);
	public:
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string & title);

		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		void introduce() const;
};

#endif