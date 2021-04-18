#pragma once
#include <stdint.h>
#include <intrin.h>


#define ETC2_DMODE_OVERFLOW_VALUE 0xf800

enum ETC2Modes
{
	ETC2_MODE_INDIVIDUAL = 0,
	ETC2_MODE_T,
	ETC2_MODE_H,
	ETC2_MODE_PLANAR,
	ETC2_MODE_DIFFERENTIAL,
};

struct IModeData
{
	uint16_t Indices0;
	uint16_t Indices1;
	uint32_t FlipBit : 1;
	uint32_t DBit : 1;
	uint32_t Table2 : 3;
	uint32_t Table1 : 3;
	uint32_t B2 : 4;
	uint32_t B1 : 4;
	uint32_t G2 : 4;
	uint32_t G1 : 4;
	uint32_t R2 : 4;
	uint32_t R1 : 4;
};

struct DModeSelData
{
	uint32_t FlipBit : 1;
	uint32_t DBit : 1;
	uint32_t Table2 : 3;
	uint32_t Table1 : 3;
	uint32_t Bd : 3;
	uint32_t B : 5;
	uint32_t Gd : 3;
	uint32_t G : 5;
	uint32_t Rd : 3;
	uint32_t R : 5;
};

struct DModeData
{
	uint16_t Indices0;
	uint16_t Indices1;
	uint32_t FlipBit : 1;
	uint32_t DBit : 1;
	uint32_t Table2 : 3;
	uint32_t Table1 : 3;
	uint32_t Bd : 3;
	uint32_t B : 5;
	uint32_t Gd : 3;
	uint32_t G : 5;
	uint32_t Rd : 3;
	uint32_t R : 5;
};

struct TModeData
{
	uint16_t Indices0;
	uint16_t Indices1;
	uint32_t db : 1;
	uint32_t DBit : 1;
	uint32_t da : 2;
	uint32_t B2 : 4;
	uint32_t G2 : 4;
	uint32_t R2 : 4;
	uint32_t B : 4;
	uint32_t G : 4;
	uint32_t R_10 : 2;
	uint32_t Ign0 : 1;
	uint32_t R_32 : 2;
	uint32_t Ign1 : 3;
};

struct HModeData
{
	uint16_t Indices0;
	uint16_t Indices1;
	uint32_t db : 1;
	uint32_t DBit : 1;
	uint32_t da : 1;
	uint32_t B2 : 4;
	uint32_t G2 : 4;
	uint32_t R2 : 4;
	uint32_t B_20 : 3;
	uint32_t Ign0 : 1;
	uint32_t B_3 : 1;
	uint32_t G_0 : 1;
	uint32_t Ign1 : 3;
	uint32_t G_31 : 3;
	uint32_t R : 4;
	uint32_t Ign2 : 1;
};

struct PModeData
{
	uint32_t Bv : 6;
	uint32_t Gv : 7;
	uint32_t Rv : 6;
	uint32_t Bh : 6;
	uint32_t Gh : 7;
	uint32_t Rh_0 : 1;
	uint32_t DBit : 1;
	uint32_t Rh_51 : 5;
	uint32_t B_20 : 3;
	uint32_t Ign0 : 1;
	uint32_t B_43 : 2;
	uint32_t Ign1 : 3;
	uint32_t B_5 : 1;
	uint32_t G_50 : 6;
	uint32_t Ign2 : 1;
	uint32_t G_6 : 1;
	uint32_t R : 6;
	uint32_t Ign3 : 1;
};


static const int32_t MTable[][4] = {
	2, 8, -2, -8,
	5, 17, -5, -17,
	9, 29, -9, -29,
	13, 42, -13, -42,
	18, 60, -18, -60,
	24, 80, -24, -80,
	33, 106, -33, -106,
	47, 183, -47, -183,
};

static const uint32_t DistanceTable[] = { 3, 6, 11, 16, 23, 32, 41, 64 };

static const uint8_t MTable8[][2] = {
	2, 8,
	5, 17,
	9, 29,
	13, 42,
	18, 60,
	24, 80,
	33, 106,
	47, 183, 
};

static const __m128i SWMask[] = {
	// SWMask = _mm_set_epi32(0x01010000, 0x01010000, 0x01010000, 0x01010000);
	// SWMask = _mm_set_epi32(0x01010101, 0x01010101, 0x00000000, 0x00000000);
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};

static const uint16_t MTable16[][2] = {
	0x0202, 0x0808, 0x0502, 0x1108, 0x0902, 0x1d08, 0x0d02, 0x2a08, 0x1202, 0x3c08, 0x1802, 0x5008, 0x2102, 0x6a08, 0x2f02, 0xb708, 
	0x0205, 0x0811, 0x0505, 0x1111, 0x0905, 0x1d11, 0x0d05, 0x2a11, 0x1205, 0x3c11, 0x1805, 0x5011, 0x2105, 0x6a11, 0x2f05, 0xb711, 
	0x0209, 0x081d, 0x0509, 0x111d, 0x0909, 0x1d1d, 0x0d09, 0x2a1d, 0x1209, 0x3c1d, 0x1809, 0x501d, 0x2109, 0x6a1d, 0x2f09, 0xb71d, 
	0x020d, 0x082a, 0x050d, 0x112a, 0x090d, 0x1d2a, 0x0d0d, 0x2a2a, 0x120d, 0x3c2a, 0x180d, 0x502a, 0x210d, 0x6a2a, 0x2f0d, 0xb72a, 
	0x0212, 0x083c, 0x0512, 0x113c, 0x0912, 0x1d3c, 0x0d12, 0x2a3c, 0x1212, 0x3c3c, 0x1812, 0x503c, 0x2112, 0x6a3c, 0x2f12, 0xb73c, 
	0x0218, 0x0850, 0x0518, 0x1150, 0x0918, 0x1d50, 0x0d18, 0x2a50, 0x1218, 0x3c50, 0x1818, 0x5050, 0x2118, 0x6a50, 0x2f18, 0xb750, 
	0x0221, 0x086a, 0x0521, 0x116a, 0x0921, 0x1d6a, 0x0d21, 0x2a6a, 0x1221, 0x3c6a, 0x1821, 0x506a, 0x2121, 0x6a6a, 0x2f21, 0xb76a, 
	0x022f, 0x08b7, 0x052f, 0x11b7, 0x092f, 0x1db7, 0x0d2f, 0x2ab7, 0x122f, 0x3cb7, 0x182f, 0x50b7, 0x212f, 0x6ab7, 0x2f2f, 0xb7b7, 
};

static const uint16_t DModeDecTable[] = {
	0x0000, 0x0800, 0x1000, 0x1800, 0xf800, 0xf800, 0xf800, 0xf800, 0x0808, 0x1008, 0x1808, 0x2108, 0xf800, 0xf800, 0xf800, 0x0008, 
	0x1010, 0x1810, 0x2110, 0x2910, 0xf800, 0xf800, 0x0010, 0x0810, 0x1818, 0x2118, 0x2918, 0x3118, 0xf800, 0x0018, 0x0818, 0x1018, 
	0x2121, 0x2921, 0x3121, 0x3921, 0x0021, 0x0821, 0x1021, 0x1821, 0x2929, 0x3129, 0x3929, 0x4229, 0x0829, 0x1029, 0x1829, 0x2129, 
	0x3131, 0x3931, 0x4231, 0x4a31, 0x1031, 0x1831, 0x2131, 0x2931, 0x3939, 0x4239, 0x4a39, 0x5239, 0x1839, 0x2139, 0x2939, 0x3139, 
	0x4242, 0x4a42, 0x5242, 0x5a42, 0x2142, 0x2942, 0x3142, 0x3942, 0x4a4a, 0x524a, 0x5a4a, 0x634a, 0x294a, 0x314a, 0x394a, 0x424a, 
	0x5252, 0x5a52, 0x6352, 0x6b52, 0x3152, 0x3952, 0x4252, 0x4a52, 0x5a5a, 0x635a, 0x6b5a, 0x735a, 0x395a, 0x425a, 0x4a5a, 0x525a, 
	0x6363, 0x6b63, 0x7363, 0x7b63, 0x4263, 0x4a63, 0x5263, 0x5a63, 0x6b6b, 0x736b, 0x7b6b, 0x846b, 0x4a6b, 0x526b, 0x5a6b, 0x636b, 
	0x7373, 0x7b73, 0x8473, 0x8c73, 0x5273, 0x5a73, 0x6373, 0x6b73, 0x7b7b, 0x847b, 0x8c7b, 0x947b, 0x5a7b, 0x637b, 0x6b7b, 0x737b, 
	0x8484, 0x8c84, 0x9484, 0x9c84, 0x6384, 0x6b84, 0x7384, 0x7b84, 0x8c8c, 0x948c, 0x9c8c, 0xa58c, 0x6b8c, 0x738c, 0x7b8c, 0x848c, 
	0x9494, 0x9c94, 0xa594, 0xad94, 0x7394, 0x7b94, 0x8494, 0x8c94, 0x9c9c, 0xa59c, 0xad9c, 0xb59c, 0x7b9c, 0x849c, 0x8c9c, 0x949c, 
	0xa5a5, 0xada5, 0xb5a5, 0xbda5, 0x84a5, 0x8ca5, 0x94a5, 0x9ca5, 0xadad, 0xb5ad, 0xbdad, 0xc6ad, 0x8cad, 0x94ad, 0x9cad, 0xa5ad, 
	0xb5b5, 0xbdb5, 0xc6b5, 0xceb5, 0x94b5, 0x9cb5, 0xa5b5, 0xadb5, 0xbdbd, 0xc6bd, 0xcebd, 0xd6bd, 0x9cbd, 0xa5bd, 0xadbd, 0xb5bd, 
	0xc6c6, 0xcec6, 0xd6c6, 0xdec6, 0xa5c6, 0xadc6, 0xb5c6, 0xbdc6, 0xcece, 0xd6ce, 0xdece, 0xe7ce, 0xadce, 0xb5ce, 0xbdce, 0xc6ce, 
	0xd6d6, 0xded6, 0xe7d6, 0xefd6, 0xb5d6, 0xbdd6, 0xc6d6, 0xced6, 0xdede, 0xe7de, 0xefde, 0xf7de, 0xbdde, 0xc6de, 0xcede, 0xd6de, 
	0xe7e7, 0xefe7, 0xf7e7, 0xffe7, 0xc6e7, 0xcee7, 0xd6e7, 0xdee7, 0xefef, 0xf7ef, 0xffef, 0xf800, 0xceef, 0xd6ef, 0xdeef, 0xe7ef, 
	0xf7f7, 0xfff7, 0xf800, 0xf800, 0xd6f7, 0xdef7, 0xe7f7, 0xeff7, 0xffff, 0xf800, 0xf800, 0xf800, 0xdeff, 0xe7ff, 0xefff, 0xf7ff,
};

static const uint16_t ETC24to8Table[] = {
	0x0000, 0x1100, 0x2200, 0x3300, 0x4400, 0x5500, 0x6600, 0x7700, 0x8800, 0x9900, 0xaa00, 0xbb00, 0xcc00, 0xdd00, 0xee00, 0xff00, 
	0x0011, 0x1111, 0x2211, 0x3311, 0x4411, 0x5511, 0x6611, 0x7711, 0x8811, 0x9911, 0xaa11, 0xbb11, 0xcc11, 0xdd11, 0xee11, 0xff11, 
	0x0022, 0x1122, 0x2222, 0x3322, 0x4422, 0x5522, 0x6622, 0x7722, 0x8822, 0x9922, 0xaa22, 0xbb22, 0xcc22, 0xdd22, 0xee22, 0xff22, 
	0x0033, 0x1133, 0x2233, 0x3333, 0x4433, 0x5533, 0x6633, 0x7733, 0x8833, 0x9933, 0xaa33, 0xbb33, 0xcc33, 0xdd33, 0xee33, 0xff33, 
	0x0044, 0x1144, 0x2244, 0x3344, 0x4444, 0x5544, 0x6644, 0x7744, 0x8844, 0x9944, 0xaa44, 0xbb44, 0xcc44, 0xdd44, 0xee44, 0xff44, 
	0x0055, 0x1155, 0x2255, 0x3355, 0x4455, 0x5555, 0x6655, 0x7755, 0x8855, 0x9955, 0xaa55, 0xbb55, 0xcc55, 0xdd55, 0xee55, 0xff55, 
	0x0066, 0x1166, 0x2266, 0x3366, 0x4466, 0x5566, 0x6666, 0x7766, 0x8866, 0x9966, 0xaa66, 0xbb66, 0xcc66, 0xdd66, 0xee66, 0xff66, 
	0x0077, 0x1177, 0x2277, 0x3377, 0x4477, 0x5577, 0x6677, 0x7777, 0x8877, 0x9977, 0xaa77, 0xbb77, 0xcc77, 0xdd77, 0xee77, 0xff77, 
	0x0088, 0x1188, 0x2288, 0x3388, 0x4488, 0x5588, 0x6688, 0x7788, 0x8888, 0x9988, 0xaa88, 0xbb88, 0xcc88, 0xdd88, 0xee88, 0xff88, 
	0x0099, 0x1199, 0x2299, 0x3399, 0x4499, 0x5599, 0x6699, 0x7799, 0x8899, 0x9999, 0xaa99, 0xbb99, 0xcc99, 0xdd99, 0xee99, 0xff99, 
	0x00aa, 0x11aa, 0x22aa, 0x33aa, 0x44aa, 0x55aa, 0x66aa, 0x77aa, 0x88aa, 0x99aa, 0xaaaa, 0xbbaa, 0xccaa, 0xddaa, 0xeeaa, 0xffaa, 
	0x00bb, 0x11bb, 0x22bb, 0x33bb, 0x44bb, 0x55bb, 0x66bb, 0x77bb, 0x88bb, 0x99bb, 0xaabb, 0xbbbb, 0xccbb, 0xddbb, 0xeebb, 0xffbb, 
	0x00cc, 0x11cc, 0x22cc, 0x33cc, 0x44cc, 0x55cc, 0x66cc, 0x77cc, 0x88cc, 0x99cc, 0xaacc, 0xbbcc, 0xcccc, 0xddcc, 0xeecc, 0xffcc, 
	0x00dd, 0x11dd, 0x22dd, 0x33dd, 0x44dd, 0x55dd, 0x66dd, 0x77dd, 0x88dd, 0x99dd, 0xaadd, 0xbbdd, 0xccdd, 0xdddd, 0xeedd, 0xffdd, 
	0x00ee, 0x11ee, 0x22ee, 0x33ee, 0x44ee, 0x55ee, 0x66ee, 0x77ee, 0x88ee, 0x99ee, 0xaaee, 0xbbee, 0xccee, 0xddee, 0xeeee, 0xffee, 
	0x00ff, 0x11ff, 0x22ff, 0x33ff, 0x44ff, 0x55ff, 0x66ff, 0x77ff, 0x88ff, 0x99ff, 0xaaff, 0xbbff, 0xccff, 0xddff, 0xeeff, 0xffff,
};

static const uint8_t PMode6to8Table[] = {
	0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 
	0x41, 0x45, 0x49, 0x4d, 0x51, 0x55, 0x59, 0x5d, 0x61, 0x65, 0x69, 0x6d, 0x71, 0x75, 0x79, 0x7d, 
	0x82, 0x86, 0x8a, 0x8e, 0x92, 0x96, 0x9a, 0x9e, 0xa2, 0xa6, 0xaa, 0xae, 0xb2, 0xb6, 0xba, 0xbe, 
	0xc3, 0xc7, 0xcb, 0xcf, 0xd3, 0xd7, 0xdb, 0xdf, 0xe3, 0xe7, 0xeb, 0xef, 0xf3, 0xf7, 0xfb, 0xff,
};

#define Ext4to8(x) ((x) | ((x) << 4))
#define Ext5to8(x) (((x) << 3) | ((x) >> 2))
#define Ext6to8(x) (((x) << 2) | ((x) >> 4))
#define Ext7to8(x) (((x) << 1) | ((x) >> 6))


static uint32_t ETC2GetMode(uint64_t* pBlock)
{
	//struct DModeData Block = *(struct DModeData*)pBlock;
	uint32_t BlockLo = *((uint32_t*)pBlock + 0);
	uint32_t BlockHi = *((uint32_t*)pBlock + 1);
	struct DModeSelData Block = *(struct DModeSelData*)&BlockHi;

	if(Block.DBit == 0){
		return ETC2_MODE_INDIVIDUAL;
	}else{
		uint32_t RI = BlockHi >> 24;

		if(DModeDecTable[RI] == ETC2_DMODE_OVERFLOW_VALUE){
			return ETC2_MODE_T;
		}else{
			uint32_t GI = (BlockHi >> 16) & 0xff;

			if(DModeDecTable[GI] == ETC2_DMODE_OVERFLOW_VALUE){
				return ETC2_MODE_H;
			}else{
				uint32_t BI = (BlockHi >> 8) & 0xff;

				if(DModeDecTable[BI] == ETC2_DMODE_OVERFLOW_VALUE){
					return ETC2_MODE_PLANAR;
				}else{
					return ETC2_MODE_DIFFERENTIAL;
				}
			}
		}
	}
}


//#define GetIndex(Ind0, Ind1, N) (((((Ind0) >> (N)) & 0x1) | (((Ind1) >> (N)) << 1)) & 0x3)
static inline uint32_t GetIndex(uint16_t Ind0, uint16_t Ind1, uint32_t N)
{
	Ind0 = Ind0 >> N;
	Ind1 = Ind1 >> N;

	return (Ind0 & 0x1) | ((Ind1 & 0x1) << 1);
}

static inline uint8_t Clamp(int32_t Value)
{
	if(Value < 0){
		return 0;
	}

	if(Value > 255){
		return 255;
	}

	return Value;
}

static void ETC2DecIMode(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct IModeData Block = *(struct IModeData*)&Data;
	uint32_t R0 = Ext4to8(Block.R1);
	uint32_t G0 = Ext4to8(Block.G1);
	uint32_t B0 = Ext4to8(Block.B1);
	uint32_t R1 = Ext4to8(Block.R2);
	uint32_t G1 = Ext4to8(Block.G2);
	uint32_t B1 = Ext4to8(Block.B2);

	const int32_t* pTable0 = &MTable[Block.Table1][0];
	const int32_t* pTable1 = &MTable[Block.Table2][0];

	if(Block.FlipBit == 0){
		for(uint32_t r = 0; r < 4; r++){
			for(uint32_t c = 0; c < 2; c++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B0 + pTable0[Index]);
			}

			for(uint32_t c = 2; c < 4; c++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B1 + pTable1[Index]);
			}
		}
	}else{
		for(uint32_t c = 0; c < 4; c++){
			for(uint32_t r = 0; r < 2; r++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B0 + pTable0[Index]);
			}

			for(uint32_t r = 2; r < 4; r++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B1 + pTable1[Index]);
			}
		}
	}
}

static void ETC2DecDMode(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	const uint32_t SMask = 1 << 2;
	struct DModeData Block = *(struct DModeData*)&Data;
	uint32_t R0 = Ext5to8(Block.R);
	uint32_t G0 = Ext5to8(Block.G);
	uint32_t B0 = Ext5to8(Block.B);
	int32_t Rd = ((int32_t)Block.Rd ^ SMask) - SMask;
	int32_t Gd = ((int32_t)Block.Gd ^ SMask) - SMask;
	int32_t Bd = ((int32_t)Block.Bd ^ SMask) - SMask;
	uint32_t R1 = Ext5to8(Block.R + Rd);
	uint32_t G1 = Ext5to8(Block.G + Gd);
	uint32_t B1 = Ext5to8(Block.B + Bd);

	const int32_t* pTable0 = &MTable[Block.Table1][0];
	const int32_t* pTable1 = &MTable[Block.Table2][0];

	if(Block.FlipBit == 0){
		for(uint32_t r = 0; r < 4; r++){
			for(uint32_t c = 0; c < 2; c++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B0 + pTable0[Index]);
			}

			for(uint32_t c = 2; c < 4; c++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B1 + pTable1[Index]);
			}
		}
	}else{
		for(uint32_t c = 0; c < 4; c++){
			for(uint32_t r = 0; r < 2; r++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G0 + pTable0[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B0 + pTable0[Index]);
			}

			for(uint32_t r = 2; r < 4; r++){
				uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

				pDst[r * Stride + c * 3 + 0] = Clamp((int32_t)R1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 1] = Clamp((int32_t)G1 + pTable1[Index]);
				pDst[r * Stride + c * 3 + 2] = Clamp((int32_t)B1 + pTable1[Index]);
			}
		}
	}
}

static void ETC2DecTMode(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct TModeData Block = *(struct TModeData*)&Data;
	int32_t R0 = Ext4to8((Block.R_32 << 2) | Block.R_10);
	int32_t G0 = Ext4to8(Block.G);
	int32_t B0 = Ext4to8(Block.B);
	int32_t R1 = Ext4to8(Block.R2);
	int32_t G1 = Ext4to8(Block.G2);
	int32_t B1 = Ext4to8(Block.B2);
	uint32_t DI = (Block.da << 1) | Block.db;
	uint32_t Dist = DistanceTable[DI];
	uint32_t R[] = { R0, Clamp(R1 + Dist), R1, Clamp(R1 - Dist) };
	uint32_t G[] = { G0, Clamp(G1 + Dist), G1, Clamp(G1 - Dist) };
	uint32_t B[] = { B0, Clamp(B1 + Dist), B1, Clamp(B1 - Dist) };

	for(uint32_t r = 0; r < 4; r++){
		for(uint32_t c = 0; c < 4; c++){
			uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

			pDst[r * Stride + c * 3 + 0] = R[Index];
			pDst[r * Stride + c * 3 + 1] = G[Index];
			pDst[r * Stride + c * 3 + 2] = B[Index];
		}
	}
}

static void ETC2DecHMode(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct HModeData Block = *(struct HModeData*)&Data;
	int32_t R0 = Ext4to8(Block.R);
	int32_t G0 = Ext4to8((Block.G_31 << 1) | Block.G_0);
	int32_t B0 = Ext4to8((Block.B_3 << 3) | Block.B_20);
	int32_t R1 = Ext4to8(Block.R2);
	int32_t G1 = Ext4to8(Block.G2);
	int32_t B1 = Ext4to8(Block.B2);
	uint32_t BC0Value = (R0 << 16) + (G0 << 8) + B0;
	uint32_t BC1Value = (R1 << 16) + (G1 << 8) + B1;
	uint32_t DI = ((Block.da << 2) | (Block.db << 1)) + (BC0Value >= BC1Value ? 1 : 0);
	uint32_t Dist = DistanceTable[DI];
	uint32_t R[] = { Clamp(R0 + Dist), Clamp(R0 - Dist), Clamp(R1 + Dist), Clamp(R1 - Dist) };
	uint32_t G[] = { Clamp(G0 + Dist), Clamp(G0 - Dist), Clamp(G1 + Dist), Clamp(G1 - Dist) };
	uint32_t B[] = { Clamp(B0 + Dist), Clamp(B0 - Dist), Clamp(B1 + Dist), Clamp(B1 - Dist) };

	for(uint32_t r = 0; r < 4; r++){
		for(uint32_t c = 0; c < 4; c++){
			uint32_t Index = GetIndex(Block.Indices0, Block.Indices1, c * 4 + r);

			pDst[r * Stride + c * 3 + 0] = R[Index];
			pDst[r * Stride + c * 3 + 1] = G[Index];
			pDst[r * Stride + c * 3 + 2] = B[Index];
		}
	}
}

static void ETC2DecPMode(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct PModeData Block = *(struct PModeData*)&Data;
	int32_t R = Ext6to8(Block.R);
	int32_t G = Ext7to8((Block.G_6 << 6) | Block.G_50);
	int32_t B = Ext6to8((Block.B_5 << 5) | (Block.B_43 << 3) | Block.B_20);
	int32_t Rh = Ext6to8((Block.Rh_51 << 1) | Block.Rh_0);
	int32_t Gh = Ext7to8(Block.Gh);
	int32_t Bh = Ext6to8(Block.Bh);
	int32_t Rv = Ext6to8(Block.Rv);
	int32_t Gv = Ext7to8(Block.Gv);
	int32_t Bv = Ext6to8(Block.Bv);

	for(int32_t r = 0; r < 4; r++){
		for(int32_t c = 0; c < 4; c++){
			pDst[r * Stride + c * 3 + 0] = Clamp(((c * (Rh - R) + r * (Rv - R) + 2 + 4 * R) >> 2) + 0);
			pDst[r * Stride + c * 3 + 1] = Clamp(((c * (Gh - G) + r * (Gv - G) + 2 + 4 * G) >> 2) + 0);
			pDst[r * Stride + c * 3 + 2] = Clamp(((c * (Bh - B) + r * (Bv - B) + 2 + 4 * B) >> 2) + 0);
		}
	}
}

static inline void ETC2SaveRGB16(uint8_t* pDst, uint32_t Stride, __m128i R, __m128i G, __m128i B)
{
	__m128i RRow = _mm_shuffle_epi8(R, _mm_set_epi32(0xffffffff, 0xffff03ff, 0xff02ffff, 0x01ffff00));
	__m128i GRow = _mm_shuffle_epi8(G, _mm_set_epi32(0xffffffff, 0xff03ffff, 0x02ffff01, 0xffff00ff));
	__m128i BRow = _mm_shuffle_epi8(B, _mm_set_epi32(0xffffffff, 0x03ffff02, 0xffff01ff, 0xff00ffff));

	_mm_storeu_si128((__m128i*)(pDst + 0 * Stride), _mm_or_si128(_mm_or_si128(RRow, GRow), BRow));

	RRow = _mm_shuffle_epi8(R, _mm_set_epi32(0xffffffff, 0xffff07ff, 0xff06ffff, 0x05ffff04));
	GRow = _mm_shuffle_epi8(G, _mm_set_epi32(0xffffffff, 0xff07ffff, 0x06ffff05, 0xffff04ff));
	BRow = _mm_shuffle_epi8(B, _mm_set_epi32(0xffffffff, 0x07ffff06, 0xffff05ff, 0xff04ffff));

	_mm_storeu_si128((__m128i*)(pDst + 1 * Stride), _mm_or_si128(_mm_or_si128(RRow, GRow), BRow));

	RRow = _mm_shuffle_epi8(R, _mm_set_epi32(0xffffffff, 0xffff0bff, 0xff0affff, 0x09ffff08));
	GRow = _mm_shuffle_epi8(G, _mm_set_epi32(0xffffffff, 0xff0bffff, 0x0affff09, 0xffff08ff));
	BRow = _mm_shuffle_epi8(B, _mm_set_epi32(0xffffffff, 0x0bffff0a, 0xffff09ff, 0xff08ffff));

	_mm_storeu_si128((__m128i*)(pDst + 2 * Stride), _mm_or_si128(_mm_or_si128(RRow, GRow), BRow));

	RRow = _mm_shuffle_epi8(R, _mm_set_epi32(0xffffffff, 0xffff0fff, 0xff0effff, 0x0dffff0c));
	GRow = _mm_shuffle_epi8(G, _mm_set_epi32(0xffffffff, 0xff0fffff, 0x0effff0d, 0xffff0cff));
	BRow = _mm_shuffle_epi8(B, _mm_set_epi32(0xffffffff, 0x0fffff0e, 0xffff0dff, 0xff0cffff));

	_mm_storeu_si128((__m128i*)(pDst + 3 * Stride), _mm_or_si128(_mm_or_si128(RRow, GRow), BRow));
}

static __forceinline void ETC2DecIDModeSSE(uint8_t* pDst, uint32_t Stride, uint32_t R0R1, uint32_t G0G1, uint32_t B0B1, uint32_t BlockLo, const __m128i* pSWMask,
	const uint16_t* pTable0)
{
	// unpacking indexes
	__m128i IndexL = _mm_cvtsi32_si128(BlockLo);
	__m128i IndexH = IndexL;

	IndexL = _mm_shuffle_epi8(IndexL, _mm_set_epi32(0x01010000, 0x01010000, 0x01010000, 0x01010000));
	IndexH = _mm_shuffle_epi8(IndexH, _mm_set_epi32(0x03030202, 0x03030202, 0x03030202, 0x03030202));

	const __m128i Mask = _mm_set_epi32(0x80088008, 0x40044004, 0x20022002, 0x10011001);

	IndexL = _mm_and_si128(IndexL, Mask);
	IndexH = _mm_and_si128(IndexH, Mask);

	IndexL = _mm_cmpeq_epi8(IndexL, _mm_setzero_si128());
	IndexH = _mm_cmpeq_epi8(IndexH, _mm_setzero_si128());

	__m128i SWMask = _mm_load_si128(pSWMask);
	__m128i Offset0, Offset1; // Offset0 positive offsets, Offset1 negative offset
	__m128i Table0 = _mm_shuffle_epi8(_mm_cvtsi32_si128(pTable0[0]), SWMask);
	__m128i Table1 = _mm_shuffle_epi8(_mm_cvtsi32_si128(pTable0[1]), SWMask);

	Offset0 = _mm_and_si128(Table0, IndexL);
	Offset1 = _mm_andnot_si128(IndexL, Table1);
	Offset0 = _mm_or_si128(Offset0, Offset1);
	Offset1 = Offset0;

	Offset0 = _mm_and_si128(Offset0, IndexH);
	Offset1 = _mm_andnot_si128(IndexH, Offset1);

	__m128i R = _mm_shuffle_epi8(_mm_cvtsi32_si128(R0R1), SWMask);
	__m128i G = _mm_shuffle_epi8(_mm_cvtsi32_si128(G0G1), SWMask);
	__m128i B = _mm_shuffle_epi8(_mm_cvtsi32_si128(B0B1), SWMask);

	R = _mm_adds_epu8(R, Offset0);
	G = _mm_adds_epu8(G, Offset0);
	B = _mm_adds_epu8(B, Offset0);
	R = _mm_subs_epu8(R, Offset1);
	G = _mm_subs_epu8(G, Offset1);
	B = _mm_subs_epu8(B, Offset1);

	ETC2SaveRGB16(pDst, Stride, R, G, B);
}

static void ETC2DecIModeSSE(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct IModeData Block = *(struct IModeData*)&Data;
	uint32_t BlockLo = *((uint32_t*)&Data + 0);
	uint32_t BlockHi = *((uint32_t*)&Data + 1);
	uint32_t R0R1 = ETC24to8Table[BlockHi >> 24];
	uint32_t G0G1 = ETC24to8Table[(BlockHi >> 16) & 0xff];
	uint32_t B0B1 = ETC24to8Table[(BlockHi >> 8) & 0xff];

	uint32_t TableIndex = (BlockHi >> 2) & 0x3f;

	/*uint32_t R0R1 = ((RGB1 >> 16) & 0xff00) | (RGB0 >> 24);

	__m128i R = _mm_shuffle_epi8(_mm_cvtsi32_si128(R0R1), SWMask);
	__m128i G = _mm_shuffle_epi8(_mm_cvtsi32_si128(G0G1), SWMask);
	__m128i B = _mm_shuffle_epi8(_mm_cvtsi32_si128(B0B1), SWMask);*/


	ETC2DecIDModeSSE(pDst, Stride, R0R1, G0G1, B0B1, BlockLo, &SWMask[Block.FlipBit], &MTable16[TableIndex][0]);
}

static void ETC2DecDModeSSE(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct DModeData Block = *(struct DModeData*)&Data;
	uint32_t BlockLo = *((uint32_t*)&Data + 0);
	uint32_t BlockHi = *((uint32_t*)&Data + 1);

	uint32_t RI = BlockHi >> 24;
	uint32_t GI = (BlockHi >> 16) & 0xff;
	uint32_t BI = (BlockHi >> 8) & 0xff;

	uint32_t TableIndex = (BlockHi >> 2) & 0x3f;

	ETC2DecIDModeSSE(pDst, Stride, DModeDecTable[RI], DModeDecTable[GI], DModeDecTable[BI], BlockLo, &SWMask[Block.FlipBit], &MTable16[TableIndex][0]);
}

static inline __m128i PModeCalcCh(uint32_t C, uint32_t Ch, uint32_t Cv)
{
	const __m128i U16Mask = _mm_set_epi32(0x01000100, 0x01000100, 0x01000100, 0x01000100);
	const __m128i CMult = _mm_set_epi32(0x00030002, 0x00010000, 0x00030002, 0x00010000);
	__m128i R0, R1, RT0, RT1;

	R0 = _mm_shuffle_epi8(_mm_cvtsi32_si128(Ch - C), U16Mask);
	R0 = _mm_mullo_epi16(R0, CMult);

	RT0 = RT1 = _mm_shuffle_epi8(_mm_cvtsi32_si128(Cv - C), U16Mask);
	RT0 = _mm_slli_si128(RT0, 8);
	RT1 = _mm_add_epi16(RT1, RT1);
	RT1 = _mm_add_epi16(RT1, RT0);

	R1 = _mm_shuffle_epi8(_mm_cvtsi32_si128((C << 2) + 2), U16Mask);
	R0 = _mm_add_epi16(R0, R1);
	R1 = R0;

	R0 = _mm_add_epi16(R0, RT0);
	R1 = _mm_add_epi16(R1, RT1);

	R0 = _mm_srai_epi16(R0, 2);
	R1 = _mm_srai_epi16(R1, 2);

	R0 = _mm_packus_epi16(R0, R1);

	return R0;
}

static void ETC2DecPModeSSE(uint8_t* pDst, uint32_t Stride, uint64_t Data)
{
	struct PModeData Block = *(struct PModeData*)&Data;
	int32_t R = PMode6to8Table[Block.R];//Ext6to8(Block.R);
	int32_t G = Ext7to8((Block.G_6 << 6) | Block.G_50);
	int32_t B = PMode6to8Table[(Block.B_5 << 5) | (Block.B_43 << 3) | Block.B_20];//((Block.B_5 << 5) | (Block.B_43 << 3) | Block.B_20);
	int32_t Rh = PMode6to8Table[(Block.Rh_51 << 1) | Block.Rh_0];//((Block.Rh_51 << 1) | Block.Rh_0);
	int32_t Gh = Ext7to8(Block.Gh);
	int32_t Bh = PMode6to8Table[Block.Bh];//Ext6to8(Block.Bh);
	int32_t Rv = PMode6to8Table[Block.Rv];//Ext6to8(Block.Rv);
	int32_t Gv = Ext7to8(Block.Gv);
	int32_t Bv = PMode6to8Table[Block.Bv];//Ext6to8(Block.Bv);

	__m128i R0 = PModeCalcCh(R, Rh, Rv);
	__m128i G0 = PModeCalcCh(G, Gh, Gv);
	__m128i B0 = PModeCalcCh(B, Bh, Bv);


	ETC2SaveRGB16(pDst, Stride, R0, G0, B0);
}

static inline void ETC1DecodeRGBSSE(uint8_t* pDst, uint32_t Stride, uint64_t Block)
{
	uint32_t BlockLo = *((uint32_t*)&Block + 0);
	uint32_t BlockHi = *((uint32_t*)&Block + 1);
	uint32_t R0R1, G0G1, B0B1;

	uint32_t TableIndex = (BlockHi >> 2) & 0x3f;

	if((Block & 0x200000000) == 0){
		R0R1 = ETC24to8Table[BlockHi >> 24];
		G0G1 = ETC24to8Table[(BlockHi >> 16) & 0xff];
		B0B1 = ETC24to8Table[(BlockHi >> 8) & 0xff];
	}else{
		R0R1 = DModeDecTable[BlockHi >> 24];
		G0G1 = DModeDecTable[(BlockHi >> 16) & 0xff];
		B0B1 = DModeDecTable[(BlockHi >> 8) & 0xff];
	}

	ETC2DecIDModeSSE(pDst, Stride, R0R1, G0G1, B0B1, BlockLo, &SWMask[BlockHi & 0x1], &MTable16[TableIndex][0]);
}

static void ETC2DecodeRGBSSE(uint8_t* pDst, uint32_t Stride, uint64_t Block)
{
	uint32_t BlockLo = *((uint32_t*)&Block + 0);
	uint32_t BlockHi = *((uint32_t*)&Block + 1);
	//struct DModeSelData Block = *(struct DModeSelData*)&BlockHi;
	uint32_t RI = BlockHi >> 24;

	if((Block & 0x200000000) == 0){
		uint32_t R0R1 = ETC24to8Table[RI];
		uint32_t G0G1 = ETC24to8Table[(BlockHi >> 16) & 0xff];
		uint32_t B0B1 = ETC24to8Table[(BlockHi >> 8) & 0xff];
		uint32_t TableIndex = (BlockHi >> 2) & 0x3f;

		ETC2DecIDModeSSE(pDst, Stride, R0R1, G0G1, B0B1, BlockLo, &SWMask[BlockHi & 0x1], &MTable16[TableIndex][0]);
	}else{
		uint32_t R0R1 = DModeDecTable[RI];

		if(R0R1 == ETC2_DMODE_OVERFLOW_VALUE){
			ETC2DecTMode(pDst, Stride, Block);
		}else{
			uint32_t GI = (BlockHi >> 16) & 0xff;
			uint32_t G0G1 = DModeDecTable[GI];

			if(G0G1 == ETC2_DMODE_OVERFLOW_VALUE){
				ETC2DecHMode(pDst, Stride, Block);
			}else{
				uint32_t BI = (BlockHi >> 8) & 0xff;
				uint32_t B0B1 = DModeDecTable[BI];

				if(B0B1 == ETC2_DMODE_OVERFLOW_VALUE){
					ETC2DecPModeSSE(pDst, Stride, Block);
				}else{
					uint32_t TableIndex = (BlockHi >> 2) & 0x3f;

					ETC2DecIDModeSSE(pDst, Stride, R0R1, G0G1, B0B1, BlockLo, &SWMask[BlockHi & 0x1], &MTable16[TableIndex][0]);
				}
			}
		}
	}
}