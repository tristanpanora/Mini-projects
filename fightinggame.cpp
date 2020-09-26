#include <iostream>
using namespace std;

/*
A very short text based fighting game
Shows understanding of OOP
*/

class Fighter {
protected:
	string name;
	string attack1_name;
	string attack2_name;

	int health;
	int attack1_dmg; //damage 
	int attack2_dmg; //damage

public:
	Fighter(): name(""), attack1_name(""), attack2_name(""), health(100), attack1_dmg(0), attack2_dmg(0)
	{}
	
	Fighter(string name, string attack1_name, string attack2_name, int health, int attack1_dmg, int attack2_dmg)
	{
		this->name = name;
		this->attack1_name = attack1_name;
		this->attack2_name = attack2_name;
		this->health = health;
		this->attack1_dmg = attack1_dmg;
		this->attack2_dmg = attack2_dmg;
	}

	string get_name() {return name; }
	string get_attack1_name() {return attack1_name; }
	string get_attack2_name() {return attack2_name; }
	int get_health() {return health; }
	int get_att1_dmg() {return attack1_dmg; }
	int get_att2_dmg() {return attack2_dmg; }
	void heal() { health += health / 5; }

	void take_damage(int dmg)
	{
		this->health -= dmg;
	}

};


class Battle: public Fighter
{
private:
	int choice;
public:

	Battle(Fighter& fighter1, Fighter& fighter2, int turnCheck)
	{
		if (turnCheck % 2 == 0) //even, fighter 1
		{
			cout << fighter1.get_name() << "'s turn!\n";
			cout << "Enter attack: (1) " << fighter1.get_attack1_name() << ", (2) " << fighter1.get_attack2_name() << ", (3) HEAL" << ": ";
			cin >> choice;

			if (choice == 1)
			{
				fighter2.take_damage(fighter1.get_att1_dmg());
				cout << fighter2.get_name() << "'s health is now: " << fighter2.get_health() << "\n\n";
			}
			else if (choice == 2)
			{
				fighter2.take_damage(fighter1.get_att2_dmg());
				cout << fighter2.get_name() << "'s health is now: " << fighter2.get_health() << "\n\n";
			}

			else if (choice == 3)
			{
				fighter1.heal();
				cout << fighter1.get_name() << " has healed. Their health is now: " << fighter1.get_health() << "\n\n";
			}

		}

		else if (turnCheck % 2 != 0) //odd, fighter 2
		{
			cout << fighter2.get_name() << "'s turn!\n";
			cout << "Enter attack: (1) " << fighter2.get_attack1_name() << ", (2) " << fighter2.get_attack2_name() << ", (3) HEAL" << ": ";
			cin >> choice;

			if (choice == 1)
			{
				fighter1.take_damage(fighter2.get_att1_dmg());
				cout << fighter1.get_name() << "'s health is now: " << fighter1.get_health() << "\n\n";
			}
			else if (choice == 2)
			{
				fighter1.take_damage(fighter2.get_att2_dmg());
				cout << fighter1.get_name() << "'s health is now: " << fighter1.get_health() << "\n\n";
			}
			
			else if (choice == 3)
			{
				fighter2.heal();
				cout << fighter2.get_name() << " has healed. Their health is now: " << fighter2.get_health() << "\n\n";			
			}
		}
		
		
	}


};

int main() //could make this a diff function
{
	string char_name = "";
	string enemy_name = "";
	int turnCheck = 0;

	cout << "WELCOME TO BATTLE ROYALE!\n";
	cout << "Choose your fighter and enemy: thor, hulk, spiderman \n";

	cout << "Enter character name: ";
	cin >> char_name;
	cout << "Enter enemy name: ";
	cin >> enemy_name;

	if (char_name == "thor") //player 1 is thor
	{
		Fighter fighter1("Thor", "hammersmash", "lightning", 100, 30, 20); //THOR
		
		if (enemy_name == "spiderman")
		{
			Fighter fighter2("Spider-Man", "webshot", "punch", 100, 25, 20); //SPIDERMAN

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}

		else if (enemy_name == "hulk")
		{
			Fighter fighter2("Hulk", "hulk smash", "ground pound", 150, 50, 40); //HULK

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}



		//cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;
		
	}

	else if (char_name == "hulk") //player 1 is hulk
	{
		Fighter fighter1("Hulk", "hulk smash", "ground pound", 150, 50, 40); //HULK

		if (enemy_name == "thor")
		{
			Fighter fighter2("Thor", "hammersmash", "lightning", 125, 40, 28); //THOR

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}

		else if (enemy_name == "spiderman")
		{
			Fighter fighter2("Spider-Man", "webshot", "punch", 100, 25, 20); //SPIDERMAN

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}
		
		
	}

	else if (char_name == "spiderman") //player 1 is spider-man
	{
		Fighter fighter1("Spider-Man", "webshot", "punch", 100, 25, 20); //SPIDERMAN

		if (enemy_name == "thor")
		{
			Fighter fighter2("Thor", "hammersmash", "lightning", 125, 40, 28); //THOR

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}

		else if (enemy_name == "hulk")
		{
			Fighter fighter2("Hulk", "hulk smash", "ground pound", 150, 45, 20); //HULK

			cout << fighter1.get_name() << " vs. " << fighter2.get_name() << endl;

			while (fighter1.get_health() > 0 && fighter2.get_health() > 0)
			{
				Battle bat(fighter1, fighter2, turnCheck); //starts a battle with thor
				turnCheck++;
				//cout << turnCheck << endl;

			}
		}

		
		
	}

	return 0;
}
