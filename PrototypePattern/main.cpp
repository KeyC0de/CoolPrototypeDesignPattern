#include <iostream>
#include "prototype.h"
#if defined _DEBUG && !defined NDEBUG
#	include <vld.h>
#endif


int main()
{
	// 1. Create the prototypes
	std::unique_ptr<Monster> skeletonPrototype = std::make_unique<Skeleton>();
	std::unique_ptr<Monster> zombiePrototype = std::make_unique<Zombie>();
	std::unique_ptr<Monster> vampirePrototype = std::make_unique<Vampire>();

	// 2. modify the prototypical objects here
	// ...

	// 3. create the factories
	std::unique_ptr<MonsterSpawner> skeletonFactory = std::make_unique<MonsterSpawner>( skeletonPrototype.get() );
	std::unique_ptr<MonsterSpawner> zombieFactory = std::make_unique<MonsterSpawner>( zombiePrototype.get() );
	std::unique_ptr<MonsterSpawner> vampireFactory = std::make_unique<MonsterSpawner>( vampirePrototype.get() );

	// 4. spawn copies of the prototype objects using the factories
	std::unique_ptr<Monster> skeleton = skeletonFactory->spawnMonster();
	std::unique_ptr<Monster> zombie = zombieFactory->spawnMonster();
	std::unique_ptr<Monster> vampire = vampireFactory->spawnMonster();

	skeleton->greet();
	zombie->greet();
	vampire->greet();

	// 5. create arrays of objects by copying the prototypes
	auto skeletons = spawnMonsterArray<Skeleton>( skeletonFactory.get(),
		10 );
	if ( auto* p = dynamic_cast<Skeleton*>( skeletons[1].get() ) )
	{
		std::cout << "Skeleton army incoming.\n";
	}
	
	auto zombies = spawnMonsterArray<Zombie>( zombieFactory.get(),
		10 );
	if ( auto* p = dynamic_cast<Skeleton*>( zombies[1].get() ) )
	{
		std::cout << "Skeleton army incoming.\n";
	}
	else
	{
		std::cout << "This is not a Skeleton army.\n";
	}
	if ( auto* p = dynamic_cast<Zombie*>( zombies[1].get() ) )
	{
		std::cout << "Zombie army incoming.\n";
	}
	
	auto vampires = spawnMonsterArray<Vampire>( vampireFactory.get(),
		10 );
	if ( auto*p = dynamic_cast<Vampire*>( vampires[1].get() ) )
	{
		std::cout << "Vampire army incoming.\n";
	}
	
	for ( const auto& i : skeletons )
	{
		i->greet();
	}
	for ( const auto& i : zombies )
	{
		i->greet();
	}
	for ( const auto& i : vampires )
	{
		i->greet();
	}

	std::system( "pause" );
	return 0;
}

