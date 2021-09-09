#include <iostream>
#include "prototype.h"


Monster::Monster( int attack, int defense, int minDamage, int maxDamage, 
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
	int growth, std::string_view specialAbility )
	:
	Monster{attack, defense, minDamage, maxDamage, health, morale, luck, speed,
		initiative, growth},
	m_specialAbility{specialAbility}
{

}

std::unique_ptr<Monster> Skeleton::clone()
{
	return std::make_unique<Skeleton>( *this );
}

void Skeleton::greet() noexcept
{
	std::cout << "Skeleton: "
		<< m_specialAbility
		<< '\n';
}

Zombie::Zombie( int attack, int defense, int minDamage, int maxDamage,
	int health, int morale, int luck, int speed, int initiative,
	int growth, std::string_view specialAbility )
	:
	Monster(attack, defense, minDamage, maxDamage, health, morale, luck, speed,
		initiative, growth),
	m_specialAbility{specialAbility}
{

}

std::unique_ptr<Monster> Zombie::clone()
{
	return std::make_unique<Zombie>( *this );
}

void Zombie::greet() noexcept
{
	std::cout << "Zombie: "
		<< m_specialAbility
		<< '\n';
}


Vampire::Vampire( int attack, int defense, int minDamage, int maxDamage,
	int health, int morale, int luck, int speed, int initiative,
	int growth, std::string_view specialAbility )
	:
	Monster{attack, defense, minDamage, maxDamage, health, morale, luck, speed,
		initiative, growth},
	m_specialAbility{specialAbility}
{

}

std::unique_ptr<Monster> Vampire::clone()
{
	return std::make_unique<Vampire>();
}

void Vampire::greet() noexcept
{
	std::cout << "Vampire: "
		<< m_specialAbility
		<< '\n';
}

MonsterSpawner::MonsterSpawner( Monster* monsterPrototype )
	:
	m_pPrototype(monsterPrototype)
{

}

std::unique_ptr<Monster> MonsterSpawner::spawnMonster()
{
	return m_pPrototype->clone();
}
