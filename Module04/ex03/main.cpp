#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

void testBasicFunctionality() {
    std::cout << CYAN "===== BASIC FUNCTIONALITY TEST =====\n" RESET << std::endl;
    
    // Test from the subject
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    std::cout << GREEN "\nBasic functionality test completed." RESET << std::endl << std::endl;
}

void testMateriaCreation() {
    std::cout << CYAN "===== MATERIA CREATION TEST =====\n" RESET << std::endl;
    
    // Create and test Ice
    Ice* ice = new Ice();
    std::cout << "Materia type: " BRIGHT_GREEN << ice->getType()
              << RESET << std::endl;
    
    // Clone the Ice
    AMateria* clonedIce = ice->clone();
    std::cout << "Cloned Materia type: " BRIGHT_GREEN
              << clonedIce->getType() << RESET << std::endl;
    
    // Create and test Cure
    Cure* cure = new Cure();
    std::cout << "Materia type: " BRIGHT_GREEN << cure->getType()
              << RESET << std::endl;
    
    // Clone the Cure
    AMateria* clonedCure = cure->clone();
    std::cout << "Cloned Materia type: " BRIGHT_GREEN
              << clonedCure->getType() << RESET << std::endl;
    
    // Test use function
    ICharacter* target = new Character("target");
    ice->use(*target);
    cure->use(*target);
    clonedIce->use(*target);
    clonedCure->use(*target);
    
    delete target;
    delete ice;
    delete clonedIce;
    delete cure;
    delete clonedCure;
    
    std::cout << GREEN "\nMateria creation test completed." RESET << std::endl << std::endl;
}

void testCharacterFunctionality() {
    std::cout << CYAN "===== CHARACTER FUNCTIONALITY TEST =====\n" RESET<< std::endl;
    
    Character* me = new Character("hero");
    std::cout << "Character name: " BRIGHT_YELLOW << me->getName()
              << RESET << std::endl;

    // Create materias
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* extraIce = new Ice();
    
    // Test equipping 4 materias (full inventory)
    std::cout << "Equipping 4 materias..." << std::endl;
    me->equip(ice1);
    me->equip(cure1);
    me->equip(ice2);
    me->equip(cure2);

    ICharacter* enemy = new Character("enemy");
    
    // Use all materias
    std::cout << "Using all 4 materias:" << std::endl;
    me->use(0, *enemy);
    me->use(1, *enemy);
    me->use(2, *enemy);
    me->use(3, *enemy);

    std::cout << "Testing invalid uses:" << std::endl;
    me->use(-1, *enemy);  // Should do nothing
    me->use(4, *enemy);   // Should do nothing

    std::cout << "Testing equip to full inventory:" << std::endl;
    me->equip(extraIce);  // Should add to floor or not equip

    std::cout << "Testing unequip:" << std::endl;
    me->unequip(1);  // Unequip cure1
    delete cure1;

    std::cout << "Using unequipped slot:" << std::endl;
    me->use(1, *enemy);  // Should do nothing

    std::cout << GREEN "\nCharacter functionality test completed." RESET << std::endl << std::endl;
    // Clean up
    delete extraIce;
    delete enemy;
    delete me;  // This will also delete ice1, ice2, cure1, and cure2
}

void testMateriaSource() {
    std::cout << CYAN "===== MATERIA SOURCE TEST =====\n" RESET << std::endl;

    MateriaSource* source = new MateriaSource();
    
    // Try to create before learning any materias
    std::cout << "Creating before learning (should return NULL):" << std::endl;
    AMateria* tmp = source->createMateria("ice");
    if (tmp == NULL)
        std::cout << "Correctly returned NULL for unknown materia." << std::endl;
    else
				delete tmp;

    // Learn materias
    std::cout << "\nLearning materias:" << std::endl;
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    
    // Create materias after learning
    std::cout << "\nCreating after learning:" << std::endl;
    AMateria* ice = source->createMateria("ice");
    AMateria* cure = source->createMateria("cure");
    
    if (ice) 
        std::cout << "Successfully created ice Materia: " << ice->getType() << std::endl;
    
    if (cure)
        std::cout << "Successfully created cure Materia: " << cure->getType() << std::endl;
    
    // Try to create unknown materia
    std::cout << "\nCreating unknown materia (should return NULL):" << std::endl;
    tmp = source->createMateria("fire");
    if (tmp == NULL) {
        std::cout << "Correctly returned NULL for unknown materia." << std::endl;
    } else {
        delete tmp;
    }
    
    // Test learning more than 4 materias
    std::cout << "\nTesting learning more than 4 materias:" << std::endl;
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    Ice*  tmp_ice = new Ice();
    source->learnMateria(tmp_ice);  // This should not be learned (over the 4 limit)
    delete tmp_ice;
    // Clean up
    delete ice;
    delete cure;
    delete source;
    
    std::cout << GREEN "\nMateriaSource test completed." RESET << std::endl << std::endl;
}

void testEdgeCases() {
    std::cout << CYAN "===== EDGE CASES TEST =====\n" RESET<< std::endl;

    std::cout << "Testing with NULL materias:" << std::endl;
    Character* character = new Character("tester");
    
    character->equip(NULL);
    character->use(0, *character);

    MateriaSource* source = new MateriaSource();
    source->learnMateria(NULL);
    
    // Test assignment operator
    std::cout << "\nTesting assignment operator:" << std::endl;
    Character* original = new Character("original");
    
    original->equip(new Ice());
    original->equip(new Cure());
    
    Character* assigned = new Character("assigned");
    *assigned = *original;

    ICharacter* target = new Character("target");
    std::cout << "--Using materias from assigned character:" << std::endl;
    assigned->use(0, *target);
    assigned->use(1, *target);
    
    // Modify original after assignment
    std::cout << "--Modifying original after assignment:" << std::endl;
    const AMateria *tmp = original->getMateria(0);
    original->unequip(0);
    delete tmp;

    std::cout << "--Using materias from original character:" << std::endl;
    original->use(0, *target);
    original->use(1, *target);
    
    // Clean up
    delete target;
    delete original;
    delete assigned;
    delete source;
    delete character;
    
    std::cout << GREEN "\nEdge cases test completed." RESET << std::endl << std::endl;
}

int main() {
    std::cout << BRIGHT_GREEN "======================================" << std::endl;
    std::cout << "     MATERIA SYSTEM TESTING SUITE     " << std::endl;
    std::cout << "======================================\n" RESET << std::endl;
    
    // Run all tests
    testBasicFunctionality();
    testMateriaCreation();
    testCharacterFunctionality();
    testMateriaSource();
    testEdgeCases();
    
    
    std::cout << BRIGHT_GREEN "======================================" << std::endl;
    std::cout << "        ALL TESTS COMPLETED           " << std::endl;
    std::cout << "======================================" RESET << std::endl;
    
    return 0;
}