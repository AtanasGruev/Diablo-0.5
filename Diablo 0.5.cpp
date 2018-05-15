#include "Character.h"
#include <iostream>

using namespace std;

int main()
{
	Barbarian bar("Konan");
	cout << bar.getHealth() << " ";
	cout << bar.getIntelligence() << " ";
	cout << bar.getStrength() << " ";
	cout << endl;

	Sorcerer sor("Gandalf");
	cout << sor.getHealth() << " ";
	cout << sor.getIntelligence() << " ";
	cout << sor.getStrength() << " ";
	cout << endl;

	BountyHunter bHun("Boba Fett");
	cout << bHun.getHealth() << " ";
	cout << bHun.getIntelligence() << " ";
	cout << bHun.getStrength() << " ";
	cout << endl;

	system("pause");
}