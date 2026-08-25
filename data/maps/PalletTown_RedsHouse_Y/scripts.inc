PalletTown_RedsHouse_Y_MapScripts::
	.byte 0


PalletTown_Redshouse_Get_Pikachu::
# 5 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	lockall
# 6 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	showmonpic SPECIES_PIKACHU, 10, 3
# 7 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox PalletTown_Redshouse_Get_Pikachu_Text_0, MSGBOX_YESNO
# 8 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_Redshouse_Get_Pikachu_2
# 33 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	hidemonpic
# 34 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox Pikachu_NotChosen
PalletTown_Redshouse_Get_Pikachu_1:
# 36 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	waitmessage
# 37 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	releaseall
	end

PalletTown_Redshouse_Get_Pikachu_2:
# 9 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	givemon SPECIES_PIKACHU, 5
# 10 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 11 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 13 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PalletTown_Redshouse_Get_Pikachu_5
# 20 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PalletTown_Redshouse_Get_Pikachu_6
# 28 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	hidemonpic
# 29 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox PalletTown_Redshouse_Get_Pikachu_Text_2
	goto PalletTown_Redshouse_Get_Pikachu_1

PalletTown_Redshouse_Get_Pikachu_5:
# 14 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 15 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox PalletTown_Redshouse_Get_Pikachu_Text_1
# 16 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	removeobject 2
# 17 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	setflag FLAG_HIDE_PIKACHU_BALL
# 18 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call NicknamePartyMon
	goto PalletTown_Redshouse_Get_Pikachu_1

PalletTown_Redshouse_Get_Pikachu_6:
# 21 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 22 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox PalletTown_Redshouse_Get_Pikachu_Text_1
# 23 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	removeobject 2
# 24 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	setflag FLAG_HIDE_PIKACHU_BALL
# 25 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call NicknameBoxMon
	goto PalletTown_Redshouse_Get_Pikachu_1


NicknamePartyMon::
# 43 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 44 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	hidemonpic
# 45 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 46 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 47 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 58 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 59 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	hidemonpic
# 60 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 63 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
# 61 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


PalletTown_Redshouse_Get_Pikachu_Text_0:
# 7 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	.string "Quite a polarized one, ehhh?$"

PalletTown_Redshouse_Get_Pikachu_Text_1:
# 15 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	.string "Got Pikachu$"

PalletTown_Redshouse_Get_Pikachu_Text_2:
# 29 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	.string "No More Room$"

NicknamePartyMon_Text_0:
# 43 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	.string "Give it a nickname?$"

Pikachu_NotChosen::
# 52 "data/maps/PalletTown_RedsHouse_Y/scripts.pory"
	.string "Too good for Pikachu?$"
