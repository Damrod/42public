#include "ASpell.hpp"

ASpell::~ASpell(void){}

ASpell::ASpell(void): _name(), _effects()
{}

ASpell::ASpell(const ASpell &rhs) : _name(rhs._name), _effects(rhs._effects)
{}

ASpell &ASpell::operator=(const ASpell &rhs){
	if (this != &rhs)
	{
		_name = rhs.getName();
		_effects = rhs.getEffects();
	}
	return *this;
}

const std::string &ASpell::getName(void) const{
	return _name;
}

const std::string &ASpell::getEffects(void) const{
	return _effects;
}

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects)
{}

void ASpell::launch(const ATarget &target) {
	target.getHitBySpell(*this);
}

