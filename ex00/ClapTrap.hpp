# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include "iostream"

class ClapTrap
{
	private:
	std::string		name;
	int				hit_points;
	int				energy_points;
	int				amount;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif
