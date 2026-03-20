#ifndef SRTPLUGINRE9_ENEMYIDS_H
#define SRTPLUGINRE9_ENEMYIDS_H

#include <map>
#include <string>

constexpr uint16_t u16(int x) { return (uint16_t)(x); }

static const std::map<uint16_t, std::string> enemies = {
    {u16(58224), "The Girl"},
    {u16(58272), "The Girl Again?"},
    {u16(59088), "Gideon"},
    {u16(57264), "Zombie"},
    {u16(58032), "Zombie"},
    {u16(57744), "Zombie"},
    {u16(57744), "Zombie"},
    {u16(57312), "Zombie"},
	{u16(57648), "Zombie"},
	{u16(57504), "Organ Zombie"},
    {u16(57360), "Chef"},
    {u16(57408), "Singing Zombie"},
    {u16(58368), "Chunk"},
    {u16(57456), "Cleaning Zombie"},
    {u16(57552), "KEEEP IT DOWNNNNN Zombie"},
    {u16(58176), "Spider"},
    {u16(58128), "Licker"},
    {u16(57840), "Big Blisterhead"},
    {u16(57792), "Chainsaw Zombie"},
    {u16(57984), "BSAA Zombie"},
    {u16(58416), "Zombie Doggo"},
    {u16(58464), "Cool Motorcycle Gideon"},
    {u16(58992), "Creepy Orphan Child"},
    {u16(58560), "Mr. X"},
    {u16(58800), "Seedling"},
    {u16(58944), "Seedling"},
    {u16(58896), "Plant 42"},
    {u16(58608), "Soldier"},
    {u16(58656), "\"The Commander\""}
};

#endif // SRTPLUGINRE9_ENEMYIDS_H
