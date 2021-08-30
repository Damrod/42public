#include "Polymorph.hpp"

Polymorph::Polymorph():ASpell("Polymorph", "turned into critter"){}
Polymorph::~Polymorph(){}
Polymorph *Polymorph::clone() const {
	return new Polymorph();
};