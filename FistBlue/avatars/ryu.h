/*
 *  ryu.h
 *  GLUTBasics
 *
 *  Created by Ben Torkington on 20/05/10.
 *  Copyright 2010 Ben Torkington. All rights reserved.
 *
 */


void pl_cb_setstatus1_ryu(Player *player, short status);
void pl_cb_setstatus2_ryu(Player *player, short status, int argd0);
void pl_cb_setstatus3_ryu(Player *player, short status);

void pl_cb_setstatus1_ken(Player *player, short status);
void pl_cb_setstatus2_ken(Player *player, short status, int argd0);
void pl_cb_setstatus3_ken(Player *player, short status);

void RyuKenStartHadouken(Player *ply);
void RyuSMHadouken(Player *ply);
void RyuSMHurricane(Player *ply);
void RyuStartShoryuken(Player *ply);
void RyuSMShoryuken(Player *ply);
void RyuStartHurricane(Player *ply);
void RyuSMHurricane(Player *ply);
short sub_2d7d2(Player *ply);

/*!
 sf2ua: 2d3a2
 @return the Y velocity
 */
int KenTrajectory(Player *ply);

int PLCBCompJumpRyuKen (Player *ply);	/* callback from 2c9be */
void PLCBCompAttackRyuKen(Player *ply);
short PLCBStandRyu(Player *ply);
short PLCBCrouchRyu(Player *ply);
void PLCBPowerRyu(Player *ply);
short PLCBJumpRyu(Player *ply);

void PSCBPowerRyu(Player *ply);
void PSCBAttackRyu(Player *ply);

void PSCBVictoryRyu(Player *ply);

struct UserData_RyuKen {
	u16		x0084;
	char	x0086;
	
	// State information for each of the Powermoves triggers
	char	FireballTriggerState[8];	// 0x90 
	char	HurricaneTriggerState[8];	// 0x98
	char	ShoryukenTriggerState[8];	// 0xa0

    // Powermove state machine
	char	x00c0;
	char	x00c1;
	char	x00c2;

	Object *x00d0;
	FIXED16_16	ShoryukenX;			/* 0xf0 */
	FIXED16_16  ShoryukenXDash;
	FIXED16_16	ShoryukenY;			/* f8 */
	FIXED16_16	ShoryukenYDash;	
} __attribute__((packed));

struct KenRyuInputs {
	u16 buttons; // %d0
	u16 stick; // %d6
};

#define STATUS_HADOUKEN     0x4c
#define STATUS_SHORYUKEN	0x4e
#define STATUS_HURRICANE	0x50


