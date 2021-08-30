#ifndef WARLOCK_CPP
# define WARLOCK_CPP

# include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
public:
	virtual ~Warlock(void);
	const std::string &getName(void) const;
	const std::string &getTitle(void) const;
	void setTitle(const std::string &title);
	Warlock(const std::string &name, const std::string &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	void launchSpell(const std::string &spell, ATarget &target);
private:
	Spellbook *_spellbook;
	std::map<std::string, ASpell *> _spells;
	Warlock(void);
	Warlock(const Warlock &rhs);
	Warlock &operator=(const Warlock &rhs);
	std::string _name;
	std::string _title;
};

#endif