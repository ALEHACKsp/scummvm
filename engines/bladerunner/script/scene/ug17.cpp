/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/scene.h"

namespace BladeRunner {

void SceneScriptUG17::InitializeScene() {
	if (Game_Flag_Query(447)) {
		Setup_Scene_Information(1013.0f, 67.96f, -1892.0f, 525);
		Game_Flag_Reset(447);
	} else {
		Setup_Scene_Information(1000.0f, 67.96f, -1539.0f, 0);
	}
	Scene_Exit_Add_2D_Exit(0, 610, 0, 639, 479, 1);
	Scene_Exit_Add_2D_Exit(1, 551, 347, 594, 386, 0);
	Ambient_Sounds_Add_Looping_Sound(589, 100, 1, 1);
	Ambient_Sounds_Add_Looping_Sound(384, 50, 1, 1);
	Ambient_Sounds_Add_Sound(72, 5, 80, 10, 11, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(73, 5, 80, 10, 11, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(74, 5, 80, 10, 11, -100, 100, -101, -101, 0, 0);
	Overlay_Play("UG17OVER", 0, 1, 0, 0);
}

void SceneScriptUG17::SceneLoaded() {
	Obstacle_Object("BOX FOR BIG VENT13", true);
	Unclickable_Object("BOX FOR BIG VENT13");
}

bool SceneScriptUG17::MouseClick(int x, int y) {
	return false;
}

bool SceneScriptUG17::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool SceneScriptUG17::ClickedOnActor(int actorId) {
	return false;
}

bool SceneScriptUG17::ClickedOnItem(int itemId, bool a2) {
	return false;
}

bool SceneScriptUG17::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(kActorMcCoy, 1000.0f, 67.96f, -1539.0f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Set(353);
			Set_Enter(87, 99);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_XYZ(kActorMcCoy, 1013.0f, 67.96f, -1892.0f, 0, 1, false, 0)) {
			Actor_Face_Heading(kActorMcCoy, 89, false);
			if (Global_Variable_Query(1) == 5) {
				Actor_Says(kActorMcCoy, 8522, 14);
			} else {
				Loop_Actor_Travel_Ladder(kActorMcCoy, 10, 1, 0);
				Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
				Ambient_Sounds_Remove_All_Looping_Sounds(1);
				Game_Flag_Set(448);
				Set_Enter(17, 83);
			}
		}
		return true;
	}
	return false;
}

bool SceneScriptUG17::ClickedOn2DRegion(int region) {
	return false;
}

void SceneScriptUG17::SceneFrameAdvanced(int frame) {
}

void SceneScriptUG17::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void SceneScriptUG17::PlayerWalkedIn() {
	if (Game_Flag_Query(352)) {
		Loop_Actor_Walk_To_XYZ(kActorMcCoy, 961.0f, 67.96f, -1539.0f, 0, 0, false, 0);
		Game_Flag_Reset(352);
	}
	//return false;
}

void SceneScriptUG17::PlayerWalkedOut() {
}

void SceneScriptUG17::DialogueQueueFlushed(int a1) {
}

} // End of namespace BladeRunner
