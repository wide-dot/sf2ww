/* rules.c */

#include "sf2types.h"
#include "sf2macros.h"
#include "sf2const.h"

#include "structs.h"
#include "player.h"

#include "particle.h"
#include "structs.h"

#include "lib.h"
#include "sf2io.h"

#include "rules.h"

#ifdef APPLICATION_TESTS
#include	<stdio.h>
#endif



extern Game g;

extern DR dr;			/* XXX yuck */

static void victory_p1(void);
static void victory_p2(void);
static void victory(void);
static void sub_86d4(void);
static void sub_89d4(short);
static void kill_ply1(void);
static void kill_ply2(void);
static int sub_4004(Player *ply);

static const u16 data_98f42[8][16][2] = {
	{ 
		{ 0x0000, 0x0018,  },
		{ 0x0000, 0x0030,  },
		{ 0x0000, 0x0050,  },
		{ 0x0000, 0x0088,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
		{ 0x0000, 0x00a8,  },
	},{ 
		{ 0x0018, 0x0030,  },
		{ 0x0018, 0x0048,  },
		{ 0x0018, 0x0068,  },
		{ 0x0018, 0x0098,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
		{ 0x0018, 0x00c0,  },
	},{ 
		{ 0x0028, 0x0040,  },
		{ 0x0028, 0x0058,  },
		{ 0x0028, 0x0078,  },
		{ 0x0028, 0x00a8,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
		{ 0x0028, 0x00d0,  },
	},{ 
		{ 0x0038, 0x0050,  },
		{ 0x0038, 0x0068,  },
		{ 0x0038, 0x0088,  },
		{ 0x0038, 0x00b8,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
		{ 0x0038, 0x00e0,  },
	},{ 
		{ 0x0048, 0x0060,  },
		{ 0x0048, 0x0078,  },
		{ 0x0048, 0x0098,  },
		{ 0x0048, 0x00c8,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
		{ 0x0048, 0x00f0,  },
	},{ 
		{ 0x0058, 0x0070,  },
		{ 0x0058, 0x0088,  },
		{ 0x0058, 0x00a8,  },
		{ 0x0058, 0x00d8,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
		{ 0x0058, 0x00ff,  },
	},{ 
		{ 0x0068, 0x0080,  },
		{ 0x0068, 0x0098,  },
		{ 0x0068, 0x00b8,  },
		{ 0x0068, 0x00e8,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
		{ 0x0068, 0x00ff,  },
	},{ 
		{ 0x0078, 0x0090,  },
		{ 0x0078, 0x00a8,  },
		{ 0x0078, 0x00c8,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
		{ 0x0078, 0x00ff,  },
	},
};
static char data_4976[256]={
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 
	0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
};
static char data_44f6[70]={
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
};


static u8 PLYWIDTHS[12]={0x28, 0x38, 0x35, 0x28, 0x28, 0x24, 0x2e, 0x28, 0x28, 0x2c, 0x28, 0x28};
static u8 PLYWIDTHS_SMALLER[12]=
{0x18, 0x2b, 0x21, 0x1c, 0x18, 0x20, 0x20, 0x1c, 0x20, 0x20, 0x1e, 0x23};


#ifdef APPLICATION_TESTS
int main(void) {
	printf("rules.c 0.01\n");
}
#endif

void set_fixed_difficulty(void) {				//2cb2
	g.Player1.Difficulty = 0x1f;
	g.Player2.Difficulty = 0x1f;
}

static void _KnockPlayerOut(Player *victim) {     /* 34ec player knocked out */
    victim->Energy = victim->EnergyDash = -1;
    LBStartTimeWarp();
    LBThrowClear(victim, victim->Opponent);
    victim->mode0 = PLMODE_KNOCKED_OUT;
    victim->mode1   = 0;
    victim->mode2   = 0;
    victim->mode3   = 0;
    victim->Attacking   = 0;
    victim->ProjHit = FALSE;
    victim->DizzyStun = FALSE;
    victim->ThrownFromDizzy = FALSE;
}


void check_level_sequence(Player *ply) {		// 0x2e94 player %a3
	int i=0;
	
	while (g.LevelScript[i+1] != 0x10) {
		if (g.LevelScript[i+1] == ply->FighterID) {
			g.LevelScript[i] = -1;
			g.LevelScript[i+1] = -1;
			return;
		}
		i += 2;
	}
}

void copy_level_table(short d0) {		// 2ecc 
	g.LevelCursor = 0;
	g.CurrentStage = 0;
	const u16 *data;
	int i;
	
	static const char data_94d60[8][16] = {
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
	};
	/* next address 00094de0 */
	static const u16 data_94de0[8][4][16] = {
		{ 
			{ 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0002, 0x0001, 0x0003, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0001, 0x0004, 0x0005, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0000, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0002, 0x0000, 0x0003, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0000, 0x0004, 0x0005, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0000, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0000, 0x0001, 0x0003, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0000, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0000, 0x0001, 0x0004, 0x0005, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0002, 0x0000, 0x0004, 0x0005, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0002, 0x0001, 0x0000, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0005, 0x0004, 0x0000, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0002, 0x0001, 0x0004, 0x0005, 0x0007, 0x0006, 0x0010, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0002, 0x0003, 0x0000, 0x0005, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0005, 0x0002, 0x0001, 0x0003, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0005, 0x0000, 0x0003, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0001, 0x0000, 0x0005, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0002, 0x0003, 0x0004, 0x0000, 0x0006, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0000, 0x0002, 0x0001, 0x0003, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0006, 0x0000, 0x0004, 0x0003, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0001, 0x0004, 0x0000, 0x0007, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0000, 0x0007, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0002, 0x0001, 0x0003, 0x0007, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0000, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0001, 0x0004, 0x0005, 0x0007, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{ 
			{ 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0000, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0005, 0x0002, 0x0001, 0x0003, 0x0000, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0003, 0x0002, 0x0001, 0x0004, 0x0005, 0x0000, 0x0006, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		}, };
	/* next address 000951e0 */

	static const char data_951e0[8][16] = {
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
		{ 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6, 0x0, 0x2, 0x4, 0x6,  },
	};
	/* next address 00095260 */
	static const u16 data_95260[8][4][16] = {
		{		// RYU
			{ 0x0002, 0x0003, 0x0001, 0x0004, 0x0006, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0006, 0x0004, 0x0001, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0007, 0x0003, 0x0006, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0006, 0x0003, 0x0007, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// HONDA
			{ 0x0002, 0x0003, 0x0000, 0x0004, 0x0006, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0006, 0x0004, 0x0000, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0000, 0x0007, 0x0003, 0x0006, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0006, 0x0003, 0x0007, 0x0000, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// BLANKA
			{ 0x0000, 0x0003, 0x0001, 0x0004, 0x0006, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0006, 0x0004, 0x0001, 0x0003, 0x0000, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0007, 0x0003, 0x0006, 0x0000, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0000, 0x0006, 0x0003, 0x0007, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// GUILE
			{ 0x0002, 0x0000, 0x0001, 0x0004, 0x0006, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0006, 0x0004, 0x0001, 0x0000, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0007, 0x0000, 0x0006, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0006, 0x0000, 0x0007, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// KEN
			{ 0x0002, 0x0003, 0x0001, 0x0000, 0x0006, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0006, 0x0000, 0x0001, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0001, 0x0007, 0x0003, 0x0006, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0006, 0x0003, 0x0007, 0x0001, 0x0000, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// CHUNLI
			{ 0x0002, 0x0003, 0x0001, 0x0004, 0x0006, 0x0000, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0000, 0x0006, 0x0004, 0x0001, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0007, 0x0003, 0x0006, 0x0002, 0x0000, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0002, 0x0006, 0x0003, 0x0007, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// ZANGEIF
			{ 0x0002, 0x0003, 0x0001, 0x0004, 0x0000, 0x0005, 0x0007, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0007, 0x0005, 0x0000, 0x0004, 0x0001, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0007, 0x0003, 0x0000, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0000, 0x0003, 0x0007, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		},{		// DHALSIM
			{ 0x0002, 0x0003, 0x0001, 0x0004, 0x0006, 0x0005, 0x0000, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0000, 0x0005, 0x0006, 0x0004, 0x0001, 0x0003, 0x0002, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0004, 0x0001, 0x0000, 0x0003, 0x0006, 0x0002, 0x0005, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
			{ 0x0005, 0x0002, 0x0006, 0x0003, 0x0000, 0x0001, 0x0004, 0x000a, 0x000b, 0x0009, 0x0008, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010,  },
		}, };
	/* next address 00095660 */
	
	
	if (g.NotUsed) {
		d0 = data_94d60[d0][RAND16];
		data = data_94de0[g.PlayersSelectedDash][d0];
	} else {
		d0 = data_951e0[d0][RAND16];
		data = data_95260[g.PlayersSelectedDash][d0/2];
	}

	for (i=0; i<16; i++) {
		g.LevelScript[i] = data[i];
	}
	if (g.Debug && (g.JPDifficulty & JP_JAPANJUMP)) {
		/* 2f34 todo one day */
	}
}

int ply_opp_has_struggled_free(Player *ply) {			// 3fd8
	ply->Opponent->Damage1 -= sub_4004(ply->Opponent);
	if (ply->Opponent->Damage1 > 0) {
		return FALSE;
	}
	return TRUE;
}
	

short sub_3466(Player *ply, short d2,short subsel_d3, short xoff_d4, short yoff_d5, short sound_d6) {			// 3466 player %a6
	/* returns true if victim knocked out. */
	Object *obj;
	short d4;
	
	// todo: d2 is always zero when called, remove from args
	ply->Timer2 = 12;
	if (obj = AllocActor()) {
		INITOBJC(obj, SF2ACT_HITSTUN, subsel_d3, PLAYERX, PLAYERY);
		obj->XPI += xoff_d4;
		obj->YPI += yoff_d5;
		obj->Owner = ply;
		obj->Flip = ply->Opponent->Flip;
	}
	hitsound(sound_d6);
	if (ply->x0150 >= 0) {		// damage set by random_damage_adjust_1
		d2 = ply->x0150;
		ply->x0150 = -1;
	}
	LBGetDamage(ply, ply->Opponent, d2);
	d4 = _EnergyDamageAdjust(ply, dr.damage);		// XXX never read
	QueueEffect(dr.d5, ply->Side);
	if (g.FastEndingFight == 0) {
		ply->Energy     -= dr.damage;
		ply->EnergyDash -= dr.damage;
	}
	if (ply->Energy < 0) {
		_KnockPlayerOut(ply);
		return TRUE;
	} else {
		return FALSE;
	}
}


static int sub_4014(Player *ply) {		//4014 ply %a4
	short d1 = 0;
	short d3 = 0;
	if (ply->JoyDecodeDash.full & 0xf == 0) {
		d1 = 1;
	}
	if (d1 && ((~ply->JoyDecodeDash.full) & ply->JoyDecode.full & 0xf)) {
		d3 = 3;
	}
	if (((~ply->JoyDecodeDash.full) & ply->JoyDecode.full & BUTTON_MASK)) {
		d3 += 1;
	}
	return d3;
}

static int sub_4004(Player *ply) {		// 4004 ply %a4
	static u16 data_98e42[32]={
		0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0800, 
		0x0200, 0x0000, 0x0020, 0x0020, 0x0800, 0x2000, 0x0020, 0x0020, 
		0x1000, 0x8004, 0x0040, 0x0801, 0x8004, 0x0010, 0x0800, 0x9002, 
		0x1100, 0x2040, 0x0208, 0x0804, 0x2101, 0x0201, 0x8102, 0x0201, 
	};
	
	if (ply->Human) {
		return sub_4014(ply);
	} else {
		if (data_98e42[ply->Difficulty] & (1 << RAND32)) {
			return (char []){4,4,2,4,4,2,7,3,8,4,3,2}[ply->FighterID];
		}
		return 0;
	}
}

static int sub_400e(Player *ply, Player *opp) {
	static u16 data_98ec2[32]={
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x0010, 0x0000, 
		0x0000, 0x0200, 0x2000, 0x0040, 0x0002, 0x0800, 0x8000, 0x0001, 
		0x0003, 0x8000, 0x1004, 0x0100, 0x0080, 0x4010, 0x0820, 0x0408, 
		0x2100, 0x8100, 0x0204, 0x0402, 0x8080, 0x8202, 0x0811, 0x1020, 
	};
	
	if (ply->Human) {
		return sub_4014(opp);
	} else {
		if (data_98ec2[ply->Difficulty] & (1 << RAND32)) {
			return (char []){4,6,8,4,4,2,6,10,8,4,3,2}[ply->FighterID];
		}
		return 0;
	}
}


int sub_3fee(Player *ply) {
	sub_400e(ply, ply);
	ply->Damage1 -= 3;
	if (ply->Damage1 >= 0) {
		return 0;
	} else {
		ply->Damage1 = ply->Damage2;
		return 1;
	}
}

void set_defeated_true(Player *ply) {		// 2eb6
	g.Defeated[ply->FighterID] = TRUE;
}

void set_defeated_false(Player *ply) {		//2eba
	g.Defeated[ply->FighterID] = FALSE;
}



void proc_round_result(void) {		/* 8c80 */
    if(g.OnBonusStage) {
        g.mode2    +=2;
        g.BonusDone++;
    } else {
        if (g.RoundResult < 0) {
            if (g.RoundCnt == 10) {
				/* 8ccc */
				g.x0a50 = TRUE;
				if (g.Player1.Human | g.Player1.x02ae) {
					g.PlyLostToComp = 0;
					g.BattleLoser = g.Player1.FighterID;
				} else {
					g.BattleLoser = g.Player2.FighterID;
					g.PlyLostToComp = 1;
				}
				kill_ply1();
				kill_ply2();
				/* redid 8d6a */
				g.BattleWinner = g.WinningFighter;
				g.BattleLoser = g.LosingFighter;
				g.x09f5 = g.HumanWinner;
				g.x09f6 = g.HumanLoser;
				g.BattleWinSide = g.RoundWinnerSide;
				g.PlyLostToPly = g.RoundLoserSide;
				g.mode2 += 4;
			}
			else if (g.RoundCnt != 9 ) {
				g.Player1.RoundsWon = 1;
				g.Player2.RoundsWon = 1;
			}
			g.mode2 += 2;
        } else {
            if(g.Player1.RoundsWon == 2) { victory_p1(); }
            else if(g.Player2.RoundsWon == 2) { victory_p2(); }
            else { g.mode2 += 2; }
        }
    }
}
int check_special_ability(Player *ply) {       /* 0x32e4 */
    if (    ply->Human 
        && !ply->Airborne 
        && !g.PreRoundAnim 
        && !g.RoundResult 
        && !g.PlayersThrowing 
        &&  ply->mode1 != PLSTAT_IN_POWERMOVE
        &&  ply->mode1 != PLSTAT_REEL
        &&  ply->mode1 != PLSTAT_TUMBLE
        &&  ply->Energy == ply->EnergyDash ) {
        return 0;
    } else {
        return 1;
    }
}
int _check_throw(int airthrow, Player *ply) {		/* 0x3338 */
    int temp4, temp5,temp6 ;
 	
    Player *opp = ply->Opponent;
    
    if (ply->ThrowDisable)									{ return 0; }
    if (ply->Human == FALSE && g.DebugNoCollide != FALSE)	{ return 0; }
    if (g.CurrentStage == STAGE_BONUS_DRUMS ||
        ply->BlockStun						||
        ply->Energy < 0						||
        ply->EnergyDash != ply->Energy		||
        opp->BlockStun						||
        opp->Energy < 0						||
        opp->EnergyDash != opp->Energy		||
        opp->exists == FALSE				||
        opp->mode1 == PLSTAT_TUMBLE ) 
	{ return 0; }
    
    if (opp->DizzyStun == 0 && 
        opp->mode1 == PLSTAT_REEL) { return 0; }
    
    
    if (!airthrow && opp->Airborne)   { return 0; } 
    
    if (opp->NoThrow_t)						{ return 0; }
    if (opp->ActionScript->HB_Head == 0 &&
		opp->ActionScript->HB_Body == 0 &&
		opp->ActionScript->HB_Foot == 0 &&
		opp->ActionScript->HB_Weak == 0)        { return 0; }
    if (opp->Invincible)						{ return 0; }
    if (opp->TCollDis)							{ return 0; }
    
    temp5 = ply->Throw[0];
    if (ply->Flip) { temp5 = -temp5; }
    temp5 = temp5 + ply->XPI - opp->XPI + ply->Throw[2] + opp->Throw[4];
    temp4 = 2 * (ply->Throw[2] + opp->Throw[4]);
    
    
    
    if (temp5 > temp4 || temp5 < 0) { return 0; }
    
	temp6 = ply->YPI + ply->Throw[1] - (opp->YPI + opp->Throw[5]) + ply->Throw[3];
    if (temp6 > (2 * ply->Throw[3]) || temp6 < 0 )   { return 0; }
    
    opp->DSOffsetX = 0;
    ply->ThrowStat = 1;
    opp->ThrowStat = -1;
    ply->Attacking = 0;
    opp->Attacking = 0;
    ply->x01b0++;
    opp->ThrownFromDizzy = opp->DizzyStun;
    g.PlayersThrowing |= 1 << ply->Side;
    
    bumpdifficulty_10(); /* difficulty */
    
    return TRUE;
}
int airthrowvalid(Player *ply) {
    return _check_throw(TRUE, ply);
}
int throwvalid(Player *ply) {
    return _check_throw(FALSE, ply);
}

void set_initial_positions(void) {          /* 0x37da */
    g.Player1.XPI = get_scr2x();
    g.Player1.YPI = get_scr2y();
    g.Player2.XPI = get_scr2x();
    g.Player2.YPI = get_scr2y();
    g.Player1.XPI += 104;		/* 88(d) pixels either side of centre, 104 and 280 */
    g.Player1.YPI +=  40;
    g.Player2.XPI += 280;
    g.Player2.YPI +=  40;
    g.Player1.Direction			 = FACING_RIGHT;
    g.Player1.EnemyDirection     = FACING_RIGHT;
    g.Player2.Direction			 = FACING_LEFT;
    g.Player2.EnemyDirection     = FACING_LEFT;
    
    g.Player1.OldX.part.integer = g.Player1.XPI;
    g.Player1.OldY.part.integer = g.Player1.YPI;
	g.Player1.OldX.part.integer = g.Player2.XPI;
	g.Player1.OldY.part.integer = g.Player2.YPI;
    /* player2 copy never gets made in original, strange, not fixed here yet */

    if(g.CurrentStage == STAGE_BONUS_CAR || g.CurrentStage == STAGE_BONUS_DRUMS) {
        g.Player1.Size = PLYWIDTHS_SMALLER[g.Player1.FighterID];
        g.Player2.Size = PLYWIDTHS_SMALLER[g.Player2.FighterID];
    } else {
        g.Player1.Size = PLYWIDTHS[g.Player1.FighterID];
        g.Player2.Size = PLYWIDTHS[g.Player2.FighterID];
    }
}
   


void give_100_points(short side) {		//53d6, wrong, actually 1
	Player *ply = side ? PLAYER2 : PLAYER1;
	if (g.PlayersOnline & (1 << ply->Side)) {
		add_bcd_32(0x1, &ply->Score);
		if (ply->Score > 0x9999999) {
			ply->Score = 0x9999999;
		}
	}
}
        
/*********************      Difficulty stuff ****************/

static void sub_2be6(short stage) {						// 2be6
	g.OnBonusStage = TRUE;
	g.CurrentStage = stage;
	sub_2c1a();
}

void sub_2b7c(void) {
	static const short SF2_DEMO_STAGES[4] = {			// 2b6e
		STAGE_JAPAN_RYU, 
		STAGE_USA_GUILE,
		STAGE_INDIA_DHALSIM, 
		STAGE_JAPAN_EHONDA
	};
	short d0,d1;
	
	if(g.InDemo) {
		g.CurrentStage = SF2_DEMO_STAGES[g.DemoStageIndex];       /* 2b60 */
		return;
	} else if (g.x0a0f == 0) {
		if(g.OnBonusStage == FALSE) {
			g.LastFightStage = g.CurrentStage;	/* u16 */
		} 
		g.OnBonusStage = 0;
		if(g.BonusDone == 0) {	/*2ba4 */
			d0 = g.x0a10;	/* u16 not found set*/
			d0 = 0xc;
			d1 = 3;
			if(g.NotUsed) { d1 = 2; }
			if(g.x09f9 == d1) {
				sub_2be6(d0);
				return;
			}
		}
		/* 2bb8 */
		if (g.BonusDone == 1) {
			d0 = 0xd;	/* barrels */
			d1 = g.NotUsed ? 4 : 6;
			if(g.x09f9 == d1) {
				sub_2be6(d0);
				return;
			}
		}
		if (g.BonusDone == 2) {
			d0 = 0xe;		/* drums */
			if (g.NoLoser) {
				sub_2be6(d0);
				return;
			}
		}
		_bumplevel();
	} else {
		d0 = g.x0a0c;
		sub_2be6(d0);		
	}
}

void sub_4720(void) {
	u16 data_4754[32]={
		0x000a, 0x0020, 0x0002, 0x0000, 0x000a, 0x0008, 0x0010, 0x0008, 
		0x0014, 0x0008, 0x0010, 0x000a, 0x0010, 0x000a, 0x0014, 0x0010,
		0x0002, 0x0010, 0x000a, 0x0008, 0x000a, 0x0020, 0x000a, 0x0002, 
		0x0000, 0x000a, 0x0008, 0x0014, 0x0008, 0x000a, 0x0010, 0x000a,  
	};

	short d0;
	if(g.ActiveHumans == BOTH_HUMAN || g.OnBonusStage) { return; }
	d0 = data_4754[(RAND32 & 0x3e) >> 1];
	g.Diff_0a04 -= d0;
	g.Diff_0a04 &= 0xff;
	g.x8a40 = -d0;
	bumpdifficulty();
}

void sub_4794(void) {			// 4794
	if (g.ActiveHumans != BOTH_HUMAN) {
		g.Diff_0a04 += 8;
		g.Diff_0a04 &= 0xff;
	}
}

void bumpdifficulty(void) {				// 4414
    if(g.InDemo) { return; };
	if(g.x0a18) {		// not found set
		/* 43d6 */
		g.Diff_0a06 = 0x69;
		g.Diff_0a08 = 0xff;
		g.CurrentDifficulty = 0x1f;
	} else {
		g.Diff_0a06 = data_98f42[g.Difficulty][g.x0a16][0];
		g.Diff_0a08 = data_98f42[g.Difficulty][g.x0a16][1];
		
		if (g.Diff_0a06 > g.Diff_0a04) {g.Diff_0a04 = g.Diff_0a06;}
		if (g.Diff_0a08 > g.Diff_0a04) {g.Diff_0a04 = g.Diff_0a08;}
		g.CurrentDifficulty = data_4976[g.Diff_0a04];		/* u8 array */
	}
}

void bumpdifficulty_4576(void) {
	g.x0a0e++;
	if (g.x0a0e & 1 == 0) {
		bumpdifficulty_01();
	}
	
}

void bumpdifficulty_01(void) {// 453c
	static char data_4566[] = {
		24, 32, 40, 48, 56, 60, 64, 68, 
		72, 76, 80, 84, 88, 92, 96, 99
	};
	if (g.x0a0c < 16) {
		g.Diff_0a04 -= data_4566[g.x0a0c];
	} else {
		g.Diff_0a04 -= 84;
	}

	if (g.Diff_0a04 < 0) {
		g.Diff_0a04 = 0;
	}
	g.Diff_0a04 &= 0xff;
	bumpdifficulty();
	++g.x0a0c;
}

void BumpDiff_NewGame(void) {
    if(g.InDemo) {
		/* 43d6 inlined */
		g.Diff_0a06 = 0x69;
		g.Diff_0a08 = 0x00ff;
		g.CurrentDifficulty = 0x1f;
    } else {
        g.Diff_GameCnt++;
        if(g.Diff_GameCnt &= 0xf) { /* deliberate */
            bumpdifficulty();
            return;
        }
        if( 0x00802000 & (1 << RAND32) ) {
            bumpdifficulty();
            return;
        }
        g.Diff_0a06 = g.Diff_0a04 = 0;
        g.CurrentDifficulty = 0;
        bumpdifficulty();
    }
}
void bumpdifficulty_08(void) {
	short d0;
	if(g.ActiveHumans == 3) { return; }
	if(g.OnBonusStage)      { return; }
	g.x0a0a++;
	if(g.x0a0a < 0xf0) {
		g.x0a0a = 0;
		g.Diff_0a04 += 3;
		g.Diff_0a04 &= 0xff;
		bumpdifficulty();
	}
	d0 = (!g.ContrP1DB.full) & g.ContrP1.full;
	if(g.Player1.Human==0) {
		d0 = (!g.ContrP2DB.full) & g.ContrP2.full;
	}
	d0 &= BUTTON_MASK;
	if(d0 == 0) {return;}
	if(g.Diff_0ad6 < 0xffff) {
		g.DisableTimer++;
	} else {
		g.Diff_0ad6 = 0xffff;
	}
}
void bumpdifficulty_02(void) {
	if(g.ActiveHumans == 3 || g.OnBonusStage) { return; }
	if(g.Diff_0ad6 < 0x3d) {
		g.x8a36     += data_44f6[g.Diff_0ad6];
		g.Diff_0a04 += data_44f6[g.Diff_0ad6];		/* u16 */
	} else {
		g.x8a36     += 4;
		g.Diff_0a04 += 4;
	}
	g.Diff_0a04 &= 0xff;
	bumpdifficulty();
}
void bumpdifficulty_03(void) {	// 46e2
	static char data_4716[] = {0,2,4,8,12,16,20,24,28,32};
	
	if (g.ActiveHumans == 3 || g.OnBonusStage) { return; }
	if (g.Diff_WeakBoxCnt > 8) {
		g.Diff_0a04 += 32;
		g.x8a38     += 32;
	} else {
		g.Diff_0a04 += data_4716[g.Diff_WeakBoxCnt];
		g.x8a38     += data_4716[g.Diff_WeakBoxCnt];
	}

	g.Diff_0a04 &= 0xff;
	bumpdifficulty();	
}
void bumpdifficulty_04(void) { /* 47aa */
	short d1 = 0;
	short d0;
	
	if (g.ActiveHumans != 3 && g.OnBonusStage == FALSE) {
		d0 = g.x0ae4 * 100;
		if (d0 > 0 && g.HumanMoveCnt > 0) {
			d1 = d0 / g.HumanMoveCnt;
		}
		if (d1 <= 28) {
			d0 = 0;
		} else if (d1 <= 60) {
			d0 = 0;
		} else if (d1 <= 0x50) {
			d0 = 1;
		} else if (d1 <= 0x5a ) {
			d0 = 2;
		} else {
			d0 = 3;
		}
		g.x8a3a = d0;
		g.Diff_0a04 += d0;
		g.Diff_0a04 &= 0xff;
		bumpdifficulty();
	}
}
void bumpdifficulty_05(void) { /* 4584 */ 
	const char *data;
	u8	d6;
	
	static const char data_4836[] = {
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1, -1, -1, -1, -1, -1,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1, -1, -1, -1, -1, -1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1, -1, -1, -1, -1, -1,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -1, -1, -1, -1, -1, -1,
	};
	
	static const char data_48d6[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, -1, -1, -1, -1, -1, -1,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, -1, -1, -1, -1, -1, -1,
		9, 9, 9, 9, 9, 9, 9, 9, 9, 9, -1, -1, -1, -1, -1, -1,
		9, 9, 9, 9, 9, 9, 9, 9, 9, 9, -1, -1, -1, -1, -1, -1,
	   15,15,15,15,15,15,15,15,15,15, -1, -1, -1, -1, -1, -1,
	   15,15,15,15,15,15,15,15,15,15, -1, -1, -1, -1, -1, -1,
	};
		
	if (g.ActiveHumans != 3 && g.OnBonusStage == 0) {
		if (g.HumanLoser) {
			d6 = 0;
			data = data_48d6;
		} else {
			d6 = 1;
			data = data_4836;
		}
		/* machine divides by zero if lookup below is negative */
		if (d6) {
			g.Diff_0a04 += data[g.TimeRemainBCD];
			g.Diff_0a04 &= 0xff;
			g.x8a3c = data[g.TimeRemainBCD];
		} else {
			g.Diff_0a04 -= data[g.TimeRemainBCD];
			g.Diff_0a04 &= 0xff;
			g.x8a3c = -data[g.TimeRemainBCD];
		}
		bumpdifficulty();
	}
}
void bumpdifficulty_06(void) { /* 45ea */ 
	static const char data_46aa[] = {0, 2, 8, 16, 20, 24, 32, 40, 48, -1};
	short d1, d2, d3;
	short d6;
	
	
	if (g.ActiveHumans != 3 && g.OnBonusStage == 0) {
		if (g.RoundResult < 0) {
			// 4684
			if(g.Diff06Cnt >= 9) {
				d1 = 0x30;
			} else {
				d1 = data_46aa[g.Diff06Cnt];
			}
			g.Diff_0a04 += d1;
			g.Diff_0a04 &= 0xff;
		} else {
			if (g.RoundResult & 1) {
				d1 = g.Player1.Energy;
				d6 = g.Player1.Side;
			} else {
				d1 = g.Player2.Energy;
				d6 = g.Player2.Side;
			}
			if (d1 >= 0x71) {
				d2 = 4;
				d3 = 12;
			} else if (d1 >= 0x51) {
				d2 = 3;
				d3 = 9;
			} else if (d1 >= 0x31) {
				d2 = 1;
				d3 = 3;
			} else if (d1 >= 0x11) {
				d2 = 1;
				d3 = 3;
			} else {
				d2 = 3;
				d3 = 6;
			}
			if (g.BattleWinSide == d6) {
				g.x8a3e = d2;
				g.Diff_0a04 += d2;
				g.Diff_0a04 &= 0xff;
			} else {
				g.Diff_0a04 -= d3;
				g.Diff_0a04 &= 0xff;
				g.x8a3e = -d3;
			}
		}
		bumpdifficulty();
	}
}

void bumpdifficulty_10(void) {		/* 0x46b4 */
	g.Diff_0a04 = (g.Diff_0a04 + 2) & 0xff;
	bumpdifficulty();
}

void bump_difficulty_4816(void) {  /* 0x4816 */
	if(g.ActiveHumans != BOTH_HUMAN && g.OnBonusStage == 0) { 
		g.Diff_0a04++;
		g.Diff_0a04 &= 0xff;
		bumpdifficulty();
	}
}

void BumpDiff_PowerMove(void) {	// 46c2 same as 4816?
	if (g.ActiveHumans != BOTH_HUMAN && g.OnBonusStage == 0) {
		++g.Diff_0a04;
		g.Diff_0a04 &= 0xff;
		bumpdifficulty();
	}
}
            
static void victory(void) {
	g.BattleWinner = g.WinningFighter;
	g.BattleLoser  = g.LosingFighter;
	g.x09f5 = g.HumanWinner;
	g.x09f6 = g.HumanLoser;
	g.BattleWinSide = g.RoundWinnerSide;
	g.PlyLostToPly = g.RoundLoserSide;
	g.mode2 += 4;
}

static void sub_86d4(void) {
	g.BattleLoser = g.LosingFighter;
	g.BattleWinner = g.WinningFighter;
	g.x09f5 = g.HumanWinner;
	g.x09f6 = g.HumanLoser;
	g.BattleWinSide = g.RoundWinnerSide;
	g.PlyLostToPly  = g.RoundLoserSide;
	g.mode1 = 8;
	g.mode2 = 0;	/* Game Over */
}
static void sub_8d94(short side) {
	int cursor;
	
	Player *pla, *plb;
	if (side) {
		pla = PLAYER2;
		plb = PLAYER1;
	} else {
		pla = PLAYER1;
		plb = PLAYER2;
	}
	if (g.ActiveHumans == BOTH_HUMAN) {
		//8e0e
		check_level_sequence(plb);
		set_defeated_false(plb);
		if (pla->FighterID != g.PlayersSelectedDash) {
			if (g.Defeated[pla->FighterID]) {
				++g.x0a16;
				g.x0a16 &= 0xf;
				++g.x09f9;
			}
		}
		check_level_sequence(pla);
		set_defeated_false(pla);
	} else {
		if (plb->x02ae || plb->Human) {
			++g.x09f9;
			++g.x0a16;
			g.x0a16 &= 0xf;
			check_level_sequence(plb);
			set_defeated_false(plb);
			check_level_sequence(pla);
			set_defeated_false(pla);
		} else if (pla->FighterID == g.PlayersSelectedDash) {
			check_level_sequence(pla);
			set_defeated_false(pla);
		}
		for (cursor = g.LevelCursor * 2; g.LevelScript[cursor+1] != 16 ; cursor += 2) {
			if(g.LevelScript[g.LevelCursor * 2] == pla->FighterID) {
				return;
			}
		}
		check_level_sequence(pla);
		set_defeated_false(pla);
	}
}

static void victory_p1(void) {
	g.VictoryCnt++;
	sub_8d94(1);
	kill_ply2();
	if(g.ActiveHumans == ONLY_P2) {
		sub_86d4();
	} else {
		g.Player2.Alive = FALSE;
		victory();
	}
}
static void victory_p2(void) {
	g.VictoryCnt++;
	sub_8d94(0);
	kill_ply1();
	if(g.ActiveHumans == ONLY_P1) {
		sub_86d4();
	} else {
		g.Player1.Alive = FALSE;
		victory();
	}
}

static void kill_ply1(void) {
	if(g.Player1.Human | g.Player1.x02ae) {
		g.Player1.FighterSelect = g.Player1.FighterID;
	}
	g.Player1.Human = FALSE;
	g.Player1.x02ae = FALSE;
	g.Player1.SelectComplete = FALSE;
	g.Player1.FighterID = 0;
}
static void kill_ply2(void) {
	if(g.Player2.Human | g.Player2.x02ae) {
		g.Player2.FighterSelect = g.Player2.FighterID;
	}
	g.Player2.Human = FALSE;
	g.Player2.x02ae = FALSE;
	g.Player2.SelectComplete = FALSE;
	g.Player2.FighterID = 0;
}

        