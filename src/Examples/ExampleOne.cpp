/*--
  Entage

	Copyrighted material. See LICENSE.txt for more information.
--*/

#include "Entage/Map/MapValue.h"
#include "Entage/Map/MapArray.h"
#include "Entage/Map/MapCompound.h"
#include "Entage/Map/ViewCompoundRoot.h"
#include "Entage/IO/JSON.h"

class Things : public Entage::ViewCompound
{
public:
	Things() :
		ENTAGE_MAP(ThingOne),
		ENTAGE_MAP(AnotherThing)
	{
	}

public:
	Entage::MapValue<std::string> ThingOne;
	Entage::MapValue<std::string> AnotherThing;
};

class Stuff : public Entage::ViewCompound
{
public:
	Stuff() :
		ENTAGE_MAP(Bob),
		ENTAGE_MAP(Fred),
		ENTAGE_MAP(MoreStuff),
		ENTAGE_MAP(EvenMore)
	{
	}

public:
	Entage::MapValue<int32_t> Bob;
	Entage::MapValue<std::string> Fred;
	Entage::MapArray<double> MoreStuff;
	Entage::MapCompound<Things> EvenMore;
};


int main()
{
	std::unique_ptr<Entage::TreeCompound> some_stuff(new Entage::TreeCompound);
	some_stuff->set("Bob", new Entage::TreeValue<int32_t>(23));
	some_stuff->set("Fred", new Entage::TreeValue<std::string>("Dibner"));

	std::unique_ptr<Entage::TreeArray<double> > more_stuff(new Entage::TreeArray<double>("Thing"));
	more_stuff->push_back(-82.993);
	more_stuff->push_back( 22.876);
	more_stuff->push_back(0.2);
	some_stuff->set("MoreStuff", more_stuff.release());

	std::unique_ptr<Entage::TreeCompound> compound_stuff(new Entage::TreeCompound());
	compound_stuff->set("ThingOne", new Entage::TreeValue<std::string>("Hello"));
	compound_stuff->set("AnotherThing", new Entage::TreeValue<std::string>("Bye"));
	some_stuff->set("EvenMore", compound_stuff.release());

	Entage::append_json(std::cout, *some_stuff);
	std::cout << std::endl;

	Entage::ViewCompoundRoot<Stuff> stuff(some_stuff.release());
	std::cout << "Example: " << stuff.Bob.value() << ", " << stuff.Fred.value() << std::endl;
	std::cout << "Example: " << stuff.EvenMore.ThingOne.value() << std::endl;
	for (const double& x : stuff.MoreStuff)
	{
		std::cout << "-- element: " << x << std::endl;
	}

	stuff.EvenMore.ThingOne.value() = "Something Else";
	std::cout << "Example changed: ";
	Entage::append_json(std::cout, * stuff.get_contents());
	std::cout << std::endl;

	std::cerr << "Finished" << std::endl;

}
