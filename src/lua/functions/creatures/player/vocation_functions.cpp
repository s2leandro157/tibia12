/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2024 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include "lua/functions/creatures/player/vocation_functions.hpp"

#include "creatures/players/vocations/vocation.hpp"

int VocationFunctions::luaVocationCreate(lua_State* L) {
	// Vocation(id or name)
	uint16_t vocationId;
	if (isNumber(L, 2)) {
		vocationId = getNumber<uint16_t>(L, 2);
	} else {
		vocationId = g_vocations().getVocationId(getString(L, 2));
	}

	const auto &vocation = g_vocations().getVocation(vocationId);
	if (vocation) {
		pushUserdata<Vocation>(L, vocation);
		setMetatable(L, -1, "Vocation");
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetId(lua_State* L) {
	// vocation:getId()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getId());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetClientId(lua_State* L) {
	// vocation:getClientId()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getClientId());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetBaseId(lua_State* L) {
	// vocation:getBaseId()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getBaseId());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetName(lua_State* L) {
	// vocation:getName()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		pushString(L, vocation->getVocName());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetDescription(lua_State* L) {
	// vocation:getDescription()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		pushString(L, vocation->getVocDescription());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetRequiredSkillTries(lua_State* L) {
	// vocation:getRequiredSkillTries(skillType, skillLevel)
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		const skills_t skillType = getNumber<skills_t>(L, 2);
		const uint16_t skillLevel = getNumber<uint16_t>(L, 3);
		lua_pushnumber(L, vocation->getReqSkillTries(skillType, skillLevel));
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetRequiredManaSpent(lua_State* L) {
	// vocation:getRequiredManaSpent(magicLevel)
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		const uint32_t magicLevel = getNumber<uint32_t>(L, 2);
		lua_pushnumber(L, vocation->getReqMana(magicLevel));
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetCapacityGain(lua_State* L) {
	// vocation:getCapacityGain()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getCapGain());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetHealthGain(lua_State* L) {
	// vocation:getHealthGain()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getHPGain());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetHealthGainTicks(lua_State* L) {
	// vocation:getHealthGainTicks()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getHealthGainTicks());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetHealthGainAmount(lua_State* L) {
	// vocation:getHealthGainAmount()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getHealthGainAmount());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetManaGain(lua_State* L) {
	// vocation:getManaGain()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getManaGain());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetManaGainTicks(lua_State* L) {
	// vocation:getManaGainTicks()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getManaGainTicks());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetManaGainAmount(lua_State* L) {
	// vocation:getManaGainAmount()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getManaGainAmount());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetMaxSoul(lua_State* L) {
	// vocation:getMaxSoul()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getSoulMax());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetSoulGainTicks(lua_State* L) {
	// vocation:getSoulGainTicks()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getSoulGainTicks());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetBaseAttackSpeed(lua_State* L) {
	// vocation:getBaseAttackSpeed()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getBaseAttackSpeed());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetAttackSpeed(lua_State* L) {
	// vocation:getAttackSpeed()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getAttackSpeed());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetBaseSpeed(lua_State* L) {
	// vocation:getBaseSpeed()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (vocation) {
		lua_pushnumber(L, vocation->getBaseSpeed());
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetDemotion(lua_State* L) {
	// vocation:getDemotion()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (!vocation) {
		lua_pushnil(L);
		return 1;
	}

	const uint16_t fromId = vocation->getFromVocation();
	if (fromId == VOCATION_NONE) {
		lua_pushnil(L);
		return 1;
	}

	const auto &demotedVocation = g_vocations().getVocation(fromId);
	if (demotedVocation && demotedVocation != vocation) {
		pushUserdata<Vocation>(L, demotedVocation);
		setMetatable(L, -1, "Vocation");
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int VocationFunctions::luaVocationGetPromotion(lua_State* L) {
	// vocation:getPromotion()
	const auto &vocation = getUserdataShared<Vocation>(L, 1);
	if (!vocation) {
		lua_pushnil(L);
		return 1;
	}

	const uint16_t promotedId = g_vocations().getPromotedVocation(vocation->getId());
	if (promotedId == VOCATION_NONE) {
		lua_pushnil(L);
		return 1;
	}

	const auto &promotedVocation = g_vocations().getVocation(promotedId);
	if (promotedVocation && promotedVocation != vocation) {
		pushUserdata<Vocation>(L, promotedVocation);
		setMetatable(L, -1, "Vocation");
	} else {
		lua_pushnil(L);
	}
	return 1;
}
