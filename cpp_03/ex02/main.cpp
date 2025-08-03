#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Test 3.1: FragTrap Constructors & Inheritance Chaining ---" << std::endl;
    // Expected: ClapTrap constructor -> FragTrap constructor (for each instance)
    FragTrap frag_alpha("AlphaFrag"); // Parameterized constructor
    FragTrap frag_beta(frag_alpha);   // Copy constructor
    FragTrap frag_gamma;              // Default constructor
    FragTrap frag_delta;              // For assignment test
    frag_delta = frag_alpha;          // Assignment operator

    std::cout << "\n--- Test 3.2: FragTrap Actions & Attack Override ---" << std::endl;
    // Expected: Specific message for FragTrap attack, energy reduction, damage taken, repair (energy -1).
    frag_alpha.attack("Giant Spider"); // Energy -1, attack damage 30
    frag_alpha.takeDamage(50);         // HP from 100 to 50
    frag_alpha.beRepaired(25);         // HP from 50 to 75, Energy -1
    frag_beta.highFivesGuys();

    std::cout << "\n--- Test 3.4: FragTrap Resource Exhaustion ---" << std::endl;
    // Expected: 100 attacks, then attack/repair failure due to 0 energy.
    FragTrap frag_exhausted("ExhaustedFrag");
    for (int i = 0; i < 100; ++i) { // FragTrap has 100 energy
        frag_exhausted.attack("practice target");
    }
    frag_exhausted.attack("nothing (should fail - no energy)");
    frag_exhausted.beRepaired(10); // Should fail - 0 energy

    std::cout << "\n--- Test 3.5: FragTrap Critical Damage ---" << std::endl;
    // Expected: HP drops to 0, attack/repair fails, highFivesGuys should still work.
    FragTrap frag_critical("CriticalFrag");
    frag_critical.takeDamage(150); // HP from 100 to 0
    frag_critical.attack("phantom (should fail - 0 HP)");
    frag_critical.beRepaired(10); // Should fail - 0 HP
    frag_critical.highFivesGuys(); // Should still work
    return 0;
}
