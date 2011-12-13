/*
 *  projdata.h
 *  GLUTBasics
 *
 *  Created by Ben on 9/11/10.
 *  Copyright 2010 Ben Torkington. All rights reserved.
 *
 */


short data_22bf6[5] = { 0x50, 0x58, 0x00, 0x40, 0x68 };
short data_22c00[5] = { 0x38, 0x22, 0x00, 0x32, 0x4e };



HitBox hitb_2329c[] = {{0,0,0,0}, {0,0,0x1c,0x13},{0,0,0x29,0x11}};
HitBoxAct hitb_232a8[] = {{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,15,12,11,1,0x2a,3,2,2,3,0x14}};

HitBox hitb_23334[] = {{0,0,0,0}, {0,0,0x29, 0x11}};
HitBoxAct hitb_2334c = {0,0,0,0, 0,0,0,0};

HitBox hitb_233bc[] = {{ 0,0,0,0}, {0,0, 0x1c, 0x13},{ 0, 0, 0, 0}};
HitBoxAct hitb_233c4 = { 0,0,0,0, 0,0, 0,    0,    0, 0, 0, 0};

HitBox hitb_2493e[] = {{0,0,0,0}, {0x2, 0x11, 0x18, 0x10}};
HitBoxAct hitb_24946 = { 0,0,0,0,0,0,0,0,0,0,0,0};

HitBox hitb_249a2[] = {{ 0,0,0,0}, {0xde, 0x20, 0x28, 0x18},{ 0,0,0,0}};
HitBoxAct hitb_249aa = { 0,0,0,0, 0,    0,    0,    0,    0,0,0,0};

struct hitboxes data_23290 = {		/* Hadouken Hitboxes */
	hitb_2329c,
	hitb_2329c,
	hitb_2329c,
	hitb_2329c,
	hitb_232a8,
	hitb_2329c,
};
struct hitboxes data_23328 = {
	hitb_23334,
	hitb_23334,
	hitb_23334,
	hitb_23334,
	&hitb_2334c,
	hitb_23334,
};
struct hitboxes data_233b0 = {
	hitb_233bc,
	hitb_233bc,
	hitb_233bc,
	hitb_233bc,
	&hitb_233c4,
	hitb_233bc,
};
struct hitboxes data_24932 = {
	hitb_2493e,
	hitb_2493e,
	hitb_2493e,
	hitb_2493e,
	&hitb_24946,
	hitb_2493e,
};
signed char data_24976[32]={
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
};
/* next address 00024996 */

struct hitboxes data_24996= {
	hitb_249a2,
	hitb_249a2,
	hitb_249a2,
	hitb_249a2,
	&hitb_249aa,
	hitb_249a2,
};
signed char data_249da[32]={
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
};
/* next address 000249fa */

short data_23572[][2]={
	{0,0}, { -0x26, 0x3b }, {-0x3c, 0x2a}, {-0x49, 0x17}
};
	

	
/* What is this waste of time for? */
signed char data_23308[] = {0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
};
signed char data_23390[] = {0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
};
signed char data_233f4[] = {0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,
};

struct {
	struct hitboxes *hb;
	signed char *mb;
} data_22c0a[5] = {
	{&data_23290, data_23308,},
	{NULL, NULL},	// Can't happen
	{NULL, NULL},	// Can't happen
	{&data_23328, data_23390},
	{&data_233b0, data_233f4},
};


//velocities, XXX not all done
VECT16 data_cf038[] = {{0x300, 0}, {-0x300, 0}, {0x380, 0}, {-0x380, 0}};
VECT16 data_cf048[] = {{0x400, 0}, {-0x400, 0}, {    0, 0}, { 0x480, 0}, {-0x480, 0}};		// very strange
VECT16 data_cf05c[] = {{0x500, 0}, {-0x500, 0}, {0x580, 0}, {-0x580, 0}};
VECT16 data_cf07c[] = {{0x700, 0}, {-0x700, 0}, {0x780, 0}, {-0x780, 0}};


#pragma mark ---- Hadouken Data ----

VECT16 *data_22c32[]={data_cf038, data_cf048 , data_cf05c};


Image image_22e66 = {
    6, 0x000e, 0x34, 0, 16,
    { 0x0940, 0x09f3, 0x0941, 0x09f4, 0x0942, 0x092a,  }
};
Image image_22e7c = {
    0, 0x000e, 0x34, 0, 0,
    {  }
};
Image image_22e4e = {
    7, 0x000e, 0x68, -8, 16,
    { 0x0e5b, 0x0e67, 0x0e5c, 0x0e68, 0x0e5d, 0x0e69, 0x0e4f,  }
};
const Action actlist_22cda[] = {
	{ 2, 0x00, 0x0, &image_22e66, 0, 0, 0, 0, 5, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 2, 0x00, 0x0, &image_22e4e, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x81, 0x1, &image_22e66, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_22cda[1], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_22d56[] = {
	{ 2, 0x00, 0x0, &image_22e66, 0, 0, 0, 0, 6, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1}, /* LOOP BEGIN */ 
	{ 2, 0x00, 0x0, &image_22e4e, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 2, 0x81, 0x1, &image_22e66, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{0,0,0,(struct image *)&actlist_22d56[1], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_22dd2[] = {
	{ 2, 0x00, 0x0, &image_22e66, 0, 0, 0, 0, 7, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2}, /* LOOP BEGIN */ 
	{ 2, 0x00, 0x0, &image_22e4e, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0x81, 0x1, &image_22e66, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{0,0,0,(struct image *)&actlist_22dd2[1], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action *action_22cd2[]={actlist_22cda, actlist_22d56, actlist_22dd2};


#pragma mark ---- anotherprojectile ----

Image image_230dc = {
    6, 0x0004, 0x4a, -7, 16,
    { 0x0000, 0x2ff0, 0x0000, 0x2ff2, 0x2fd0, 0x2ff3,  }
};
Image image_230f6 = {
    4, 0x0004, 0x2c, -6, 1,
    { 0x3163, 0x31a1, 0x31b6, 0x31c7,  }
};
Image image_23108 = {
    6, 0x0064, 0x4a, -7, 16,
    { 0x0000, 0x2ff0, 0x0000, 0x2ff2, 0x2fd0, 0x2ff3,  }
};
Image image_23122 = {
    4, 0x0064, 0x2c, -6, 1,
    { 0x3163, 0x31a1, 0x31b6, 0x31c7,  }
};
const Action actlist_22e90[] = {
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23122, 0, 0, 0, 0, 4, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x84, 0x1, &image_23122, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_22e90[4], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_22f54[] = {
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 5, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 5, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 5, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23122, 0, 0, 0, 0, 5, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x84, 0x1, &image_23122, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{0,0,0,(struct image *)&actlist_22f54[4], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_23018[] = {
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 6, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 6, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 6, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23122, 0, 0, 0, 0, 6, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_230dc, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_230f6, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23108, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x84, 0x1, &image_23122, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{0,0,0,(struct image *)&actlist_23018[4], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action *action_22e88[]={actlist_22e90, actlist_22f54, actlist_23018};


#pragma mark ---- TIGER ----

VECT16 *data_22c3e[]={data_cf038, data_cf05c, data_cf07c};

Image image_23268 = {
    6, 0x0011, 0x34, 0, 16,
    { 0x045b, 0x04d3, 0x045c, 0x04d4, 0x0407, 0x0457,  }
};
Image image_2327e = {
    4, 0x0011, 0x31, 0, 16,
    { 0x03af, 0x03bf, 0x03cf, 0x03df,  }
};
const Action actlist_2313c[] = {
	{ 2, 0x00, 0x0, &image_23268, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x00, 0x0, &image_2327e, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x80, 0x1, &image_22e7c, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_2313c[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_231a0[] = {
	{ 2, 0x00, 0x0, &image_23268, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x00, 0x0, &image_2327e, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x80, 0x1, &image_22e7c, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_231a0[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_23204[] = {
	{ 2, 0x00, 0x0, &image_23268, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 1, 0x00, 0x0, &image_22e7c, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 0x00, 0x0, &image_2327e, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x80, 0x1, &image_22e7c, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_23204[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action *action_23134[]={actlist_2313c, actlist_231a0, actlist_23204};


#pragma mark ---- Yoga Fire Data ----
/*
 * YOGA FIRE 
 */

short *data_2349a[] = 	// velocity paths
	{data_cf038, data_cf05c, data_cf07c };


#define IMAGE_BLOCK	0x8000		// actually image_with_attrs

 Image image_23b62 = {
    0, 0x000e, 0x34, 0, 0,
    {  }
};
 Image image_23aa6 = {
    6, 0x000f, 0x34, 0, 0,
    { 0x0afb, 0x0a90, 0x0afc, 0x0a86, 0x0afd, 0x0ad5,  }
};
 Image image_23abc = {
    6, 0x000f, 0x34, 0, 0,
    { 0x0df8, 0x0d0f, 0x0df9, 0x0d1f, 0x0dfa, 0x0d2f,  }
};
 Image image_23ad2 = {
    6, 0x000f, 0x34, 0, 0,
    { 0x0707, 0x0771, 0x0708, 0x0772, 0x0709, 0x0773,  }
};
 Image image_23ae8 = {
    6, 0x000f, 0x34, 0, 0,
    { 0x0755, 0x0727, 0x0756, 0x0747, 0x0757, 0x0767,  }
};
 Image image_23afe = {
    6, 0x000f, 0x34, 0, 0,
    { 0x07b9, 0x07c9, 0x07ba, 0x07b6, 0x07a7, 0x07b7,  }
};
 Image image_23b14 = {
    6+IMAGE_BLOCK, 0x000f, 0x34, 0, 0,
    { 0x07ab, 0x000f, 0x07fb, 0x000f, 0x07ac, 0x000f,  }
};
 Image image_23b36 = {
    6, 0x000f, 0x34, 0, 0,
    { 0x0790, 0x072e, 0x07c5, 0x0779, 0x07f7, 0x07d9,  }
};
 Image image_23b4c = {
    6, 0x000f, 0x34, 0, 0,
    { 0x05b0, 0x05c0, 0x0528, 0x0538, 0x05d0, 0x050a,  }
};
const Action actlist_2361a[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_23aa6, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23abc, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23ad2, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23ae8, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23afe, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23b14, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x00, 0x1, &image_23b36, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 3, 0x80, 0x1, &image_23b4c, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 0},
	{0,0,0,(struct image *)&actlist_2361a[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_2379e[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_23aa6, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23abc, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23ad2, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23ae8, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23afe, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23b14, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x00, 0x1, &image_23b36, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{ 3, 0x80, 0x1, &image_23b4c, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 1},
	{0,0,0,(struct image *)&actlist_2379e[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_23922[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_23aa6, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23abc, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23ad2, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23ae8, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23afe, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23b14, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x00, 0x1, &image_23b36, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 3, 0x80, 0x1, &image_23b4c, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 2},
	{0,0,0,(struct image *)&actlist_23922[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action *data_23612[]={actlist_2361a, actlist_2379e, actlist_23922};


#pragma mark ---- Yoga Flame ----


Image image_24728 = {
    4, 0x000f, 0x31, 16, 0,
    { 0x2070, 0x20fe, 0x2062, 0x20ff,  }
};
Image image_2473a = {
    6, 0x000f, 0x34, 24, 0,
    { 0x2104, 0x2114, 0x2160, 0x2170, 0x214a, 0x215a,  }
};
Image image_24750 = {
    10, 0x000f, 0x54, 32, 0,
    { 0x0000, 0x21e4, 0x21f4, 0x21d5, 0x21e5, 0x21f5, 0x21d6, 0x21e6, 0x21f6, 0x0000,  }
};
Image image_24772 = {
    10, 0x000f, 0x54, 32, 0,
    { 0x21d0, 0x21e0, 0x21f0, 0x21d1, 0x21e1, 0x21f1, 0x0000, 0x21e2, 0x21f2, 0x0000,  }
};
Image image_24794 = {
    12, 0x000f, 0x53, 40, 0,
    { 0x2073, 0x20f0, 0x0000, 0x2074, 0x20f1, 0x209c, 0x20b5, 0x200d, 0x209d, 0x20b6, 0x200e, 0x209e,  }
};
Image image_247bc = {
    15, 0x000f, 0x1e, 40, 0,
    { 0x0000, 0x21d8, 0x21e8, 0x21f8, 0x21c9, 0x21d9, 0x21e9, 0x21f9, 0x21ca, 0x21da, 0x21ea, 0x21fa, 0x0000, 0x21db, 0x21eb,  }
};
Image image_247ee = {
    17, 0x000f, 0x1e, 40, 0,
    { 0x218a, 0x219a, 0x21aa, 0x21ba, 0x218b, 0x219b, 0x21ab, 0x21bb, 0x218c, 0x219c, 0x21ac, 0x21bc, 0x0000, 0x219d, 0x21ad, 0x21bd, 0x0000,  }
};
Image image_24820 = {
    16, 0x000f, 0x1e, 40, 0,
    { 0x3e0e, 0x3e1e, 0x3e2e, 0x3e3e, 0x3e0f, 0x3e1f, 0x3e2f, 0x3e3f, 0x3ece, 0x3ede, 0x3eee, 0x3efe, 0x0000, 0x3edf, 0x3eef, 0x3eff,  }
};
Image image_24852 = {
    16, 0x000f, 0x1e, 40, 0,
    { 0x21cc, 0x21dc, 0x21ec, 0x21fc, 0x21cd, 0x21dd, 0x21ed, 0x21fd, 0x21ce, 0x21de, 0x21ee, 0x21fe, 0x0000, 0x21df, 0x21ef, 0x21ff,  }
};
Image image_24884 = {
    16, 0x000f, 0x1e, 40, 0,
    { 0x478d, 0x479d, 0x47ad, 0x47bd, 0x478e, 0x479e, 0x47ae, 0x47be, 0x478f, 0x479f, 0x47af, 0x47bf, 0x0000, 0x47cf, 0x47df, 0x47ef,  }
};
Image image_248b6 = {
    14, 0x000f, 0x1e, 40, 0,
    { 0x0000, 0x20e7, 0x20f7, 0x0000, 0x2001, 0x20d8, 0x20e8, 0x20f8, 0x20c9, 0x20d9, 0x20e9, 0x20f9, 0x0000, 0x2007,  }
};
Image image_248e8 = {
    9, 0x000f, 0x47, 40, 0,
    { 0x2135, 0x218d, 0x21af, 0x21bf, 0x0000, 0x218e, 0x219e, 0x21b6, 0x0000,  }
};
Image image_2490a = {
    5, 0x000f, 0x34, 40, -16,
    { 0x2109, 0x21d2, 0x210a, 0x21d3, 0x0000,  }
};
Image image_24920 = {
    3, 0x000f, 0x31, 48, -16,
    { 0x0000, 0x20b3, 0x2077,  }
};

const Action actlist_23b78[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_24728, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2473a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24750, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24772, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24794, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247bc, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 1, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24884, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248b6, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248e8, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2490a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x80, 0x0, &image_24920, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{0,0,0,(struct image *)&actlist_23b78[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_23e4c[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_24728, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2473a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24750, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24772, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24794, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247bc, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 2, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24884, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248b6, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248e8, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2490a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x80, 0x0, &image_24920, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{0,0,0,(struct image *)&actlist_23e4c[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
const Action actlist_241e0[] = {
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13}, /* LOOP BEGIN */ 
	{ 3, 0x00, 0x0, &image_24728, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2473a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24750, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24772, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24794, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247bc, 0, 0, 0, 0, 3, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_247ee, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24820, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24852, 0, 0, 0, 0, 3, 1, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_24884, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248b6, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_248e8, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x00, 0x0, &image_2490a, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 1, 0x00, 0x0, &image_23b62, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{ 3, 0x80, 0x0, &image_24920, 0, 0, 0, 0, 0, 0, 0, 0x00, 0, 0, 0, 0, 0, 0, 0, 13},
	{0,0,0,(struct image *)&actlist_241e0[0], 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};

const Action *data_23b6e[]={actlist_23b78, actlist_23e4c, actlist_241e0};
