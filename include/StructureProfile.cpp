#include "StructureProfile.h"
#include "Structure.h"

static EntityData Wood =
{
	"../assets/Ang_Birds/NicePng_angry-gamer-png_2299190.PNG",
	100.0f,
	10.0f,
	1.0f,
	0.5f,
	0.3f,
	true
};

static EntityData Ice =
{
	"../assets/Ang_Birds/NicePng_stone-block-png_3097617.PNG",
	100.0f,
	10.0f,
	1.0f,
	0.5f,
	0.3f,
	true

};

static EntityData Stone =
{
	"../assets/Ang_Birds/NicePng_angry-gamer-png_2299190.PNG",
	100.0f,
	10.0f,
	1.0f,
	0.5f,
	0.3f,
	true
};

const EntityData& getStructProfile(StructType type)
{
	switch(type)
	{
	case StructType::Wood: return Wood;
	case StructType::Ice: return Ice;
	case StructType::Stone: return Stone;
	}
	return Wood;
}
