#ifndef SPELLBOOK_CPP
# define SPELLBOOK_CPP

# include <iostream>
#include <map>

#include "ASpell.hpp"

class Spellbook {
public:
	virtual ~Spellbook(void);
	Spellbook(void);
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	ASpell* createSpell(std::string const &spell);
private:
	std::map<std::string, ASpell *> _spells;
	Spellbook(const Spellbook &rhs);
	Spellbook &operator=(const Spellbook &rhs);
};

#endif