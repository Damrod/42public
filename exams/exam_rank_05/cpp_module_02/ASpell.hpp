#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <iostream>

class ATarget;

class ASpell {
public:
	virtual ~ASpell(void);
	const std::string &getName(void) const;
	const std::string &getEffects(void) const;
	virtual ASpell *clone() const = 0;
	ASpell(const std::string &name, const std::string &effects);
	ASpell(void);
	ASpell(const ASpell &rhs);
	ASpell &operator=(const ASpell &rhs);
	void launch(const ATarget &target);
protected:
	std::string _name;
	std::string _effects;
};

#include "ATarget.hpp"

#endif