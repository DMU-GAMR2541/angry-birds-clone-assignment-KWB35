#include "BirdProfile.h"
#include "Bird.h"

static EntityData Red = //Sets the stats for the bird type
{
	"../assets/Ang_Birds/birds-png-3514.png",
	50.0f,
	50.0f,
	1.0f,
	4.0f,
	0.5f,
	true
};

static EntityData Yellow =
{
	"../assets/Ang_Birds/angry-birds-png-46179.png",
	50.0f,
	50.0f,
	1.0f,
	4.0f,
	0.5f,
	true
};

static EntityData Black =
{
	"../assets/Ang_Birds/angry-birds-png-46165.png",
	55.0f,
	55.0f,
	1.2f,
	4.0f,
	0.5f,
	true
};

static EntityData Blue =
{
	"../assets/Ang_Birds/angry-birds-png-46169.png",
	30.0f,
	30.0f,
	0.7f,
	3.0f,
	0.5f,
	true
};

const EntityData& getBirdProfile(Birdtype type) //returns which bird type is selected 
{
	switch (type) 
	{
	case Birdtype::Red: return Red;
	case Birdtype::Blue: return Blue;
	case Birdtype::Yellow: return Yellow;
	case Birdtype::Black: return Black;
	}
	return Red;
}