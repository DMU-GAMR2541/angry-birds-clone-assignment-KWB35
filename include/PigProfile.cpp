#include "PigProfile.h"
#include "Pig.h"

static EntityData Small =
{
	"../assets/Ang_Birds/angry-birds-png-46187.png",
	30.0f,
	30.0f,
	0.6f,
	3.0f,
	0.3f,
	true,
};

static EntityData Med =
{
	"../assets/Ang_Birds/angry-birds-png-46187.png",
	50.0f,
	50.0f,
	1.0f,
	3.5f,
	0.3f,
	true,
};

static EntityData Large =
{
	"../assets/Ang_Birds/Angry_Birds_Pig2.PNG",
	75.0f,
	75.0f,
	1.5f,
	4.0f,
	0.3f,
	true,
};

const EntityData& getPigProfile(PigSize size)
{
	switch (size) 
	{
	case PigSize::Small: return Small;
	case PigSize::Med: return Med;
	case PigSize::Large: return Large;
	}
	return Med;
};