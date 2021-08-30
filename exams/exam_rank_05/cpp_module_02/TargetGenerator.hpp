#ifndef TARGETGENERATOR_CPP
# define TARGETGENERATOR_CPP

# include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {
public:
	virtual ~TargetGenerator(void);
	TargetGenerator(void);
	void learnTargetType(ATarget *target);
	void forgetTargetType(const std::string &target);
	ATarget* createTarget(std::string const &target);
private:
	std::map<std::string, ATarget *> _targets;
	TargetGenerator(const TargetGenerator &rhs);
	TargetGenerator &operator=(const TargetGenerator &rhs);
};

#endif