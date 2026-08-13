PewterCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_POKE_CENTER, 1
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
	.string "What!?\p"
	.string "TEAM ROCKET is at MT. MOON?\n"
	.string "Huh?\p"
	.string "I'm on the phone!\n"
	.string "Scram!$"

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
	.string "JIGGLYPUFF: Puu pupuu!$"

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
	.string "Yawn!\p"
	.string "When JIGGLYPUFF sings, POKéMON get\n"
	.string "drowsy…\p"
	.string "…Me, too…\n"
	.string "Snore…$"

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
	.string "I really want a PIKACHU, so I'm\n"
	.string "trading my CLEFAIRY for one.$"

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
	.string "I'm trading POKéMON with that kid\n"
	.string "there.\p"
	.string "I had two PIKACHU, so I figured\n"
	.string "I might as well trade one.$"


//Trigger Events
//Left
PewterCity_PokemonCenter_1F_TriggerEvent_CharmanderL::
	lock
	call PewterCity_PokemonCenter_1F_EventScript_NurseJoyHolla
	applymovement LOCALID_PLAYER, PewterCity_PokemonCenter_1F_Movement_L
	waitmovement 0
	call PewterCity_PokemonCenter_1F_EventScript_Charmander
	end

//Center
PewterCity_PokemonCenter_1F_TriggerEvent_CharmanderC::
	lock
	call PewterCity_PokemonCenter_1F_EventScript_NurseJoyHolla
	applymovement LOCALID_PLAYER, PewterCity_PokemonCenter_1F_Movement_C
	waitmovement 0
	call PewterCity_PokemonCenter_1F_EventScript_Charmander
	end

//Right
PewterCity_PokemonCenter_1F_TriggerEvent_CharmanderR::
	lock
	call PewterCity_PokemonCenter_1F_EventScript_NurseJoyHolla
	applymovement LOCALID_PLAYER, PewterCity_PokemonCenter_1F_Movement_R
	waitmovement 0
	call PewterCity_PokemonCenter_1F_EventScript_Charmander
	end


//NurseJoy Hollers at ya
PewterCity_PokemonCenter_1F_EventScript_NurseJoyHolla::
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox PewterCity_PokemonCenter_1F_Text_NurseJoyHolla
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	return
	
//NurseJoy Tells ya about Charmander
PewterCity_PokemonCenter_1F_EventScript_Charmander::
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox PewterCity_PokemonCenter_1F_Text_Worried
	setvar VAR_MAP_SCENE_ROUTE2_CHARMANDER, 2
	releaseall
	return


//Movement Events
//Center
PewterCity_PokemonCenter_1F_Movement_C::
	walk_up
	walk_up
	walk_up
	step_end

//Left	
PewterCity_PokemonCenter_1F_Movement_L::
	walk_up
	walk_right
	walk_up
	walk_up
	step_end
	
//Right
PewterCity_PokemonCenter_1F_Movement_R::
	walk_up
	walk_left
	walk_up
	walk_up
	step_end
	
//Dialogue
PewterCity_PokemonCenter_1F_Text_NurseJoyHolla::
	.string "Nurse Joy: HEY YOU!$"

PewterCity_PokemonCenter_1F_Text_Worried::
	.string "Earlier some trainer was bragging about\n"
	.string "leaving his CHARMANDER behind. \p"
	.string "It's about to storm real bad, and I'm\n"
	.string "worried about the POKéMON...\p"
	.string "Would you go save it?$"
