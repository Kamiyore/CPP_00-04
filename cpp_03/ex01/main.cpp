#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


int main()
{

    std::cout << "\n--- Test 1.1: Basic ClapTrap Operations ---" << std::endl;
    // Expected: ClapTrap constructor, attack (0 dmg), take damage, repair (energy -1)
    ClapTrap clap_alpha("Alpha");
    clap_alpha.attack("a rusty bolt");
    clap_alpha.takeDamage(3);
    clap_alpha.beRepaired(2);

    std::cout << "\n--- Test 1.2: ClapTrap Resource Exhaustion ---" << std::endl;
    // Expected: 10 attacks (energy -1 each), then failed attack/repair attempts
    ClapTrap clap_beta("Beta");
    for (int i = 0; i < 10; ++i) {
        clap_beta.attack("a cardboard box");
    }
    clap_beta.attack("nothing (should fail - no energy)");
    clap_beta.beRepaired(1); // Should fail - no energy

    std::cout << "\n--- Test 1.3: ClapTrap Critical Damage ---" << std::endl;
    // Expected: HP drops to 0, subsequent actions fail if HP is 0
    ClapTrap clap_gamma("Gamma");
    clap_gamma.takeDamage(12); // Has 10 HP, so HP should become 0
    clap_gamma.attack("itself (should fail - 0 HP)");
    clap_gamma.beRepaired(5); // Should fail - 0 HP
    clap_gamma.takeDamage(1);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "         SCAVTRAP TESTS START           " << std::endl;
    std::cout << "------------------------------------------" << std::endl;


    std::cout << "\n--- Test 2.1: ScavTrap Constructors & Inheritance Chaining ---" << std::endl;
    // Expected: ClapTrap constructor then ScavTrap constructor for each new object.
    ScavTrap scav_one("Sentinel"); // Parameterized constructor
    ScavTrap scav_two(scav_one);   // Copy constructor
    ScavTrap scav_three;           // Default constructor
    ScavTrap scav_four;            // For assignment test
    scav_four = scav_one;          // Copy assignment operator

    std::cout << "\n--- Test 2.2: ScavTrap Actions & Attack Override ---" << std::endl;
    // Expected: ScavTrap's specific attack message, energy reduction, damage taken, repair (energy -1)
    scav_one.attack("a rogue Roomba"); // Energy -1, use attack_damage 20
    scav_one.takeDamage(40);           // HP from 100 to 60
    scav_one.beRepaired(20);           // HP from 60 to 80, Energy -1
    scav_one.guardGate();              // New ScavTrap ability

    std::cout << "\n--- Test 2.3: ScavTrap Resource Exhaustion ---" << std::endl;
    // Expected: 50 attacks, then failed attack/repair due to 0 energy
    ScavTrap scav_exhausted("TiredGuard");
    for (int i = 0; i < 50; ++i) { // ScavTrap has 50 energy points
        scav_exhausted.attack("a training dummy");
    }
    scav_exhausted.attack("nothing (should fail - no energy)");
    scav_exhausted.beRepaired(10); // Should fail - no energy

    std::cout << "\n--- Test 2.4: ScavTrap Critical Damage & Special Ability ---" << std::endl;
    // Expected: HP drops to 0, attack/repair fail, guardGate still works
    ScavTrap scav_critical("CriticalGuard");
    scav_critical.takeDamage(150); // HP from 100 to 0
    scav_critical.attack("phantom (should fail - 0 HP)");
    scav_critical.beRepaired(10); // Should fail - 0 HP
    scav_critical.guardGate(); // This should still work as it doesn't depend on HP/Energy

    return 0;
}
