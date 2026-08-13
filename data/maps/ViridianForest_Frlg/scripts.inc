ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

@ ViridianForest_EventScript_Youngster::
@	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
@	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

@ ViridianForest_EventScript_Doug::
@	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
@	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
@	msgbox ViridianForest_Text_DougPostBattle
@	releaseall
@	end

@ ViridianForest_EventScript_Sammy::
@ 	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
@ 	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
@ 	end

@ ViridianForest_EventScript_Charlie::
@ 	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
@ 	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
@ 	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "I came here with some friends to\n"
	.string "catch us some BUG POKéMON!\p"
	.string "They're all itching to get into\n"
	.string "some POKéMON battles!$"

@ ViridianForest_Text_DougIntro::
@ 	.string "Yo!\n"
@ 	.string "You can't jam out if you're a\l"
@ 	.string "POKéMON TRAINER!$"

@ ViridianForest_Text_DougDefeat::
@ 	.string "Huh?\n"
@ 	.string "I ran out of POKéMON!$"

@ ViridianForest_Text_DougPostBattle::
@ 	.string "That totally stinks! I'm going to\n"
@ 	.string "catch some stronger ones!$"

@ ViridianForest_Text_SammyIntro::
@ 	.string "Hey, wait up!\n"
	.string "What's the hurry? Why the rush?$"

@ ViridianForest_Text_SammyDefeat::
@ 	.string "I give!\n"
@ 	.string "You're good at this!$"

@ ViridianForest_Text_SammyPostBattle::
@ 	.string "Sometimes, you can find stuff on\n"
@ 	.string "the ground.\p"
@ 	.string "I'm looking for the stuff I\n"
@ 	.string "dropped. Can you help me?$"

@ ViridianForest_Text_CharlieIntro::
@ 	.string "Did you know that POKéMON evolve?$"

@ ViridianForest_Text_CharlieDefeat::
@ 	.string "Oh!\n"
@ 	.string "I lost!$"

@ ViridianForest_Text_CharliePostBattle::
@ 	.string "BUG POKéMON evolve quickly.\n"
@ 	.string "They're a lot of fun!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "I was throwing POKé BALLS to\n"
	.string "catch POKéMON, and I ran out.\p"
	.string "That's why you can never have too\n"
	.string "many POKé BALLS.$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "TRAINER TIPS\p"
	.string "If your POKéMON are weak and you\n"
	.string "want to avoid battles, stay away\l"
	.string "from grassy areas!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "TRAINER TIPS\p"
	.string "For poison, use ANTIDOTE!\n"
	.string "Get it at POKéMON MARTS!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "TRAINER TIPS\p"
	.string "Contact PROF. OAK via a PC to\n"
	.string "get your POKéDEX evaluated!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "TRAINER TIPS\p"
	.string "You can't catch a POKéMON that\n"
	.string "belongs to someone else.\p"
	.string "Throw POKé BALLS only at wild\n"
	.string "POKéMON to catch them!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "TRAINER TIPS\p"
	.string "Weaken POKéMON before attempting\n"
	.string "capture!\p"
	.string "When healthy, they may escape!$"

ViridianForest_Text_LeavingViridianForest::
	.string "LEAVING VIRIDIAN FOREST\n"
	.string "PEWTER CITY AHEAD$"
	
	
ViridianForest_EventScript_Caterpie::
	setwildbattle SPECIES_CATERPIE, 6
	dowildbattle
	setvar VAR_MAP_SCENE_VIRIDIAN_FOREST, 1
	end
	
ViridianForest_EventScript_Pidgeotto::
	setwildbattle SPECIES_PIDGEOTTO, 8
	dowildbattle
	setvar VAR_MAP_SCENE_VIRIDIAN_FOREST, 2
	end
	




ViridianForest_EventScript_TR_Battle::
	lock
	faceplayer
	message ViridianForest_Text_TeamRocket_Intro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_VIRIDIAN_FOREST_ROCKETS ViridianForest_Text_TeamRocket_Defeat
	msgbox ViridianForest_Text_TeamRocket_Boss
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_BANG
	removeobject LOCALID_VIRIDIANFOREST_JESSIE
	removeobject LOCALID_VIRIDIANFOREST_JAMES
	removeobject LOCALID_VIRIDIANFOREST_MEOWTH
	setflag FLAG_HIDE_VIRFOREST_TR
	waitse
	delay 60
	fadescreen FADE_FROM_BLACK
	releaseall
	end
	
ViridianForest_EventScript_Samurai::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMURAI, ViridianForest_Text_SamuraiIntro, ViridianForest_Text_SamuraiDefeat
	msgbox ViridianForest_Text_SamuraiPostBattle, MSGBOX_AUTOCLOSE
	end
	
ViridianForest_EventScript_Heal::
	special HealPlayerParty
	releaseall
	end
	
	
ViridianForest_EventScript_Neesha_Left_Trigger::
	lockall
	setvar VAR_TEMP_1, 0
	goto ViridianForest_EventScript_Neesha
	end
	
ViridianForest_EventScript_Neesha_Right_Trigger::
	setvar VAR_TEMP_1, 1
	lockall
	goto ViridianForest_EventScript_Neesha
	end
	
	
ViridianForest_EventScript_Neesha::
	textcolor NPC_TEXT_COLOR_FEMALE
	@ playbgm
	applymovement LOCALID_VIRIDIAN_FOREST_NEESHA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_VIRIDIAN_FOREST_NEESHA, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, ViridianForest_EventScript_NeeshaApproachLeft
	call_if_eq VAR_TEMP_1, 1, ViridianForest_EventScript_NeeshaApproachRight
	msgbox ViridianForest_Text_NeeshaOtherKid
	setvar VAR_LAST_TALKED, LOCALID_VIRIDIAN_FOREST_NEESHA
 	trainerbattle_no_intro TRAINER_RIVAL_NEESHA, ViridianForest_Text_NeeshaDefeat
	msgbox ViridianForest_Text_NeeshaFun
	closemessage
	@ playbgm
	call ViridianForest_EventScript_EndNeeshaBattle
	@ fadedefaultbgm
	removeobject LOCALID_VIRIDIAN_FOREST_NEESHA
	playse SE_EXIT
	waitse
	setvar VAR_MAP_SCENE_VIRIDIAN_FOREST, 3
	setflag FLAG_HIDE_VIRIDIAN_FOREST_NEESHA
	releaseall
 	end
	
	
ViridianForest_EventScript_EndNeeshaBattle::
	applymovement LOCALID_VIRIDIAN_FOREST_NEESHA, ViridianForest_Movement_NeeshaExit
	waitmovement 0
	return
	
	
ViridianForest_EventScript_NeeshaApproachLeft::
	closemessage
	applymovement LOCALID_VIRIDIAN_FOREST_NEESHA, ViridianForest_Movement_NeeshaApproachLeft
	waitmovement 0
	return

ViridianForest_EventScript_NeeshaApproachRight::
	return

ViridianForest_Movement_NeeshaApproachLeft::
	walk_left
	step_end


ViridianForest_Movement_NeeshaExit::
	walk_up
	walk_up
	delay_8
	step_end
	
	
ViridianForest_Text_TeamRocket_Intro::
	.string "JESSIE!\n"
	.string "JAMES!\p"
	.string "TEAM ROCKET, Blast off at the\n" 
	.string "speed of light!\p"
	.string "Surrender now, or prepare to fight!\n"
	.string "MEOWTH, dat's right!$"
	
ViridianForest_Text_TeamRocket_Defeat::
	.string "UH-OH! MEOWTH?!$"
	
ViridianForest_Text_TeamRocket_Boss::
	.string "We've got to get the twerp's POKéMON!\n"
	.string "The boss'll reward us then!$"
	
ViridianForest_Text_SamuraiIntro::
	.string "Hey! Are you the trainer from Pallet?\p"
	.string "The other trainers from Pallet were \n"
	.string "truly fierce! Are you?$"

ViridianForest_Text_SamuraiDefeat::
	.string "A truly fantastic battle!$"

ViridianForest_Text_SamuraiPostBattle::
	.string "I have a camp further in where you\n"
	.string "can heal.\p"
	.string "BEE careful around the BEEDRILL!$"

ViridianForest_Text_NeeshaOtherKid::
	.string "YO! Let's battle!$"

	
ViridianForest_Text_NeeshaIntro::
	.string "So you're the other kid from Pallet?\n"
	.string "I'm Neesha.\p"


ViridianForest_Text_NeeshaDefeat::
	.string "That was fun!$"
	
ViridianForest_Text_NeeshaFun::
	.string "Have you met {RIVAL}?\n"
	.string "He was rude, but strong.\p"
	.string "Hopefully we battle again {PLAYER}.$"