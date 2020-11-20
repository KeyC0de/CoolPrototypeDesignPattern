#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <type_traits>

//============================================================
//	\class	Monster
//
//	\author	KeyC0de
//	\date	2020/11/02 21:06
//
//	\brief	The Prototype class
//=============================================================
class Monster
{
private:
	int m_attack;
	int m_defense;
	int m_minDamage;
	int m_maxDamage;
	int m_health;
	int m_morale;
	int m_luck;
	int m_speed;
	int m_initiative;
	int m_growth;
public:
	Monster( int attack, int defense, int minDamage, int maxDamage, 
		int health, int morale, int luck, int speed, 
		int initiative, int growth )
		:
		m_attack{attack},
		m_defense{defense},
		m_minDamage{minDamage},
		m_maxDamage{maxDamage},
		m_health{health},
		m_morale{morale},
		m_luck{luck},
		m_speed{speed},
		m_initiative{initiative},
		m_growth{growth}
	{}
	virtual ~Monster() noexcept = default;
	virtual Monster* clone() = 0;
	virtual void greet() noexcept = 0;
};

class Skeleton final 
	: public Monster
{
	const char* m_specialAbility;
public:
	Skeleton( int attack = 1, int defense = 2, int minDamage = 1, int maxDamage = 1, 
		int health = 4, int morale = 0, int luck = 0, int speed = 5, int initiative = 10, 
		int growth = 20, const char* specialAbility = "Undead" )
		:
		Monster{ attack, defense, minDamage,
		maxDamage, health, morale,
		luck, speed, initiative, growth },
		m_specialAbility{ specialAbility }
	{}
	Monster* clone() override
	{
		return new Skeleton{};
	}
	void greet() noexcept override
	{
		std::cout << "Skeleton: " << m_specialAbility << '\n';
	}
};

class Zombie final 
	: public Monster
{
	const char* m_specialAbility;
public:
	Zombie( int attack = 1, int defense = 2, int minDamage = 1, int maxDamage = 2, 
		int health = 17, int morale = 0, int luck = 0, int speed = 4, int initiative = 6, 
		int growth = 15, const char* specialAbility = "Enrage")
		:
		Monster{ attack, defense, minDamage,
		maxDamage, health, morale,
		luck, speed, initiative, growth },
		m_specialAbility{ specialAbility }
	{}
	Monster* clone() override
	{
		return new Zombie{};
	}

	void greet() noexcept override
	{
		std::cout << "Zombie: " << m_specialAbility << '\n';
	}
};

class Vampire final 
	: public Monster
{
	const char* m_specialAbility;
public:
	Vampire( int attack = 6, int defense = 6, int minDamage = 6, int maxDamage = 8,
		int health = 30, int morale = 0, int luck = 0, int speed = 6, int initiative = 11,
		int growth = 5, const char* specialAbility = "Life Drain" )
		:
		Monster{ attack, defense, minDamage,
		maxDamage, health, morale,
		luck, speed, initiative, growth },
		m_specialAbility{ specialAbility }
	{}
	Monster* clone() override
	{
		return new Vampire{};
	}

	void greet() noexcept override
	{
		std::cout << "Vampire: " << m_specialAbility << '\n';
	}
};

//============================================================
//	\class	MonsterFactory
//
//	\author	KeyC0de
//	\date	2020/11/02 21:07
//
//	\brief	The PrototypeFactory class
//=============================================================
class MonsterFactory final
{
	Monster* m_prototype;
public:
	MonsterFactory( Monster* monsterPrototype )
		: m_prototype( monsterPrototype )
	{}

	Monster* spawnMonster()
	{
		return m_prototype->clone();
	}
};

//===================================================
//	\function	spawnMonsterArray
//	\brief  use this helper function as a factory for arrays of objects
//			spawned from a prototypical instance
//	\date	2020/11/02 22:03
template< typename T,
	typename = std::enable_if_t<std::is_base_of_v<Monster, T>> >
std::vector<Monster*> spawnMonsterArray( MonsterFactory* monsterFactory,
	std::size_t count )
{
	std::vector<Monster*> monsters;
	monsters.reserve( count );
	for ( std::size_t i = 0; i < count; ++i )
	{
		monsters.emplace_back( monsterFactory->spawnMonster() );
	}
	return monsters;
}
