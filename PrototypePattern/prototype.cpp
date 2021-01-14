#include <iostream>
#include "prototype.h"


Monster:: Monster( int attack, int defense, int minDamage, int maxDamage, 
	int health, int morale, int luck, int speed, 
	int initiative, int growth )
	:
	m_attack(attack),
	m_defense(defense),
	m_minDamage(minDamage),
	m_maxDamage(maxDamage),
	m_health(health),
	m_morale(morale),
	m_luck(luck),
	m_speed(speed),
	m_initiative(initiative),
	m_growth(growth)
{

}

Skeleton::Skeleton( int attack, int defense, int minDamage, int maxDamage,
	int health, int morale, int luck, int speed, int initiative,
	int growth, const char* specialAbility )
	:
	Monster{ attack, defense, minDamage,
	maxDamage, health, morale,
	luck, speed, initiative, growth },
	m_specialAbility{ specialAbility }
{}

Monster* Skeleton::clone()
{
	return new Skeleton{};
}

void Skeleton::greet() noexcept
{
	std::cout << "Skeleton: "
		<< m_specialAbility << '\n';
}


Zombie::Zombie( int attack, int defense, int minDamage, int maxDamage,
	int health, int morale, int luck, int speed, int initiative,
	int growth, const char* specialAbility )
	:
	Monster( attack, defense, minDamage,
	maxDamage, health, morale,
	luck, speed, initiative, growth ),
	m_specialAbility{specialAbility}
{

}

Monster* Zombie::clone()
{
	return new Zombie{};
}

void Zombie::greet() noexcept
{
	std::cout << "Zombie: "
		<< m_specialAbility << '\n';
}


Vampire::Vampire( int attack, int defense, int minDamage, int maxDamage,
	int health, int morale, int luck, int speed, int initiative,
	int growth, const char* specialAbility )
	:
	Monster{ attack, defense, minDamage,
	maxDamage, health, morale,
	luck, speed, initiative, growth },
	m_specialAbility{ specialAbility }
{

}

Monster* Vampire::clone()
{
	return new Vampire{};
}

void Vampire::greet() noexcept
{
	std::cout << "Vampire: "
		<< m_specialAbility << '\n';
}


MonsterFactory::MonsterFactory( Monster* monsterPrototype )
	:
	m_prototype( monsterPrototype )
{}

Monster* MonsterFactory::spawnMonster()
{
	return m_prototype->clone();
}
