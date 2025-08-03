#include "ClapTrap.hpp"

int main() 
{

    std::cout << "--- Test 1: Constructors and Destructor ---" << std::endl;
    ClapTrap hero("HeroClap");
    ClapTrap defaultBot;
    ClapTrap heroCopy(hero);

    // Expected: Default constructor for assignedBot, then "ClapTrap Assignment operator called."
    ClapTrap assignedBot;
    assignedBot = hero; // Test the assignment operator


    std::cout << "\n--- Test 2: Attack Functionality ---" << std::endl;
    // Expected: "ClapTrap HeroClap attacks BadGuy, causing 0 points of damage!"
    hero.attack("BadGuy");

    // Expected: 10 attack messages, then "Hit points or Energy points are 0!" for the final attack.
    ClapTrap tiredClap("TiredClap");
    for (int i = 0; i < 10; ++i) { // Consumes all energy (10 energy points by default)
        tiredClap.attack("PunchingBag");
    }
    tiredClap.attack("Target (should fail)"); // Should fail as energy is 0

    // Expected: "BrokenClap takes 20 of damage." (HP becomes 0), then "Hit points or Energy points are 0!" for the attack.
    ClapTrap brokenClap("BrokenClap");
    brokenClap.takeDamage(20); // Sets HP to 0 (assuming max HP is 10)
    brokenClap.attack("Target (should fail)"); // Should fail as HP is 0


    std::cout << "\n--- Test 3: TakeDamage Functionality ---" << std::endl;
    // Expected: "DefaultBot takes 5 of damage." (HP from 10 to 5)
    defaultBot.takeDamage(5);

    // Expected: "VulnerableClap takes 15 of damage." (HP becomes 0)
    ClapTrap vulnerableClap("VulnerableClap");
    vulnerableClap.takeDamage(15); // Has 10 HP, 15 damage -> 0 HP

    // Expected: "AlreadyDeadClap takes 20 of damage." (HP becomes 0), so it cannot do anthing
    ClapTrap alreadyDeadClap("AlreadyDeadClap");
    alreadyDeadClap.takeDamage(7); // Sets HP to 3
    alreadyDeadClap.takeDamage(2); // Sets to 1
    alreadyDeadClap.takeDamage(1); // Sets to 0
    alreadyDeadClap.beRepaired(5);


    std::cout << "\n--- Test 4: BeRepaired Functionality ---" << std::endl;
    // Expected: "HeroClap takes 5 of damage." (HP to 5), then "ClapTrap HeroClap 
    //repairs itself by 3 points! Energy points left: X"
    hero.takeDamage(5);
    hero.beRepaired(3);

    // Expected: Attacks consume energy, then "Not enough energy points!" for repair attempt.
    ClapTrap needsRepair("NeedsRepair");
    needsRepair.takeDamage(5);
    for (int i = 0; i < 10; ++i) {
        needsRepair.attack("Dummy"); // Consume all energy
    }
    needsRepair.beRepaired(5); // Should fail

    // Expected (if HP > 0 is NOT checked): "AlmostGone takes 10 of damage." (HP to 0), then "ClapTrap AlmostGone repairs itself by 5 points! Energy points left: X" (Energy -1, HP to 5)
    // Expected (if HP > 0 IS checked): "AlmostGone takes 10 of damage." (HP to 0), then "Hit points or Energy points are 0!" (or similar failure message)
    ClapTrap almostGone("AlmostGone");
    almostGone.takeDamage(10); // Sets HP to 0
    almostGone.beRepaired(5); // Should fail because HP is 0
    std::cout << "\n--- End of Tests ---" << std::endl;
    return 0;
}
