/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2024 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include "lua/callbacks/creaturecallback.hpp"

bool CreatureCallback::startScriptInterface(int32_t scriptId) {
	if (scriptId == -1) {
		return false;
	}

	if (!LuaScriptInterface::reserveScriptEnv()) {
		const auto targetCreature = m_targetCreature.lock();
		g_logger().error(
			"[CreatureCallback::startScriptInterface] - {} {} Call stack overflow. Too many lua script calls being nested.",
			getCreatureClass(targetCreature),
			targetCreature->getName()
		);
		return false;
	}

	LuaScriptInterface::getScriptEnv()
		->setScriptId(scriptId, scriptInterface);

	L = scriptInterface->getLuaState();

	scriptInterface->pushFunction(scriptId);

	return true;
}

void CreatureCallback::pushSpecificCreature(const std::shared_ptr<Creature> &creature) {
	if (const auto &npc = creature->getNpc()) {
		LuaScriptInterface::pushUserdata<Npc>(L, npc);
	} else if (const auto &monster = creature->getMonster()) {
		LuaScriptInterface::pushUserdata<Monster>(L, monster);
	} else if (const auto &player = creature->getPlayer()) {
		LuaScriptInterface::pushUserdata<Player>(L, player);
	} else {
		return;
	}

	params++;
	LuaScriptInterface::setMetatable(L, -1, getCreatureClass(creature));
}

std::string CreatureCallback::getCreatureClass(const std::shared_ptr<Creature> &creature) {
	if (!creature) {
		return "";
	}
	if (creature->getNpc()) {
		return "Npc";
	}
	if (creature->getMonster()) {
		return "Monster";
	}
	if (creature->getPlayer()) {
		return "Player";
	}

	return "";
}
