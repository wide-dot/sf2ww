/* player.c */

#include "sf2.h"

#include "structs.h"
#include "player.h"

#include "structs.h"
#include "particle.h"
#include "gfxlib.h"
#include "lib.h"
#include "sound.h"
#include "actions.h"

#include "playerstate.h"

#include "playerdata.h"

#include "ryu.h"
#include "guile.h"
#include "ehonda.h"
#include "blanka.h"
#include "chunli.h"

#include "dhalsim.h"
#include "mbison.h"


int PLCBStandZangeif(Player *ply);
int PLCBCrouchZangeif(Player *ply);
int PLCBJumpZangeif(Player *ply);
int PLCBPowerZangeif(Player *ply);
void pl_cb_setstatus1_zangeif(Player *ply, short status);
void pl_cb_setstatus2_zangeif(Player *ply, short status);
void pl_cb_setstatus3_zangeif(Player *ply, short status);


int PLCBStandDhalsim(Player *ply);
int PLCBCrouchDhalsim(Player *ply);
int PLCBJumpDhalsim(Player *ply);
int PLCBPowerDhalsim(Player *ply);
void pl_cb_setstatus1_dhalsim(Player *ply, short status);
void pl_cb_setstatus2_dhalsim(Player *ply, short status);
void pl_cb_setstatus3_dhalsim(Player *ply, short status);


extern Game g;
extern CAFrame **data_37f1e[];		// all player animations

DR dr;		// global damageresult

static void _ApplyDamageAdjustment(Player *opp, int damage, const char data[]);



void hitsound(int sound) {      /* 0x352a */
    queuesound(sound & 0xff);
}
int find_apex(Player *ply) {       /* 320e */
    int a,b;
    a = (ply->VelX.full >= 0);     /* zero considered positive */
    ply->VelX.full -= ply->AclX.full;
    b = (ply->VelX.full >= 0);     /* zero considered positive */
    if (a ^ b) {
        ply->VelX.full = 0;
    }
    ply->X.full += (ply->VelX.full << 8);
    if (ply->VelX.full == 0) {
        return FALSE;
    } else {
        return TRUE;
    }
}

void check_ply_x_bounds (Player *ply) {	/* 3232 verified */
    ply->BoundCheck = 0;
	
    if(ply->XPI <= (get_scr2x() + ply->Size)) {
        ply->BoundCheck = 1;                    /* against leftedge */
        if(ply->ThrowStat) {
            ply->Opponent->XPI += (get_scr2x() + ply->Size) - ply->XPI;
        }
		
        ply->XPI = (get_scr2x() + ply->Size);
    }
    if(ply->X.part.integer >= (get_scr2x() + (SCREEN_WIDTH - ply->Size))) {
        ply->BoundCheck = 2;                /* against rightedge */
        if(ply->ThrowStat) {
            ply->Opponent->XPI += (get_scr2x() + (SCREEN_WIDTH - ply->Size)) - ply->XPI;
        }
        ply->XPI = (get_scr2x() + (SCREEN_WIDTH - ply->Size));
    }
}        


void LBStartTimeWarp(void) {   /* 0x3534 */
    Object *obj;
    
    if(g.OnBonusStage) { return; }
	if((obj=AllocActor())) {
        g.FlagTimeWarp = TRUE;         /* time slows down */
        obj->exists	   = TRUE;
        obj->Sel       = SF2ACT_TIMEWARP;
        obj->SubSel    = 0x1;
        obj->UserByte  = 0x1;
    }
}

static void apply_throw_damage(Player *ply, Player *opp_a3, short index) {		///0x3560
	LBGetDamage(ply, opp_a3, index);
    opp_a3->UndealtDamage = dr.damage;
    opp_a3->RewardID = dr.d5;             /* score reward */
    if(g.FastEndingFight == 0 && g.OnBonusStage == 0) {
        if(opp_a3->Energy < dr.damage) { return; }
        
        /* player is knocked out */
        if(opp_a3->FighterID == FID_CHUN_LI) {
            queuesound(SOUND_KO_FEMALE);
        } else {
            queuesound(SOUND_KO_MALE);
        }
        opp_a3->Energy        = -1;
        opp_a3->UndealtDamage = 0;
        
        QueueEffect(opp_a3->RewardID, opp_a3->Side ^ 1);
		LBStartTimeWarp();
    } else {
        opp_a3->UndealtDamage    = 0;
        opp_a3->RewardID         = 0;
    }
}

int _EnergyDamageAdjust(Player *ply, int damage) {			// 3640 change to globals
    if (ply->Opponent->Energy >= 0x1f ) { return damage; }
    damage -= (data_93420[ply->Energy] * damage )/ 32;
    if (damage == 0) { damage = 1; }
    return damage;
}
void LBGetDamage(Player *ply, Player *opp, int index) {	/* 0x35c0 */
	/* XXX modify to return struct */
    if((index & 0x7f) >= 0x20) {
        dr.damage = data_99324[index/2][ply->Difficulty];
        dr.d5     = data_99544[index/2];
    } else {
        index -= 0x20;
        dr.d5=data_995a6[index/2];
        
        if(opp->Energy <= data_99566[index/2][1])          { dr.damage = data_99566[index/2][2];
        } else if (opp->Energy >= data_99566[index/2][3]) { dr.damage = data_99566[index/2][4];
        } else                { dr.damage = opp->Energy-(opp->Energy >> data_99566[index/2][0]); 
        }
    }       
    dr.damage=_EnergyDamageAdjust(ply, dr.damage);     /* diminish the damage */
}


void set_throw_trajectory(Player *ply, int trajectory, int direction, short damage) {	//3668 
    int temp;
	
    ply->Opponent->ThrowTrajectory = trajectory;
    ply->Opponent->Direction       = direction;
    apply_throw_damage(ply, ply->Opponent, damage);  /* slow time & make sound if KO'd */
    ply->Opponent->mode1 = PLSTAT_TUMBLE;
    ply->Opponent->mode2 = 0;
    ply->Opponent->mode3 = 0;
    
    temp = ply->Opponent->ThrownFromDizzy;
    ply->Opponent->ThrownFromDizzy = FALSE;
    if(temp==0) {
        player_check_dizzy(ply->Opponent);
    }
    LBThrowClear(ply, ply->Opponent);
} 

void ply_grip_release(Player *ply, int direction) {		//369a	
    Player *opp = ply->Opponent;
    opp->mode1 = 0xe;
    opp->mode2 = 0;
    opp->mode3 = 0;

    if(opp->DizzyFall) {
        ply->NextReactMode = 0x12;
        ply->ReactMode     = 0x12;
    } else {
        opp->NextReactMode = 0x10;	
        opp->ReactMode     = 0x10;     
    }
    opp->BlockStun = 0;
    opp->Direction = direction;
    LBThrowClear(ply, opp);
}


void sub_36d6(Player *ply, short x, short y, short throwtrajd0, char direction, int damage_d2, int sound_d6, short subsel_d3) {
// %d0 trajectory %d1 direction %d2 damage %d3 subsel %d4 = x %d5 = y %d6 = sound 
	Object *splash;
    int temp;

    ply->Opponent->ThrowTrajectory = throwtrajd0;
    ply->Opponent->Direction       = direction;
    if((splash=AllocActor()) ) {
        splash->exists     = TRUE;
        splash->Sel        = SF2ACT_HITSTUN;
		splash->SubSel	   = subsel_d3;
        splash->XPI        = ply->XPI;
        splash->YPI        = ply->YPI;
        splash->XPI += x;
        splash->YPI += y;
        splash->Owner = ply;
        splash->Flip  = ply->Opponent->Flip;
    }
    hitsound(sound_d6);
    
    if(g.FastEndingFight == 0 && g.OnBonusStage == 0) {
        LBGetDamage(ply, ply->Opponent, damage_d2);     /* calc, adjust damage based on difficulty */
        QueueEffect(dr.d5, ply->Side);					/* award points for hit */
        ply->Opponent->Energy     -= dr.damage;
        ply->Opponent->EnergyDash -= dr.damage;
        if (ply->EnergyDash <= 0) {
            LBStartTimeWarp();        
        }
    }
    ply->mode1 = PLSTAT_TUMBLE;
    ply->mode2 = 0;
    ply->mode3 = 0;
        
    temp = ply->ThrownFromDizzy;
    ply->ThrownFromDizzy = FALSE;
    if(temp==0) {
        player_check_dizzy(ply->Opponent);
    }
    LBThrowClear(ply, ply->Opponent);
}

void LBThrowClear(Player *ply, Player *opp) {		// 0x3764
    g.ThrowEndHoldoff = 28;
    g.PlayersThrowing = 0;
    ply->ThrowStat    = 0;
    opp->ThrowStat    = 0;
    opp->Attacking    = FALSE;
}


void LBInitHitBoxes(Player *ply) {	/* 388c initialise player hitboxes, vega clar */
    ply->exists = TRUE;
    ply->flag1  = TRUE;
    ply->HitBoxes = data_38e8[ply->FighterID].HitBoxList;
    ply->ThrowCatchX = data_38e8[ply->FighterID].ThrowX;
    ply->ThrowCatchY = data_38e8[ply->FighterID].ThrowY;
#if 0	
    if(ply->FighterID == FID_VEGA) {
        ply->Sprite2 = data_7b520;
        ply->VegaHasClaw = TRUE;
    }
#endif
    if(g.FastEndingFight || g.OnBonusStage) {
        ply->Energy     = 1;        /* Don't know why this is useful, but it makes using cheats */
        ply->EnergyDash = 1;        /* difficult */
    }
    sub_99142(ply);     /* set 38, 4f,50,51 */
}
    
void ply_thrown(Player *ply) {        /* 3948 data at 93440 */
    struct throwcatch {
        char x;
        char y;
        char drawOrder;
        char catchSprite;
    } __attribute__((packed));
    
    const void *opponent = RHOffsetLookup16(RHCODE(0x93440), ply->Opponent->FighterID);
    const struct throwcatch *catch = RHOffsetLookup16(opponent, ply->FighterID);
    
    ply->XPI = ply->Opponent->XPI + (ply->Opponent->Flip ? -catch->x : catch->x) ;
    ply->YPI = ply->Opponent->YPI + catch->y;
    
    g.PlyDrawOrder = (catch->drawOrder & 1) ^ ply->Side ^ 1;

    ply->Flip = ((catch->drawOrder & 0x20)>>5) ^ ply->Opponent->Flip;
    CASetAnim2(ply, STATUS_GETTING_THROWN, catch->catchSprite);
}
    
void random_damage_adjust_1(Player *ply, int damage_d0, int damage_d1) {			// 3f62
	const static char data_3fb8[32]={
		0,  -6,  -3,   0,   0,   0,   0,  -3,   
		0,   0,  -9,   0,   0,   0,  -6,  -9, 
		0,   0,   0,   0,   0,  -3,   0,   0,  
	   -3,   0,  -6,   0,   0,   0,   0,   0, 
	};
	ply->x0150 = damage_d1;
	
    _ApplyDamageAdjustment(ply->Opponent, damage_d0, data_3fb8);
    ply->Damage2 = ply->Damage1;
}
void random_damage_adjust_2(Player *ply, int damage) {			// 3f76
	const static char data_3f98[32]={
		0, -12,  -6,   0,   0,   0,   0,  -6,   
		0,   0,   0,   0,  -9,  -6,   0,   0, 
		0,  -9,   0,  -6,   0,   0,  -9,   0, 
	   -6,   0,   0,   0,  -9, -12, -15,   0, 
	};	
    _ApplyDamageAdjustment(ply->Opponent, damage, data_3f98);
}    

void _ApplyDamageAdjustment(Player *opp, int damage, const char data[]) {		/* 0x3f7e */
    opp->Damage1 = damage + data[RAND32];
}

void proc_player_actions(void) {		/* 282a8 */
	debughook(0);
	
	g.Player1.OldOldY = g.Player1.OldY;
	g.Player2.OldOldY = g.Player2.OldY;
	g.Player1.OldX = g.Player1.X;
	g.Player1.OldY = g.Player1.Y;
	g.Player2.OldX = g.Player2.X;
	g.Player2.OldY = g.Player2.Y;
	
	if(g.Player1.ThrowDisable) {g.Player1.ThrowDisable--;}
	if(g.Player2.ThrowDisable) {g.Player2.ThrowDisable--;}
	
	if(g.PlayersThrowing) {
			/* 0x28386 */
		PSEntry(g.CheckPlyFirst);
		PSEntry(g.CheckPlySecond);
	} else {
		if(0x55555555L & (RAND32 << 1)) {		// 50/50 chance
			g.PlayerFirst  = PLAYER2;
			g.PlayerSecond = PLAYER1;
		} else {
			g.PlayerFirst  = PLAYER1;
			g.PlayerSecond = PLAYER2;
		}
		PSEntry(g.PlayerFirst);
		if (g.PlayerFirst->ThrowStat) {
			g.CheckPlyFirst = g.PlayerFirst;		PSEntry(g.PlayerFirst);
			g.CheckPlySecond = g.PlayerSecond;		PSEntry(g.PlayerSecond);
			return;
		}
		PSEntry(g.PlayerSecond);
		if(g.PlayerSecond->ThrowStat) {
			g.CheckPlyFirst = g.PlayerSecond;		PSEntry(g.PlayerSecond);
			g.CheckPlySecond = g.PlayerFirst;		PSEntry(g.PlayerFirst);
			return;
		}
		g.GPCollDetect = 0;
		if(g.ThrowEndHoldoff) {
			g.ThrowEndHoldoff--;
		} else {
			ApplyPhysicsRules();		/* calc draw order, check direction, pushboxes etc. */
		}
	}
}

#pragma mark Callbacks to per-Avatar code

void check_powermove_input(Player *ply) { /* 2a7ea, actually void() */
	static void (* const data_2a7fa[])(Player *)={
		PLCBPowerRyu,
		PLCBPowerEHonda,		
		PLCBPowerBlanka,
		PLCBPowerGuile,
		PLCBPowerRyu,
		(void (*const)(Player *))PLCBPowerChunLi,
		(void (*const)(Player *))PLCBPowerZangeif,
		(void (*const)(Player *))PLCBPowerDhalsim
	} ; 
	return data_2a7fa[ply->FighterID](ply);
}

short ply_cb_standmove(Player *ply) {	/* 2a81a */
	static short (* const data_2a82a[])(Player *)={
		PLCBStandRyu,
		PLCBStandEHonda,		
		PLCBStandBlanka,
		PLCBStandGuile,
		PLCBStandRyu,
		(short (*const)(Player *))PLCBStandChunLi,
		(short (*const)(Player *))PLCBStandZangeif,
		(short (*const)(Player *))PLCBStandDhalsim,
	};
	return data_2a82a[ply->FighterID](ply);
}

short ply_cb_crouchmove(Player *ply) {	/* 2a84a */
	static short (* const data_2a85a[])(Player *)={
		PLCBCrouchRyu,
		PLCBCrouchEHonda,		
		PLCBCrouchBlanka,
		PLCBCrouchGuile,		
		PLCBCrouchRyu,
		(short (*const)(Player *))PLCBCrouchChunLi,
		(short (*const)(Player *))PLCBCrouchZangeif,
		(short (*const)(Player *))PLCBCrouchDhalsim,
	};			
	
	return data_2a85a[ply->FighterID](ply);
}

short ply_cb_jumpmove(Player *ply) {	/* 2a87a */
	static short (* const data_2a88a[])(Player *)={
		PLCBJumpRyu,
		PLCBJumpEHonda,		
		PLCBJumpBlanka,
		PLCBJumpGuile,
		PLCBJumpRyu,
		(short (*const)(Player *))PLCBJumpChunLi,
		(short (*const)(Player *))PLCBJumpZangeif,
		(short (*const)(Player *))PLCBJumpDhalsim,
	};
	return data_2a88a[ply->FighterID](ply);
}


static void (*const PL_CB_SETSTATUS3[])(Player *ply, short status)={
	pl_cb_setstatus3_ryu,
	pl_cb_setstatus3_ehonda,
	pl_cb_setstatus3_blanka,
	pl_cb_setstatus3_guile,
	pl_cb_setstatus3_ken,
	pl_cb_setstatus3_chunli,
	pl_cb_setstatus3_zangeif,
	pl_cb_setstatus3_dhalsim,
	pl_cb_setstatus3_mbison,
	NULL,
	NULL,
	NULL,
	
}; /* XXX */
static void (* const PL_CB_SETSTATUS2[])(Player *ply, short status, int argd0)={
	pl_cb_setstatus2_ryu,
	pl_cb_setstatus2_ehonda,
	pl_cb_setstatus2_blanka,
	pl_cb_setstatus2_guile,
	pl_cb_setstatus2_ken,
	pl_cb_setstatus2_chunli,
	(void (*const)(Player *, short, int))pl_cb_setstatus2_zangeif,
	(void (*const)(Player *, short, int))pl_cb_setstatus2_dhalsim,
	(void (*const)(Player *, short, int))pl_cb_setstatus2_mbison,
	NULL,
	NULL,
	NULL,
	
}; /* XXX */
static void (*const PL_CB_SETSTATUS1[])(Player *ply, short status)={
	pl_cb_setstatus1_ryu,
	pl_cb_setstatus1_ehonda,
	pl_cb_setstatus1_blanka,
	pl_cb_setstatus1_guile,
	pl_cb_setstatus1_ken,
	pl_cb_setstatus1_chunli,
	pl_cb_setstatus1_zangeif,
	pl_cb_setstatus1_dhalsim,
	pl_cb_setstatus1_mbison,
	NULL,
	NULL,
	NULL,
}; /* XXX */


void setstatus4(Player *ply, short d1) {
	NEXT(ply->mode2);
	CASetAnim2(ply, d1, ply->Move);
}

void CASetAnimWithStep(Player *ply, int status) {
    PL_CB_SETSTATUS3[ply->FighterID](ply, status);
}

void CASetAnim2(Player *ply, int statusd1, int argd0) {
    PL_CB_SETSTATUS2[ply->FighterID](ply, statusd1, argd0);
	
	/* instead, one day */
	/*
	 u16 *data_AvatarTiles[1] = {data_37f1e};
	 u16 *temp = data_AvatarTiles[ply->FighterID];
	 
	 setaction_list((Object *)ply, temp+(statusd1 >> 1), argd0);
	 */
}

void CASetAnim1(Player *ply, short status) {
    PL_CB_SETSTATUS1[ply->FighterID](ply, status);
}


void CASetAnim_BurningFall(Player *ply) {        /* 0x3a8e */
    RHSetAction((Object *)ply, RHCODE(0x3aa4));
}

void CASetAnim_IcyFall(Player *ply) {
    RHSetAction((Object *)ply, RHCODE(0x3bc8));
}



void sub_99142(Player *ply) {
    ply->MoreBoxes = data_991a4[ply->FighterID];    /* 32 bytes per player */
    
    ply->HitBoxUnused[0]  =
	ply->HitBoxUnused[1]  =
	ply->HitBoxUnused[2]  = 0;
}
