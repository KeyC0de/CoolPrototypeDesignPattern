#pragma once

#include <vector>
#include <memory>
#include <string_view>


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
protected:
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
	Monster( int attack, int defense, int minDamage, int maxDamage, int health,
		int morale, int luck, int speed, int initiative, int growth );
	virtual ~Monster() noexcept = default;

	virtual std::unique_ptr<Monster> clone() = 0;
	virtual void greet() noexcept = 0;
};

class Skeleton final 
	: public Monster
{
	std::string_view m_specialAbility;
public:
	Skeleton( int attack = 1, int defense = 2, int minDamage = 1, int maxDamage = 1, 
		int health = 4, int morale = 0, int luck = 0, int speed = 5, int initiative = 10, 
		int growth = 20, std::string_view specialAbility = "Undead" );

	std::unique_ptr<Monster> clone() override;
	void greet() noexcept override;
};

class Zombie final 
	: public Monster
{
	std::string_view m_specialAbility;
public:
	Zombie( int attack = 1, int defense = 2, int minDamage = 1, int maxDamage = 2, 
		int health = 17, int morale = 0, int luck = 0, int speed = 4, int initiative = 6, 
		int growth = 15, std::string_view specialAbility = "Enrage");

	std::unique_ptr<Monster> clone() override;
	void greet() noexcept override;
};

class Vampire final 
	: public Monster
{
	std::string_view m_specialAbility;
public:
	Vampire( int attack = 6, int defense = 6, int minDamage = 6, int maxDamage = 8,
		int health = 30, int morale = 0, int luck = 0, int speed = 6, int initiative = 11,
		int growth = 5, std::string_view specialAbility = "Life Drain" );

	std::unique_ptr<Monster> clone() override;
	void greet() noexcept override;
};

//============================================================
//	\class	MonsterSpawner
//
//	\author	KeyC0de
//	\date	2020/11/02 21:07
//
//	\brief	The Prototype Factory/Spawner class
//=============================================================
class MonsterSpawner final
{
	Monster* m_pPrototype;
public:
	MonsterSpawner( Monster* monsterPrototype );

	std::unique_ptr<Monster> spawnMonster();
};

//===================================================
//	\function	spawnMonsterArray
//	\brief  use this helper function as a factory for arrays of objects
//				spawned from supplied prototypical instance
//	\date	2020/11/02 22:03
template<typename T, typename = std::enable_if_t<std::is_base_of_v<Monster, T>>>
std::vector<std::unique_ptr<Monster>> spawnMonsterArray( MonsterSpawner* monsterFactory,
	std::size_t count )
{
	std::vector<std::unique_ptr<Monster>> monsters;
	monsters.reserve( count );
	for ( std::size_t i = 0; i < count; ++i )
	{
		monsters.emplace_back( monsterFactory->spawnMonster() );
	}
	return monsters;
}
