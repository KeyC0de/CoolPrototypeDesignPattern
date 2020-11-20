#include "prototype.h"


int main()
{
	// 1. Create the prototypes
	std::unique_ptr<Monster> skeletonPrototype = std::make_unique<Skeleton>();
	std::unique_ptr<Monster> zombiePrototype = std::make_unique<Zombie>();
	std::unique_ptr<Monster> vampirePrototype = std::make_unique<Vampire>();

	// 2. modify the prototypical objects here

	// 3. create the factories
	MonsterFactory* skeletonFactory = new MonsterFactory{ skeletonPrototype.get() };
	MonsterFactory* zombieFactory = new MonsterFactory{ zombiePrototype.get() };
	MonsterFactory* vampireFactory = new MonsterFactory{ vampirePrototype.get() };

	// 4. spawn copies of the prototype objects using the factories
	Monster* skeleton = skeletonFactory->spawnMonster();
	Monster* zombie = zombieFactory->spawnMonster();
	Monster* vampire = vampireFactory->spawnMonster();

	skeleton->greet();
	zombie->greet();
	vampire->greet();

	// 5. create arrays of objects by copying the prototypes using the factories
	auto skeletons = spawnMonsterArray<Skeleton>( skeletonFactory, 10 );
	if ( auto*p = dynamic_cast<Skeleton*>( skeletons[1] ) )
	{
		std::wcout << L"Skeleton army incoming." << L'\n';
	}
	
	auto zombies = spawnMonsterArray<Zombie>( zombieFactory, 10 );
	if ( auto*p = dynamic_cast<Skeleton*>( zombies[1] ) )
	{
		std::wcout << L"Skeleton army incoming." << L'\n';
	}
	else
	{
		std::wcout << L"This is not a Skeleton army." << L'\n';
	}
	if ( auto*p = dynamic_cast<Zombie*>( zombies[1] ) )
	{
		std::wcout << L"Zombie army incoming." << L'\n';
	}
	
	auto vampires = spawnMonsterArray<Vampire>( vampireFactory, 10 );
	if ( auto*p = dynamic_cast<Vampire*>( vampires[1] ) )
	{
		std::wcout << L"Vampire army incoming." << L'\n';
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

