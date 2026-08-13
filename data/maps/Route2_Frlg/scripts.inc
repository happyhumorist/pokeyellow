Route2_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	.byte 0

Route2_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE2_CHARMANDER, 2, Route2_EventScript_Charmander_Weather
	end

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_Text_RouteSign::
	.string "ROUTE 2\n"
	.string "VIRIDIAN CITY - PEWTER CITY$"

Route2_Text_DiglettsCave::
	.string "DIGLETT'S CAVE$"

Route2_EventScript_Charmander::
	lockall
	goto_if_eq VAR_MAP_SCENE_ROUTE2_CHARMANDER, 0, Route2_EventScript_Charmander_Waiting
	goto_if_eq VAR_MAP_SCENE_ROUTE2_CHARMANDER, 1, Route2_EventScript_Charmander_Waiting
	call_if_eq VAR_MAP_SCENE_ROUTE2_CHARMANDER, 2, Route2_EventScript_Charmander_Tail
	releaseall
	end
	
Route2_EventScript_Charmander_Waiting::
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route2_Text_Charmander_Waiting
	setvar VAR_MAP_SCENE_ROUTE2_CHARMANDER, 1
	closemessage
	return
	
Route2_EventScript_Charmander_Tail::
	msgbox Route2_Text_Charmander_Tail
	msgbox Route2_Text_TakeCharmander, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route2_EventScript_WantCharmander
	goto_if_eq VAR_RESULT, NO, Route2_EventScript_NoCharmander
	closemessage
	return
	
Route2_EventScript_Charmander_Weather::
	setweather(WEATHER_DOWNPOUR)
	doweather
	releaseall
	end

Route2_EventScript_WantCharmander::
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route2_Text_WantCharmander
	closemessage
	givemon SPECIES_CHARMANDER, 10
	goto_if_eq VAR_RESULT, 0, Route2_EventScript_GetCharmanderParty
	goto_if_eq VAR_RESULT, 1, Route2_EventScript_GetCharmanderPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

Route2_EventScript_GetCharmanderParty::
	removeobject LOCALID_CHARMANDER
	playfanfare MUS_LEVEL_UP
	message Route2_Text_ObtainedCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route2_EventScript_SetGotCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route2_EventScript_SetGotCharmander
	end
	end

Route2_EventScript_GetCharmanderPC::
	removeobject LOCALID_CHARMANDER
	playfanfare MUS_LEVEL_UP
	message Route2_Text_ObtainedCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route2_EventScript_TransferCharmanderToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route2_EventScript_TransferCharmanderToPC
	end

Route2_EventScript_TransferCharmanderToPC::
	call Common_EventScript_TransferredToPC
	goto Route2_EventScript_SetGotCharmander
	end

Route2_EventScript_SetGotCharmander::
	setflag FLAG_GOT_CHARMANDER
	setvar VAR_MAP_SCENE_ROUTE2_CHARMANDER, 3
	release
	end


Route2_EventScript_NoCharmander::
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route2_Text_NoCharmander
	closemessage
	end

Route2_Text_Charmander_Waiting::
	.string "It seems like CHARMANDER is waiting\n"
	.string "for someone.$"
	
Route2_Text_Charmander_Tail::
	.string "CHARMANDER's tail might go out in the\n"
	.string "storm!\p"
	.string "It seems like it wants to go with you.$"
	
Route2_Text_TakeCharmander::
	.string "Will you take the CHARMANDER?$"
	
Route2_Text_NoCharmander::
	.string "CHARMANDER is distraught.$"
	
Route2_Text_WantCharmander::
	.string "CHARMANDER is relieved!$"
	
Route2_Text_ObtainedCharmander::
	.string "Got CHARMANDER!$"