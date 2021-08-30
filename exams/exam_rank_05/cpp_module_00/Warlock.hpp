#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock {
public:
	virtual ~Warlock(void);
	const std::string &getName(void) const;
	const std::string &getTitle(void) const;
	void setTitle(const std::string &title);
	Warlock(const std::string &name, const std::string &title);
	void introduce() const;
private:
	Warlock(void);
	Warlock(const Warlock &rhs);
	Warlock &operator=(const Warlock &rhs);
	std::string _name;
	std::string _title;
};

#endif