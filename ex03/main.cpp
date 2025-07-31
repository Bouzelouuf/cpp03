#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
   std::cout << "=== CLAPTRAP TESTS ===" << std::endl;
   {
       ClapTrap basic("Basic");
       basic.attack("dummy");
       basic.takeDamage(5);
       basic.beRepaired(3);
       basic.takeDamage(15); // Should die
       basic.attack("dummy"); // Should fail (no HP)
   }

   std::cout << "\n=== SCAVTRAP TESTS ===" << std::endl;
   {
       ScavTrap guard("Guardian");
       guard.attack("enemy");
       guard.guardGate();
       guard.takeDamage(50);
       guard.beRepaired(20);
       
       // Test copy
       ScavTrap guard2(guard);
       guard2.guardGate();
   }

   std::cout << "\n=== FRAGTRAP TESTS ===" << std::endl;
   {
       FragTrap frag("Fragmenter");
       frag.attack("target");
       frag.highFivesGuys();
       frag.takeDamage(80);
       frag.beRepaired(40);
       
       // Test assignment
       FragTrap frag2("Copy");
       frag2 = frag;
       frag2.highFivesGuys();
   }

   std::cout << "\n=== DIAMONDTRAP TESTS ===" << std::endl;
   {
       DiamondTrap diamond("Diamond");
       diamond.whoAmI();
       diamond.attack("villain");
       diamond.guardGate();    // From ScavTrap
       diamond.highFivesGuys(); // From FragTrap
       diamond.takeDamage(25);
       diamond.beRepaired(10);
       
       // Test copy constructor
       DiamondTrap diamond2(diamond);
       diamond2.whoAmI();
       
       // Test default constructor
       DiamondTrap diamond3;
       diamond3.whoAmI();
   }

   std::cout << "\n=== ENERGY DEPLETION TEST ===" << std::endl;
   {
       DiamondTrap tired("Tired");
       // Use up all energy (50 points)
       for (int i = 0; i < 25; i++) {
           tired.attack("dummy");
           tired.beRepaired(1);
       }
       tired.attack("dummy"); // Should fail (no energy)
       tired.beRepaired(1);   // Should fail (no energy)
   }

   return 0;
}
