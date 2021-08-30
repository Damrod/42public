#include "SpellBook.hpp"

Spellbook::Spellbook(void):_spells(){
}

Spellbook::~Spellbook(void){
	std::map<std::string, ASpell*>::iterator it = _spells.begin();
	for(; it != _spells.end(); ++it)
		delete it->second; // it is like a poiinter to arrow
	_spells.clear(); // clear them all!!
}

void Spellbook::learnSpell(ASpell *spell){
	if (spell && _spells.find(spell->getName()) == _spells.end())
		_spells[spell->getName()] = spell->clone();
}
void Spellbook::forgetSpell(const std::string &spell){
	try {
		delete _spells.at(spell);
		_spells.erase(spell); // _spells.erase(spell)!!
	} catch (...){}
}

ASpell* Spellbook::createSpell(const std::string &spell){
	try {
		return _spells.at(spell);
	} catch (...){}
	return NULL;
}