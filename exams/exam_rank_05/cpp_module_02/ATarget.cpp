#include "ATarget.hpp"

ATarget::~ATarget(void){}

ATarget::ATarget(void): _type()
{}

ATarget::ATarget(const ATarget &rhs) : _type(rhs._type)
{}

ATarget &ATarget::operator=(const ATarget &rhs){
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	return *this;
}

const std::string &ATarget::getType(void) const{
	return _type;
}

ATarget::ATarget(const std::string &type) : _type(type)
{}

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}

