# 1 "data/maps/PalletTown_Frlg/scripts.pory"

# 2 "data/maps/PalletTown_Frlg/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 3 "data/maps/PalletTown_Frlg/scripts.pory"

# 4 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Frlg_MapScripts::
# 5 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 6 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 7 "data/maps/PalletTown_Frlg/scripts.pory"
	.byte 0
# 8 "data/maps/PalletTown_Frlg/scripts.pory"

# 9 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_OnTransition::
# 10 "data/maps/PalletTown_Frlg/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 11 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 12 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 13 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 14 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 15 "data/maps/PalletTown_Frlg/scripts.pory"

# 16 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 17 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, Common_EventScript_NopReturn
# 18 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, Common_EventScript_NopReturn
# 19 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 20 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 21 "data/maps/PalletTown_Frlg/scripts.pory"

# 22 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 23 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 24 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 25 "data/maps/PalletTown_Frlg/scripts.pory"

# 26 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 27 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 28 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 5, 15
# 29 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 30 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 31 "data/maps/PalletTown_Frlg/scripts.pory"

# 32 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 33 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 12, 2
# 34 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 35 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 36 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 37 "data/maps/PalletTown_Frlg/scripts.pory"

# 38 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_OnFrame::
# 39 "data/maps/PalletTown_Frlg/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 40 "data/maps/PalletTown_Frlg/scripts.pory"
	.2byte 0
# 41 "data/maps/PalletTown_Frlg/scripts.pory"

# 42 "data/maps/PalletTown_Frlg/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 43 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 44 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 45 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 46 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectxyperm LOCALID_PALLET_PROF_OAK, 14, 14
# 47 "data/maps/PalletTown_Frlg/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 48 "data/maps/PalletTown_Frlg/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 49 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 50 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 51 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 52 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 53 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_0x8004, 0
# 54 "data/maps/PalletTown_Frlg/scripts.pory"
	specialvar VAR_RESULT, GetFrlgPokedexCount
# 55 "data/maps/PalletTown_Frlg/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 56 "data/maps/PalletTown_Frlg/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 57 "data/maps/PalletTown_Frlg/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 58 "data/maps/PalletTown_Frlg/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 59 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 60 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 61 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 62 "data/maps/PalletTown_Frlg/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 63 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 64 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 65 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 66 "data/maps/PalletTown_Frlg/scripts.pory"
	opendoor 16, 13
# 67 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 68 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 69 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 70 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 71 "data/maps/PalletTown_Frlg/scripts.pory"
	closedoor 16, 13
# 72 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 73 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 74 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 75 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 76 "data/maps/PalletTown_Frlg/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 77 "data/maps/PalletTown_Frlg/scripts.pory"
	waitstate
# 78 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 79 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 80 "data/maps/PalletTown_Frlg/scripts.pory"

# 81 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 82 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 83 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakExit
# 84 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 85 "data/maps/PalletTown_Frlg/scripts.pory"
	removeobject LOCALID_PALLET_PROF_OAK
# 86 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 87 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 88 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 89 "data/maps/PalletTown_Frlg/scripts.pory"

# 90 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 91 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 92 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 93 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 94 "data/maps/PalletTown_Frlg/scripts.pory"

# 95 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 96 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 97 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 98 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 99 "data/maps/PalletTown_Frlg/scripts.pory"

# 100 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 101 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 102 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 103 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 104 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 105 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 106 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 107 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 108 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 109 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 110 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 111 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 112 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 113 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 114 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 115 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 116 "data/maps/PalletTown_Frlg/scripts.pory"

# 117 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakExit::
# 118 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 119 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 120 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 121 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 122 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 124 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 125 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 126 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 127 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 128 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 129 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 130 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 131 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 132 "data/maps/PalletTown_Frlg/scripts.pory"

# 133 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 134 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 135 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 136 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 137 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 138 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 139 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 140 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 141 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 142 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 143 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 144 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 145 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 146 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 147 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 148 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 149 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 150 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 151 "data/maps/PalletTown_Frlg/scripts.pory"

# 152 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 153 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 154 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 155 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 156 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 157 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 158 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 159 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 160 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 161 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 162 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 163 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 164 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 165 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 166 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 167 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 168 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 169 "data/maps/PalletTown_Frlg/scripts.pory"

# 170 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 171 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 172 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_TEMP_1, 0
# 173 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_RivalSlowpoke
# 174 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 175 "data/maps/PalletTown_Frlg/scripts.pory"

# 176 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 177 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 178 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_TEMP_1, 1
# 179 "data/maps/PalletTown_Frlg/scripts.pory"
    goto PalletTown_EventScript_RivalSlowpoke
# 180 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 181 "data/maps/PalletTown_Frlg/scripts.pory"

# 182 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_RivalSlowpoke::
# 183 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 184 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 185 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_RIVAL, Common_Movement_FacePlayer
# 186 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_Rival_Gramps
# 187 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 188 "data/maps/PalletTown_Frlg/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 189 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 190 "data/maps/PalletTown_Frlg/scripts.pory"

# 191 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 192 "data/maps/PalletTown_Frlg/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 193 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 194 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 195 "data/maps/PalletTown_Frlg/scripts.pory"
	playbgm MUS_RG_OAK, 0
# 196 "data/maps/PalletTown_Frlg/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 197 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmessage
# 198 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 85
# 199 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 200 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 201 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 202 "data/maps/PalletTown_Frlg/scripts.pory"
	playse SE_PIN
# 203 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 204 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 205 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 206 "data/maps/PalletTown_Frlg/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 207 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 208 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 209 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 210 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 211 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 212 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 30
# 213 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 214 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 215 "data/maps/PalletTown_Frlg/scripts.pory"
	opendoor 16, 13
# 216 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 217 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 218 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 219 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 220 "data/maps/PalletTown_Frlg/scripts.pory"
	closedoor 16, 13
# 221 "data/maps/PalletTown_Frlg/scripts.pory"
	waitdooranim
# 222 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 223 "data/maps/PalletTown_Frlg/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 224 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 225 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 226 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 227 "data/maps/PalletTown_Frlg/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 228 "data/maps/PalletTown_Frlg/scripts.pory"
	waitstate
# 229 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 230 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 231 "data/maps/PalletTown_Frlg/scripts.pory"

# 232 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 233 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 234 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 235 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 236 "data/maps/PalletTown_Frlg/scripts.pory"

# 237 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 238 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterRight
# 239 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 240 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 241 "data/maps/PalletTown_Frlg/scripts.pory"

# 242 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 243 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 244 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 245 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 246 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 247 "data/maps/PalletTown_Frlg/scripts.pory"

# 248 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 249 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 250 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 251 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 252 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 253 "data/maps/PalletTown_Frlg/scripts.pory"

# 254 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 255 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 256 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 257 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 258 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 259 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 260 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 261 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 262 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 263 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 264 "data/maps/PalletTown_Frlg/scripts.pory"

# 265 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 266 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 267 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 268 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 269 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 270 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 271 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 272 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 273 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 274 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 275 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 276 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 277 "data/maps/PalletTown_Frlg/scripts.pory"

# 278 "data/maps/PalletTown_Frlg/scripts.pory"
	.macro walk_to_lab
# 279 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 280 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 281 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 282 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 283 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 284 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 285 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 286 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 287 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 288 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 289 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 290 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 291 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 292 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 293 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 294 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 295 "data/maps/PalletTown_Frlg/scripts.pory"
	.endm
# 296 "data/maps/PalletTown_Frlg/scripts.pory"

# 297 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 298 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 299 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 300 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 301 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 302 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 303 "data/maps/PalletTown_Frlg/scripts.pory"

# 304 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 305 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 306 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 307 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 308 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 309 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 310 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_up
# 311 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 312 "data/maps/PalletTown_Frlg/scripts.pory"

# 313 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 314 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 315 "data/maps/PalletTown_Frlg/scripts.pory"
	set_invisible
# 316 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 317 "data/maps/PalletTown_Frlg/scripts.pory"

# 318 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 319 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 320 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 321 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 322 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 323 "data/maps/PalletTown_Frlg/scripts.pory"

# 324 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 325 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 326 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 327 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_down
# 328 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 329 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_to_lab
# 330 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 331 "data/maps/PalletTown_Frlg/scripts.pory"

# 332 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 333 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 334 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_up
# 335 "data/maps/PalletTown_Frlg/scripts.pory"
	set_invisible
# 336 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 337 "data/maps/PalletTown_Frlg/scripts.pory"

# 338 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLady::
# 339 "data/maps/PalletTown_Frlg/scripts.pory"
	lock
# 340 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 341 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 342 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 343 "data/maps/PalletTown_Frlg/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 344 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 345 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 346 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 347 "data/maps/PalletTown_Frlg/scripts.pory"
	playse SE_PIN
# 348 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_ExclamationMark
# 349 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 350 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_Delay48
# 351 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 352 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 353 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 354 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 355 "data/maps/PalletTown_Frlg/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 356 "data/maps/PalletTown_Frlg/scripts.pory"
	copyobjectxytoperm LOCALID_PALLET_SIGN_LADY
# 357 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_TEMP_2
# 358 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 359 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 360 "data/maps/PalletTown_Frlg/scripts.pory"

# 361 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 362 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 363 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 364 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 365 "data/maps/PalletTown_Frlg/scripts.pory"

# 366 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 367 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 368 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 369 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 370 "data/maps/PalletTown_Frlg/scripts.pory"

# 371 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 372 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 373 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 374 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 375 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 376 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 377 "data/maps/PalletTown_Frlg/scripts.pory"

# 378 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 379 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 380 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 381 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 382 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 383 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 384 "data/maps/PalletTown_Frlg/scripts.pory"

# 385 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 386 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 387 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 388 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 389 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 390 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 391 "data/maps/PalletTown_Frlg/scripts.pory"

# 392 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 393 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_right
# 394 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_left
# 395 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 396 "data/maps/PalletTown_Frlg/scripts.pory"

# 397 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 398 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_left
# 399 "data/maps/PalletTown_Frlg/scripts.pory"
	walk_in_place_faster_right
# 400 "data/maps/PalletTown_Frlg/scripts.pory"
	step_end
# 401 "data/maps/PalletTown_Frlg/scripts.pory"

# 402 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_FatMan::
# 403 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 404 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 405 "data/maps/PalletTown_Frlg/scripts.pory"

# 406 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 407 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 408 "data/maps/PalletTown_Frlg/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 409 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 410 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 411 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 412 "data/maps/PalletTown_Frlg/scripts.pory"

# 413 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 414 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 415 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 416 "data/maps/PalletTown_Frlg/scripts.pory"

# 417 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 418 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 419 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 420 "data/maps/PalletTown_Frlg/scripts.pory"

# 421 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TownSign::
# 422 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 423 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 424 "data/maps/PalletTown_Frlg/scripts.pory"

# 425 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 426 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 427 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 428 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 429 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 430 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 431 "data/maps/PalletTown_Frlg/scripts.pory"

# 432 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 433 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 434 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 435 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 436 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 437 "data/maps/PalletTown_Frlg/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 438 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
# 439 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 440 "data/maps/PalletTown_Frlg/scripts.pory"

# 441 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 442 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 443 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 444 "data/maps/PalletTown_Frlg/scripts.pory"
	closemessage
# 445 "data/maps/PalletTown_Frlg/scripts.pory"
	delay 20
# 446 "data/maps/PalletTown_Frlg/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 447 "data/maps/PalletTown_Frlg/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 448 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 449 "data/maps/PalletTown_Frlg/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 450 "data/maps/PalletTown_Frlg/scripts.pory"
	special SetWalkingIntoSignVars
# 451 "data/maps/PalletTown_Frlg/scripts.pory"
	special DisableMsgBoxWalkaway
# 452 "data/maps/PalletTown_Frlg/scripts.pory"
	signmsg
# 453 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 454 "data/maps/PalletTown_Frlg/scripts.pory"
	normalmsg
# 455 "data/maps/PalletTown_Frlg/scripts.pory"
	return
# 456 "data/maps/PalletTown_Frlg/scripts.pory"

# 457 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 458 "data/maps/PalletTown_Frlg/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 459 "data/maps/PalletTown_Frlg/scripts.pory"
	waitmovement 0
# 460 "data/maps/PalletTown_Frlg/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 461 "data/maps/PalletTown_Frlg/scripts.pory"
	release
# 462 "data/maps/PalletTown_Frlg/scripts.pory"
	end
# 463 "data/maps/PalletTown_Frlg/scripts.pory"

# 464 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_Rival_Gramps::
# 465 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "{RIVAL}: Hey Slowpoke!\n"
# 466 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Gramps already gave me his best POKéMON!$"
# 467 "data/maps/PalletTown_Frlg/scripts.pory"

# 468 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakDontGoOut::
# 469 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Hey! Wait!\n"
# 470 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Don't go out!$"
# 471 "data/maps/PalletTown_Frlg/scripts.pory"

# 472 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakGrassUnsafeNeedMon::
# 473 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: It's unsafe!\n"
# 474 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Wild POKéMON live in tall grass!\p"
# 475 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You need your own POKéMON for\n"
# 476 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "your protection.\p"
# 477 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I know!\n"
# 478 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Here, come with me!$"
# 479 "data/maps/PalletTown_Frlg/scripts.pory"

# 480 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_RaisingMonsToo::
# 481 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I'm raising POKéMON, too.\p"
# 482 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "When they get strong, they can\n"
# 483 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "protect me.$"
# 484 "data/maps/PalletTown_Frlg/scripts.pory"

# 485 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CanStoreItemsAndMonsInPC::
# 486 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Technology is incredible!\p"
# 487 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You can now store and recall items\n"
# 488 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "and POKéMON as data via PC.$"
# 489 "data/maps/PalletTown_Frlg/scripts.pory"

# 490 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakPokemonResearchLab::
# 491 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK POKéMON RESEARCH LAB$"
# 492 "data/maps/PalletTown_Frlg/scripts.pory"

# 493 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PlayersHouse::
# 494 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "{PLAYER}'s house$"
# 495 "data/maps/PalletTown_Frlg/scripts.pory"

# 496 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_RivalsHouse::
# 497 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "{RIVAL}'s house$"
# 498 "data/maps/PalletTown_Frlg/scripts.pory"

# 499 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_TownSign::
# 500 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "PALLET TOWN\n"
# 501 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Shades of your journey await!$"
# 502 "data/maps/PalletTown_Frlg/scripts.pory"

# 503 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakLetMeSeePokedex::
# 504 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Ah, {PLAYER}!\n"
# 505 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You're back, are you?\p"
# 506 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "How much have you filled in your\n"
# 507 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "POKéDEX?\p"
# 508 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "May I see it?\p"
# 509 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Let's see…$"
# 510 "data/maps/PalletTown_Frlg/scripts.pory"

# 511 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CaughtXPuttingInHonestEffort::
# 512 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You've caught {STR_VAR_2}…\p"
# 513 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hm, it looks as if you're putting\n"
# 514 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "in an honest effort.\p"
# 515 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "When you manage to fill it some\n"
# 516 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "more, come show me, please.$"
# 517 "data/maps/PalletTown_Frlg/scripts.pory"

# 518 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_CaughtXImpressiveFollowMe::
# 519 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You've caught… {STR_VAR_2}!?\n"
# 520 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Now, this is impressive!\p"
# 521 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "There's something I wanted to ask\n"
# 522 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "of you, {PLAYER}.\p"
# 523 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Come.\n"
# 524 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Follow me.$"
# 525 "data/maps/PalletTown_Frlg/scripts.pory"

# 526 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OakYouEnjoyingTraveling::
# 527 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "OAK: Ah, {PLAYER}!\n"
# 528 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "You seem to be enjoying traveling.\p"
# 529 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Knowing you, {PLAYER}, I can easily\n"
# 530 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "imagine you going out to even more\l"
# 531 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "exotic locales.\p"
# 532 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Good for you, good for you.\n"
# 533 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hohoho.$"
# 534 "data/maps/PalletTown_Frlg/scripts.pory"

# 535 "data/maps/PalletTown_Frlg/scripts.pory"
@ For the NPC in Pallet Town that talks about the Trainer Tips sign
# 536 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_HmmIsThatRight::
# 537 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Hmm…\n"
# 538 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Is that right…$"
# 539 "data/maps/PalletTown_Frlg/scripts.pory"

# 540 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_OhLookLook::
# 541 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Oh!\n"
# 542 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Look, look!$"
# 543 "data/maps/PalletTown_Frlg/scripts.pory"

# 544 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_ReadItReadIt::
# 545 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Read it, read it!$"
# 546 "data/maps/PalletTown_Frlg/scripts.pory"

# 547 "data/maps/PalletTown_Frlg/scripts.pory"
@ Used by sign
# 548 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PressStartToOpenMenu::
# 549 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "TRAINER TIPS\p"
# 550 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Press START to open the MENU!$"
# 551 "data/maps/PalletTown_Frlg/scripts.pory"

# 552 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_SignsAreUsefulArentThey::
# 553 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Signs are useful, aren't they?$"
# 554 "data/maps/PalletTown_Frlg/scripts.pory"

# 555 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_LookCopiedTrainerTipsSign::
# 556 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Look, look!\p"
# 557 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "I copied what it said on one of\n"
# 558 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "those TRAINER TIPS signs!$"
# 559 "data/maps/PalletTown_Frlg/scripts.pory"

# 560 "data/maps/PalletTown_Frlg/scripts.pory"
@ Used by NPC
# 561 "data/maps/PalletTown_Frlg/scripts.pory"
PalletTown_Text_PressStartToOpenMenuCopy::
# 562 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "TRAINER TIPS!\p"
# 563 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Press START to open the MENU!$"

PalletTown_EventScript_GreensHouseSign::
# 567 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 568 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_EventScript_GreensHouseSign_Text_0
# 569 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
	return


PalletTown_EventScript_RedsHouseSign::
# 574 "data/maps/PalletTown_Frlg/scripts.pory"
	lockall
# 575 "data/maps/PalletTown_Frlg/scripts.pory"
	msgbox PalletTown_EventScript_RedsHouseSign_Text_0
# 576 "data/maps/PalletTown_Frlg/scripts.pory"
	releaseall
	return


PalletTown_EventScript_GreensHouseSign_Text_0:
# 568 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Green's House$"

PalletTown_EventScript_RedsHouseSign_Text_0:
# 575 "data/maps/PalletTown_Frlg/scripts.pory"
	.string "Red's House$"
