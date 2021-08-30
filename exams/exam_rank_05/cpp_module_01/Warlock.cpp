#include "Warlock.hpp"

Warlock::~Warlock(void){
	std::cout << _name << ": My job here is done!\n";
}

const std::string &Warlock::getName(void) const{
	return _name;
}
const std::string &Warlock::getTitle(void) const{
	return _title;
}
void Warlock::setTitle(const std::string &title){
	_title = title;
}
Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *spell){
	if (spell && _spells.find(spell->getName()) == _spells.end())
		_spells[spell->getName()] = spell;
}
void Warlock::forgetSpell(const std::string &spell){
	try {
		_spells.erase(spell); // _spells.erase(spell)!!
	} catch (...){}
}
void Warlock::launchSpell(const std::string &spell, ATarget &target){
	try {
		_spells.at(spell)->launch(target);
	} catch (...){}
}