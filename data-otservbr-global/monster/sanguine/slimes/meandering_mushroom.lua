local mType = Game.createMonsterType("Meandering Mushroom")
local monster = {}

monster.description = "a meandering mushroom"
monster.experience = 21980
monster.outfit = {
	lookType = 1621,
	lookHead = 0,
	lookBody = 0,
	lookLegs = 0,
	lookFeet = 0,
	lookAddons = 0,
	lookMount = 0,
}

monster.raceId = 2376
monster.Bestiary = {
	class = "Slime",
	race = BESTY_RACE_SLIME,
	toKill = 5000,
	FirstUnlock = 200,
	SecondUnlock = 2000,
	CharmsPoints = 100,
	Stars = 5,
	Occurrence = 0,
	Locations = "Putrefactory.",
}

monster.health = 29100
monster.maxHealth = 29100
monster.race = "undead"
monster.corpse = 43559
monster.speed = 205
monster.manaCost = 0

monster.changeTarget = {
	interval = 5000,
	chance = 0,
}

monster.strategiesTarget = {
	nearest = 70,
	health = 10,
	damage = 10,
	random = 10,
}

monster.flags = {
	summonable = false,
	attackable = true,
	hostile = true,
	convinceable = false,
	pushable = false,
	rewardBoss = false,
	illusionable = false,
	canPushItems = true,
	canPushCreatures = false,
	staticAttackChance = 85,
	targetDistance = 0,
	runHealth = 0,
	healthHidden = false,
	isBlockable = false,
	canWalkOnEnergy = false,
	canWalkOnFire = false,
	canWalkOnPoison = true,
}

monster.light = {
	level = 0,
	color = 0,
}


monster.voices = {
	interval = 5000,
	chance = 10,
	{ text = "twiggle*", yell = false },
	{ text = "SSSSHRRR", yell = false },
}

monster.loot = {
	{ name = "crystal coin", chance = 67550, maxCount = 2 },
	{ name = "darklight core", chance = 7920 },
	{ id = 3039, chance = 4910 },
	{ name = "darklight matter", chance = 3020 },
	{ name = "rubber cap", chance = 2640 },
	{ id = 23544, chance = 750 },
	{ id = 3038, chance = 750 },
	{ name = "shadow sceptre", chance = 750},
	{ id = 43895, chance = 5 },
}

monster.attacks = {
	{ name = "melee", interval = 2000, chance = 100, minDamage = 0, maxDamage = -1150 },
	{ name = "combat", interval = 2500, chance = 15, type = COMBAT_DEATHDAMAGE, minDamage = -1800, maxDamage = -1900, radius = 5, effect = CONST_ME_MORTAREA, target = true },
	{ name = "combat", interval = 2500, chance = 15, type = COMBAT_DEATHDAMAGE, minDamage = -1700, maxDamage = -1700, radius = 5, effect = CONST_ME_INSECTS, target = true },
	{ name = "combat", interval = 2500, chance = 20, type = COMBAT_ICEDAMAGE, minDamage = -1100, maxDamage = -1300, length = 8, spread = 5, effect = CONST_ME_BLACKSMOKE, target = false },
	{ name = "largeblackring", interval = 2000, chance = 10, minDamage = -900, maxDamage = -1500, target = false },
}

monster.defenses = {
	defense = 115,
	armor = 115,
	mitigation = 3.19,
}

monster.elements = {
	{ type = COMBAT_PHYSICALDAMAGE, percent = 0 },
	{ type = COMBAT_ENERGYDAMAGE, percent = 25 },
	{ type = COMBAT_EARTHDAMAGE, percent = -20 },
	{ type = COMBAT_FIREDAMAGE, percent = -10 },
	{ type = COMBAT_LIFEDRAIN, percent = 0 },
	{ type = COMBAT_MANADRAIN, percent = 0 },
	{ type = COMBAT_DROWNDAMAGE, percent = 0 },
	{ type = COMBAT_ICEDAMAGE, percent = 40 },
	{ type = COMBAT_HOLYDAMAGE, percent = -15 },
	{ type = COMBAT_DEATHDAMAGE, percent = 50 },
}

monster.immunities = {
	{ type = "paralyze", condition = false },
	{ type = "outfit", condition = false },
	{ type = "invisible", condition = false },
	{ type = "bleed", condition = false },
}

mType:register(monster)
