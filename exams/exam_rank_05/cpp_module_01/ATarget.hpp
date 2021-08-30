#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <iostream>

class ASpell;

class ATarget {
public:
	ATarget(void);
	ATarget(const ATarget &rhs);
	ATarget &operator=(const ATarget &rhs);
	virtual ~ATarget(void);
	const std::string &getType(void) const;
	virtual ATarget *clone() const = 0;
	ATarget(const std::string &type);
	void getHitBySpell(const ASpell &spell) const;
protected:
	std::string _type;
};

#include "ASpell.hpp"

#endif