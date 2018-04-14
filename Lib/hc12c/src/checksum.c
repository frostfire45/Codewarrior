/******************************************************************************
  FILE        : checksum.c
  PURPOSE     : generic checksum utility functions
  LANGUAGE    : ANSI-C
  -----------------------------------------------------------------------------
  HISTORY
    19 sep 2002       Created.
  General notes:
  We do define here more functions than anyone would like to use at one time.
  Or in other words, we rely on the linker to drop the non referenced functions.
  So don't switch of smart linking for this module.
 ******************************************************************************/
#include "checksum.h"

#ifndef __HIWARE__ /* HIWARE target compilers are using the tables, any host compiler computes them */
#define ENABLE_CALCULATE_TABLES       1 /* calculate the precomputed tables */
#else
#define ENABLE_CALCULATE_TABLES       0
#endif

#ifndef ENABLE_PRECOMPUTE
#define ENABLE_PRECOMPUTE (!ENABLE_CALCULATE_TABLES && 1) /* 1: use tables: much faster, but needs more ROM */
#endif

#if ENABLE_PRECOMPUTE

/* Description:
The CRC algorithm is in its generic form is a loop over 8 bits where in every loop
  a 1 bit shift is performed. If in this shift a one bit drops out of the value,
  a number (the polynom) is xored into the value.
  Because of this, only the 8 leading bits and the polynom control
  when to which positions the polynom is xorded. The tables below just
  precompute this for all 256 values of the leading byte.
  These tables are therefore only usable for a specific polynom
  (the ones called default in checksum.h). But at the bottom of this
  file is the code to compute these tables. This code can easily be
  adapted for different polynoms.
*/

/* CRC8 */
static const _CheckSum1ByteType TableCRC8[256]= {
/*            0,     1,     2,     3,     4,     5,     6,     7,*/
/*   0 */     0,   155,   173,    54,   193,    90,   108,   247,
/*   8 */    25,   130,   180,    47,   216,    67,   117,   238,
/*  16 */    50,   169,   159,     4,   243,   104,    94,   197,
/*  24 */    43,   176,   134,    29,   234,   113,    71,   220,
/*  32 */   100,   255,   201,    82,   165,    62,     8,   147,
/*  40 */   125,   230,   208,    75,   188,    39,    17,   138,
/*  48 */    86,   205,   251,    96,   151,    12,    58,   161,
/*  56 */    79,   212,   226,   121,   142,    21,    35,   184,
/*  64 */   200,    83,   101,   254,     9,   146,   164,    63,
/*  72 */   209,    74,   124,   231,    16,   139,   189,    38,
/*  80 */   250,    97,    87,   204,    59,   160,   150,    13,
/*  88 */   227,   120,    78,   213,    34,   185,   143,    20,
/*  96 */   172,    55,     1,   154,   109,   246,   192,    91,
/* 104 */   181,    46,    24,   131,   116,   239,   217,    66,
/* 112 */   158,     5,    51,   168,    95,   196,   242,   105,
/* 120 */   135,    28,    42,   177,    70,   221,   235,   112,
/* 128 */    11,   144,   166,    61,   202,    81,   103,   252,
/* 136 */    18,   137,   191,    36,   211,    72,   126,   229,
/* 144 */    57,   162,   148,    15,   248,    99,    85,   206,
/* 152 */    32,   187,   141,    22,   225,   122,    76,   215,
/* 160 */   111,   244,   194,    89,   174,    53,     3,   152,
/* 168 */   118,   237,   219,    64,   183,    44,    26,   129,
/* 176 */    93,   198,   240,   107,   156,     7,    49,   170,
/* 184 */    68,   223,   233,   114,   133,    30,    40,   179,
/* 192 */   195,    88,   110,   245,     2,   153,   175,    52,
/* 200 */   218,    65,   119,   236,    27,   128,   182,    45,
/* 208 */   241,   106,    92,   199,    48,   171,   157,     6,
/* 216 */   232,   115,    69,   222,    41,   178,   132,    31,
/* 224 */   167,    60,    10,   145,   102,   253,   203,    80,
/* 232 */   190,    37,    19,   136,   127,   228,   210,    73,
/* 240 */   149,    14,    56,   163,    84,   207,   249,    98,
/* 248 */   140,    23,    33,   186,    77,   214,   224,   123,
};

/* CRC16 */
static const _CheckSum2ByteType TableCRC16[256]= {
/*            0,     1,     2,     3,     4,     5,     6,     7,*/
/*   0 */     0, 32773, 32783,    10, 32795,    30,    20, 32785,
/*   8 */ 32819,    54,    60, 32825,    40, 32813, 32807,    34,
/*  16 */ 32867,   102,   108, 32873,   120, 32893, 32887,   114,
/*  24 */    80, 32853, 32863,    90, 32843,    78,    68, 32833,
/*  32 */ 32963,   198,   204, 32969,   216, 32989, 32983,   210,
/*  40 */   240, 33013, 33023,   250, 33003,   238,   228, 32993,
/*  48 */   160, 32933, 32943,   170, 32955,   190,   180, 32945,
/*  56 */ 32915,   150,   156, 32921,   136, 32909, 32903,   130,
/*  64 */ 33155,   390,   396, 33161,   408, 33181, 33175,   402,
/*  72 */   432, 33205, 33215,   442, 33195,   430,   420, 33185,
/*  80 */   480, 33253, 33263,   490, 33275,   510,   500, 33265,
/*  88 */ 33235,   470,   476, 33241,   456, 33229, 33223,   450,
/*  96 */   320, 33093, 33103,   330, 33115,   350,   340, 33105,
/* 104 */ 33139,   374,   380, 33145,   360, 33133, 33127,   354,
/* 112 */ 33059,   294,   300, 33065,   312, 33085, 33079,   306,
/* 120 */   272, 33045, 33055,   282, 33035,   270,   260, 33025,
/* 128 */ 33539,   774,   780, 33545,   792, 33565, 33559,   786,
/* 136 */   816, 33589, 33599,   826, 33579,   814,   804, 33569,
/* 144 */   864, 33637, 33647,   874, 33659,   894,   884, 33649,
/* 152 */ 33619,   854,   860, 33625,   840, 33613, 33607,   834,
/* 160 */   960, 33733, 33743,   970, 33755,   990,   980, 33745,
/* 168 */ 33779,  1014,  1020, 33785,  1000, 33773, 33767,   994,
/* 176 */ 33699,   934,   940, 33705,   952, 33725, 33719,   946,
/* 184 */   912, 33685, 33695,   922, 33675,   910,   900, 33665,
/* 192 */   640, 33413, 33423,   650, 33435,   670,   660, 33425,
/* 200 */ 33459,   694,   700, 33465,   680, 33453, 33447,   674,
/* 208 */ 33507,   742,   748, 33513,   760, 33533, 33527,   754,
/* 216 */   720, 33493, 33503,   730, 33483,   718,   708, 33473,
/* 224 */ 33347,   582,   588, 33353,   600, 33373, 33367,   594,
/* 232 */   624, 33397, 33407,   634, 33387,   622,   612, 33377,
/* 240 */   544, 33317, 33327,   554, 33339,   574,   564, 33329,
/* 248 */ 33299,   534,   540, 33305,   520, 33293, 33287,   514,
};

/* CRC32 */
static const _CheckSum4ByteType TableCRC32[256]= {
/*                 0,          1,          2,          3,*/
/*   0 */          0,   79764919,  159529838,  222504665,
/*   4 */  319059676,  398814059,  445009330,  507990021,
/*   8 */  638119352,  583659535,  797628118,  726387553,
/*  12 */  890018660,  835552979, 1015980042,  944750013,
/*  16 */ 1276238704, 1221641927, 1167319070, 1095957929,
/*  20 */ 1595256236, 1540665371, 1452775106, 1381403509,
/*  24 */ 1780037320, 1859660671, 1671105958, 1733955601,
/*  28 */ 2031960084, 2111593891, 1889500026, 1952343757,
/*  32 */ 2552477408, 2632100695, 2443283854, 2506133561,
/*  36 */ 2334638140, 2414271883, 2191915858, 2254759653,
/*  40 */ 3190512472, 3135915759, 3081330742, 3009969537,
/*  44 */ 2905550212, 2850959411, 2762807018, 2691435357,
/*  48 */ 3560074640, 3505614887, 3719321342, 3648080713,
/*  52 */ 3342211916, 3287746299, 3467911202, 3396681109,
/*  56 */ 4063920168, 4143685023, 4223187782, 4286162673,
/*  60 */ 3779000052, 3858754371, 3904687514, 3967668269,
/*  64 */  881225847,  809987520, 1023691545,  969234094,
/*  68 */  662832811,  591600412,  771767749,  717299826,
/*  72 */  311336399,  374308984,  453813921,  533576470,
/*  76 */   25881363,   88864420,  134795389,  214552010,
/*  80 */ 2023205639, 2086057648, 1897238633, 1976864222,
/*  84 */ 1804852699, 1867694188, 1645340341, 1724971778,
/*  88 */ 1587496639, 1516133128, 1461550545, 1406951526,
/*  92 */ 1302016099, 1230646740, 1142491917, 1087903418,
/*  96 */ 2896545431, 2825181984, 2770861561, 2716262478,
/* 100 */ 3215044683, 3143675388, 3055782693, 3001194130,
/* 104 */ 2326604591, 2389456536, 2200899649, 2280525302,
/* 108 */ 2578013683, 2640855108, 2418763421, 2498394922,
/* 112 */ 3769900519, 3832873040, 3912640137, 3992402750,
/* 116 */ 4088425275, 4151408268, 4197601365, 4277358050,
/* 120 */ 3334271071, 3263032808, 3476998961, 3422541446,
/* 124 */ 3585640067, 3514407732, 3694837229, 3640369242,
/* 128 */ 1762451694, 1842216281, 1619975040, 1682949687,
/* 132 */ 2047383090, 2127137669, 1938468188, 2001449195,
/* 136 */ 1325665622, 1271206113, 1183200824, 1111960463,
/* 140 */ 1543535498, 1489069629, 1434599652, 1363369299,
/* 144 */  622672798,  568075817,  748617968,  677256519,
/* 148 */  907627842,  853037301, 1067152940,  995781531,
/* 152 */   51762726,  131386257,  177728840,  240578815,
/* 156 */  269590778,  349224269,  429104020,  491947555,
/* 160 */ 4046411278, 4126034873, 4172115296, 4234965207,
/* 164 */ 3794477266, 3874110821, 3953728444, 4016571915,
/* 168 */ 3609705398, 3555108353, 3735388376, 3664026991,
/* 172 */ 3290680682, 3236090077, 3449943556, 3378572211,
/* 176 */ 3174993278, 3120533705, 3032266256, 2961025959,
/* 180 */ 2923101090, 2868635157, 2813903052, 2742672763,
/* 184 */ 2604032198, 2683796849, 2461293480, 2524268063,
/* 188 */ 2284983834, 2364738477, 2175806836, 2238787779,
/* 192 */ 1569362073, 1498123566, 1409854455, 1355396672,
/* 196 */ 1317987909, 1246755826, 1192025387, 1137557660,
/* 200 */ 2072149281, 2135122070, 1912620623, 1992383480,
/* 204 */ 1753615357, 1816598090, 1627664531, 1707420964,
/* 208 */  295390185,  358241886,  404320391,  483945776,
/* 212 */   43990325,  106832002,  186451547,  266083308,
/* 216 */  932423249,  861060070, 1041341759,  986742920,
/* 220 */  613929101,  542559546,  756411363,  701822548,
/* 224 */ 3316196985, 3244833742, 3425377559, 3370778784,
/* 228 */ 3601682597, 3530312978, 3744426955, 3689838204,
/* 232 */ 3819031489, 3881883254, 3928223919, 4007849240,
/* 236 */ 4037393693, 4100235434, 4180117107, 4259748804,
/* 240 */ 2310601993, 2373574846, 2151335527, 2231098320,
/* 244 */ 2596047829, 2659030626, 2470359227, 2550115596,
/* 248 */ 2947551409, 2876312838, 2788305887, 2733848168,
/* 252 */ 3165939309, 3094707162, 3040238851, 2985771188,
};

/* CRC_CCITT */
static const _CheckSum2ByteType Table_CCITT[256]= {
/*            0,     1,     2,     3,     4,     5,     6,     7,*/
/*   0 */     0,  4129,  8258, 12387, 16516, 20645, 24774, 28903,
/*   8 */ 33032, 37161, 41290, 45419, 49548, 53677, 57806, 61935,
/*  16 */  4657,   528, 12915,  8786, 21173, 17044, 29431, 25302,
/*  24 */ 37689, 33560, 45947, 41818, 54205, 50076, 62463, 58334,
/*  32 */  9314, 13379,  1056,  5121, 25830, 29895, 17572, 21637,
/*  40 */ 42346, 46411, 34088, 38153, 58862, 62927, 50604, 54669,
/*  48 */ 13907,  9842,  5649,  1584, 30423, 26358, 22165, 18100,
/*  56 */ 46939, 42874, 38681, 34616, 63455, 59390, 55197, 51132,
/*  64 */ 18628, 22757, 26758, 30887,  2112,  6241, 10242, 14371,
/*  72 */ 51660, 55789, 59790, 63919, 35144, 39273, 43274, 47403,
/*  80 */ 23285, 19156, 31415, 27286,  6769,  2640, 14899, 10770,
/*  88 */ 56317, 52188, 64447, 60318, 39801, 35672, 47931, 43802,
/*  96 */ 27814, 31879, 19684, 23749, 11298, 15363,  3168,  7233,
/* 104 */ 60846, 64911, 52716, 56781, 44330, 48395, 36200, 40265,
/* 112 */ 32407, 28342, 24277, 20212, 15891, 11826,  7761,  3696,
/* 120 */ 65439, 61374, 57309, 53244, 48923, 44858, 40793, 36728,
/* 128 */ 37256, 33193, 45514, 41451, 53516, 49453, 61774, 57711,
/* 136 */  4224,   161, 12482,  8419, 20484, 16421, 28742, 24679,
/* 144 */ 33721, 37784, 41979, 46042, 49981, 54044, 58239, 62302,
/* 152 */   689,  4752,  8947, 13010, 16949, 21012, 25207, 29270,
/* 160 */ 46570, 42443, 38312, 34185, 62830, 58703, 54572, 50445,
/* 168 */ 13538,  9411,  5280,  1153, 29798, 25671, 21540, 17413,
/* 176 */ 42971, 47098, 34713, 38840, 59231, 63358, 50973, 55100,
/* 184 */  9939, 14066,  1681,  5808, 26199, 30326, 17941, 22068,
/* 192 */ 55628, 51565, 63758, 59695, 39368, 35305, 47498, 43435,
/* 200 */ 22596, 18533, 30726, 26663,  6336,  2273, 14466, 10403,
/* 208 */ 52093, 56156, 60223, 64286, 35833, 39896, 43963, 48026,
/* 216 */ 19061, 23124, 27191, 31254,  2801,  6864, 10931, 14994,
/* 224 */ 64814, 60687, 56684, 52557, 48554, 44427, 40424, 36297,
/* 232 */ 31782, 27655, 23652, 19525, 15522, 11395,  7392,  3265,
/* 240 */ 61215, 65342, 53085, 57212, 44955, 49082, 36825, 40952,
/* 248 */ 28183, 32310, 20053, 24180, 11923, 16050,  3793,  7920,
};


#endif /* ENABLE_PRECOMPUTE */

/*****************************************************************************/
/********* Utility functions treating 1 byte only for CRC checksums **********/
/*****************************************************************************/

/* CheckSumByteCRC_CCITT: calculate the CRC_CCITT checksum of a single additional byte */

_CheckSum2ByteType CheckSumByteCRC_CCITT(_CheckSum2ByteType crc, _CheckSum1ByteType val) {
    _CheckSum1ByteType temp, temp1;
    _CheckSum2ByteType quick, quick1;
    temp = (_CheckSum1ByteType)((crc >> 8) ^ val);
    temp1= (_CheckSum1ByteType)crc;
    crc = (_CheckSum2ByteType)(temp1 << 8);
    quick = (_CheckSum2ByteType)(temp ^ (temp >> 4));
    crc ^= quick;
#if 1 /* faster to use shifts by 4/8 */
    quick1 = quick << 4;
    crc ^= quick1 << 1;
    return crc ^ quick1 << 8;
#else
    quick <<= 5;
    crc ^= quick;
    quick <<= 7;
    crc ^= quick;
    return crc;
#endif
}

/* CheckSumByteCRC8: calculate the CRC8 checksum of a single additional byte */

_CheckSum1ByteType CheckSumByteCRC8(_CheckSum1ByteType crc, _CheckSum1ByteType val, _CheckSum1ByteType poly) {
    unsigned char temp;
    unsigned char index;

    for (index= 8; index != 0; index--) {
      temp = (unsigned char)((crc >> 7) ^ (val >> 7));
      crc <<= 1;
      val <<= 1;
      if (temp) {
        crc ^=  poly;
      }
    }
    return crc;
}

/* CheckSumByteCRC16: calculate the CRC16 checksum of a single additional byte */

_CheckSum2ByteType CheckSumByteCRC16(_CheckSum2ByteType crc, _CheckSum1ByteType val, _CheckSum2ByteType poly) {
    unsigned char index;
#if 1 /* how is it computed faster? */
    crc ^= (_CheckSum2ByteType)val << 8;
    for (index= 8; index != 0; index--) {
      if ((crc & 0x8000) != 0) {
        crc = (_CheckSum2ByteType)((crc << 1) ^ poly);
      } else {
        crc =  (_CheckSum2ByteType)(crc << 1);
      }
    }
#else
    unsigned char temp;
    for (index= 8; index != 0; index--) {
#if 1 /* how is it computed faster? */
      if ((crc & 0x8000) != 0) {
        temp= (val & 0x80) == 0;
      } else {
        temp= (val & 0x80) != 0;
      }
#else
      temp = (unsigned char)((crc >> 15) ^ (val >> 7));
#endif
      crc <<= 1;
      val <<= 1;
      if (temp) {
        crc ^=  poly;
      }
    }
#endif
    return crc;
}

/* CheckSumByteCRC32: calculate the CRC32 checksum of a single additional byte */

_CheckSum4ByteType CheckSumByteCRC32(_CheckSum4ByteType crc, _CheckSum1ByteType val, _CheckSum4ByteType poly) {
  unsigned char index;
  unsigned char temp;

  for (index= 8; index != 0; index--) {
    if ((crc & 0x80000000) != 0) { temp= (val & 0x80) == 0; } else { temp= (val & 0x80) != 0; }
    crc <<= 1;
    val <<= 1;
    if (temp) {
      crc ^=  poly;
    }
  }
  return crc;
}

#if ENABLE_PRECOMPUTE

_CheckSum2ByteType CheckSumByteCRC_CCITT_PreCalc(_CheckSum2ByteType crc, _CheckSum1ByteType val) {
  _CheckSum2ByteType tmp;
  _CheckSum2ByteType res;
  tmp= Table_CCITT[val ^ (crc >> 8)];
  res= (_CheckSum2ByteType)(tmp ^ ((crc & 0xff) << 8));
  return res;
}

_CheckSum1ByteType CheckSumByteCRC8_PreCalc(_CheckSum1ByteType crc, _CheckSum1ByteType val) {
  return TableCRC8[val ^ crc];
}

_CheckSum2ByteType CheckSumByteCRC16_PreCalc(_CheckSum2ByteType crc, _CheckSum1ByteType val) {
  _CheckSum2ByteType tmp= TableCRC16[val ^ (crc >> 8)];
  return(_CheckSum2ByteType)(tmp ^ ((crc & 0xff) << 8));
}

_CheckSum4ByteType CheckSumByteCRC32_PreCalc(_CheckSum4ByteType crc, _CheckSum1ByteType val) {
  _CheckSum4ByteType tmp= TableCRC32[val ^ (crc >> 24)];
  return tmp ^ (crc << 8);
}

#endif /* ENABLE_PRECOMPUTE */

#if ENABLE_CALCULATE_TABLES

static void ComputeCRC_CCITT_PreCalc(_CheckSum2ByteType* table) {
  _CheckSum1ByteType index= 0;
  do {
    _CheckSum2ByteType val= CheckSumByteCRC_CCITT((_CheckSum2ByteType)(index << 8), 0);
    table[index]= val;
    index++;
  } while ((index & 0xff) != 0); /* overflow */
}

static void ComputeCRC8_PreCalc(_CheckSum1ByteType* table, _CheckSum1ByteType poly) {
  _CheckSum1ByteType index= 0;
  do {
    _CheckSum1ByteType val= CheckSumByteCRC8((_CheckSum1ByteType)index, 0, poly);
    table[index]= val;
    index++;
  } while ((index & 0xff) != 0); /* overflow */
}

static void ComputeCRC16_PreCalc(_CheckSum2ByteType* table, _CheckSum2ByteType poly) {
  _CheckSum1ByteType index= 0;
  do {
    _CheckSum2ByteType val= CheckSumByteCRC16((_CheckSum2ByteType)(index << 8), 0, poly);
    table[index]= val;
    index++;
  } while ((index & 0xff) != 0); /* overflow */
}

static void ComputeCRC32_PreCalc(_CheckSum4ByteType* table, _CheckSum4ByteType poly) {
  _CheckSum1ByteType index= 0;
  do {
    _CheckSum4ByteType val= CheckSumByteCRC32((_CheckSum4ByteType)index << 24, 0, poly);
    table[index]= val;
    index++;
  } while ((index & 0xff) != 0); /* overflow */
}

#endif /* ENABLE_CALCULATE_TABLES */

/*****************************************************************************/
/********* Utility functions calculating the checksum of an area. ************/
/*****************************************************************************/

/* _Checksum_CheckAreaCRC_CCITT: CRC CCITT checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaCRC_CCITT(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  /* ITU-TSS CRC for polynom G(x)=x**16+x**12+x**5+1  ("**" is for exponentiation) */
  const _CheckSum1ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  _CheckSum2ByteType crc = 0xFFFF;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC_CCITT(crc, *ptr);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /* == check->checkSumCRC_CCITT */
}

/* _Checksum_CheckAreaCRC8: CRC8 checksum of an aera */

_CheckSum1ByteType _Checksum_CheckAreaCRC8(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum1ByteType poly, _CheckSum1ByteType init) {
  const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType*_CHECKSUM_QUALI)start;
  _CheckSum1ByteType crc = init;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC8(crc, *ptr, poly);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /* == check->checkSumCRC8 */
}

/* _Checksum_CheckAreaCRC16: CRC16 checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaCRC16(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum2ByteType poly, _CheckSum2ByteType init) {
  const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType*_CHECKSUM_QUALI)start;
  _CheckSum2ByteType crc = init;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC16(crc, *ptr, poly);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /* == check->checkSumCRC16 */
}

/* _Checksum_CheckAreaCRC32: CRC32 checksum of an aera */

_CheckSum4ByteType _Checksum_CheckAreaCRC32(_CHECKSUM_ConstMemBytePtr start, unsigned int len, _CheckSum4ByteType poly, _CheckSum4ByteType init) {
  const _CheckSum1ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  _CheckSum4ByteType crc = init;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC32(crc, *ptr, poly);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /*== check->checkSumCRC32 */
}

#if ENABLE_PRECOMPUTE

/* _Checksum_CheckAreaCRC_CCITT_PreCalc: CRC CCITT checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaCRC_CCITT_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  /* ITU-TSS CRC for polynom G(x)=x**16+x**12+x**5+1  ("**" is for exponentiation) */
  const _CheckSum1ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  _CheckSum2ByteType crc = 0xFFFF;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC_CCITT_PreCalc(crc, *ptr);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /* == check->checkSumCRC_CCITT */
}

/* _Checksum_CheckAreaCRC8_PreCalc: CRC8 checksum of an aera */

_CheckSum1ByteType _Checksum_CheckAreaCRC8_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType*_CHECKSUM_QUALI)start;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  _CheckSum1ByteType crc;
#if defined(__HC08__)
 /* HC08 HLI optimized version */
    /* we keep HX == ptr and A == crc in registers */
  asm {
    LDA #0xff;  /* initialize A with starting checksum */
    LDHX ptr;
    BRA check;
loop:                /* start of the inner loop */
}
    __FEED_COP;      /* COP enabled? If so, feed it */
  asm {              /* A == crc */
    EOR 0,X          /* A == crc ^ *ptr */
    AIX #1           /* p++    */
    PSHX             /* save HX so we can use it as index */
    PSHH
    CLRH
    TAX
    LDA @TableCRC8,X /* A = TableCRC8[crc ^ *ptr] == crc */
    PULH             /* restore HX == ptr  */
    PULX
check:
    CPX endPtr:1;    /* check low */
    BNE loop;        /* happens in 99% (255 of 256 cases) */
    PSHX             /* save X (so it can be used for the compare) */
    PSHH             /* move H->X */
    PULX
    CPX endPtr:0;    /* for the remaining 1% check high value */
    PULX             /* restore X. Note: does not modify flags */
    BNE loop;        /* not done? */
    STA crc;         /* pass result to C variable */
  }
#elif defined(__HC12__) && !defined(__LARGE__) && !defined(_CHECKSUM_USE_FAR_PTR)
  asm {
    LDAB #0xFF
    LDX ptr
    BRA comp

loop:
  }
  __FEED_COP;      /* COP enabled? If so, feed it */
  asm {
    EORB  1,X+
    LDY   #TableCRC8
    LDAB  B,Y
comp:
    CPX   endPtr
    BNE   loop
    STAB  crc
  }
#else
  crc = 0xFF;
  while (ptr != endPtr) {
#if 0  /* function call */
    crc= CheckSumByteCRC8_PreCalc(crc, *ptr);
#else  /* inline expanded */
    crc= TableCRC8[*ptr ^ crc];
#endif
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
#endif
  return crc; /* == check->checkSumCRC8 */
}

/* _Checksum_CheckAreaCRC16_PreCalc: CRC16 checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaCRC16_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType*_CHECKSUM_QUALI)start;
  _CheckSum2ByteType crc = 0xFFFF;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
#if defined(__HC12__) && !defined(__LARGE__) && !defined(_CHECKSUM_USE_FAR_PTR) /* HC12 HLI version, ca 40% faster than C version below */
  asm {
    LDD #0xFFFF
    LDX ptr
    BRA comp
loop:
  }
  __FEED_COP;      /* COP enabled? If so, feed it */
  asm {
    // tmp= TableCRC16[*ptr ^ (crc >> 8)];
    EORA  1,X+
    PSHB  ; save low byte of old CRC
    LDY   #TableCRC16
    LEAY  A,Y ; Y= A+TableCRC16
    LDD   A,Y ; load entry at A*2+TableCRC16
    // (_CheckSum2ByteType)(tmp ^ ((crc & 0xff) << 8));
    EORA  1,SP+ ; XOR low byte of old CRC to high byte and free stack
comp:
    CPX   endPtr
    BNE   loop
    STD   crc
  }
#else /* !(defined(__HC12__)  && !defined(__LARGE__) && !defined(_CHECKSUM_USE_FAR_PTR)) */
  while (ptr != endPtr) {
#if 0  /* function call */
    crc= CheckSumByteCRC16_PreCalc(crc, *ptr);
#elif defined(__HC08__) /* HC08 HLI version, ca 20% faster than C version below */
    asm {
     LDA   ptr
     PSHA
     LDX   ptr:1
     PULH
     LDA   0,X
     EOR   crc:0
     LSLA
     CLRX
     ROLX
     PSHX
     PULH
     TAX
     LDA   @TableCRC16,X
     EOR   crc:1
     STA   crc:0
     LDA   @TableCRC16:1,X
     STA   crc:1
  }
#else /* inline expanded */
    {
      _CheckSum2ByteType tmp= TableCRC16[*ptr ^ (crc >> 8)];
      crc= (_CheckSum2ByteType)(tmp ^ ((crc & 0xff) << 8));
    }
#endif

    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
#endif /* defined(__HC12__)  && !defined(__LARGE__) && !defined(_CHECKSUM_USE_FAR_PTR) */  
  return crc; /* == check->checkSumCRC16 */
}

/* _Checksum_CheckAreaCRC32_PreCalc: CRC32 checksum of an aera */

_CheckSum4ByteType _Checksum_CheckAreaCRC32_PreCalc(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  const _CheckSum1ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  _CheckSum4ByteType crc = 0xFFFFFFFF;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    crc= CheckSumByteCRC32_PreCalc(crc, *ptr);
    __FEED_COP;     /* COP enabled? If so, feed it */
    ptr++;
  }
  return crc; /*== check->checkSumCRC32 */
}

#endif /*ENABLE_PRECOMPUTE */

/* _Checksum_CheckAreaByteAdd: byte summation checksum of an aera */

_CheckSum1ByteType _Checksum_CheckAreaByteAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum1ByteType checkVal=0;
  const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal = (_CheckSum1ByteType)(checkVal + (*ptr));
    ptr++;
  }
  return checkVal;
}

/* _Checksum_CheckAreaWordAdd: word summation checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaWordAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum2ByteType checkVal=0;
  const _CheckSum2ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum2ByteType* _CHECKSUM_QUALI)start;
  while (len > 0) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal = (_CheckSum2ByteType)(checkVal + (*ptr));
    ptr++;
    len-= sizeof(*ptr);
  }
  return checkVal;
}

/* _Checksum_CheckAreaLongAdd: long summation checksum of an aera */

_CheckSum4ByteType _Checksum_CheckAreaLongAdd(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum4ByteType checkVal=0;
  const _CheckSum4ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum4ByteType* _CHECKSUM_QUALI)start;
  while (len > 0) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal += (*ptr);
    ptr++;
    len-= sizeof(*ptr);
  }
  return checkVal;
}

/* _Checksum_CheckAreaByteXor: byte xor checksum of an aera */

_CheckSum1ByteType _Checksum_CheckAreaByteXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum1ByteType checkVal=0;
  const _CheckSum1ByteType*_CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)start;
  const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + len;
  while (ptr != endPtr) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal ^= (*ptr);
    ptr++;
  }
  return checkVal;
}

/* _Checksum_CheckAreaWordXor: word xor checksum of an aera */

_CheckSum2ByteType _Checksum_CheckAreaWordXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum2ByteType checkVal=0;
  const _CheckSum2ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum2ByteType* _CHECKSUM_QUALI)start;
  while (len > 0) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal ^= (*ptr);
    ptr++;
    len-= sizeof(*ptr);
  }
  return checkVal;
}

/* _Checksum_CheckAreaLongXor: long xor checksum of an aera */

_CheckSum4ByteType _Checksum_CheckAreaLongXor(_CHECKSUM_ConstMemBytePtr start, unsigned int len) {
  _CheckSum4ByteType checkVal=0;
  const _CheckSum4ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum4ByteType* _CHECKSUM_QUALI)start;
  while (len > 0) {
    __FEED_COP;     /* COP enabled? If so, feed it */
    checkVal ^= (*ptr);
    ptr++;
    len-= sizeof(*ptr);
  }
  return checkVal;
}

int _Checksum_Check(const struct __Checksum* _CHECKSUM_QUALI check, int num) {
  /* returns TRUE when checksums are OK, FALSE otherwise */
  int i;

  for (i= 0; i < num; i++) {
#if _CHECKSUM_CRC_CCITT
#if ENABLE_PRECOMPUTE
    if (_Checksum_CheckAreaCRC_CCITT_PreCalc(check->start, check->len) != check->checkSumCRC_CCITT)
#else
    if (_Checksum_CheckAreaCRC_CCITT(check->start, check->len) != check->checkSumCRC_CCITT)
#endif
    {
      return FALSE;
    }
#endif
#if _CHECKSUM_CRC_8
#if ENABLE_PRECOMPUTE
    if (_Checksum_CheckAreaCRC8_PreCalc(check->start, check->len) != check->checkSumCRC8)
#else
    if (_Checksum_CheckAreaCRC8(check->start, check->len, DEFAULT_CRC8_CHECKSUM, 0xFF) != check->checkSumCRC8)
#endif
    {
      return FALSE;
    }
#endif
#if _CHECKSUM_CRC_16
#if ENABLE_PRECOMPUTE
    if (_Checksum_CheckAreaCRC16_PreCalc(check->start, check->len) != check->checkSumCRC16)
#else
    if (_Checksum_CheckAreaCRC16(check->start, check->len, DEFAULT_CRC16_CHECKSUM, 0xFFFF) != check->checkSumCRC16)
#endif
    {
      return FALSE;
    }
#endif
#if _CHECKSUM_CRC_32
#if ENABLE_PRECOMPUTE
    if (_Checksum_CheckAreaCRC32_PreCalc(check->start, check->len) != check->checkSumCRC32)
#else
    if (_Checksum_CheckAreaCRC32(check->start, check->len, DEFAULT_CRC32_CHECKSUM, 0xFFFFFFFF) != check->checkSumCRC32)
#endif
    {
      return FALSE;
    }
#endif
#if _CHECKSUM_ADD_BYTE
    if (_Checksum_CheckAreaByteAdd(check->start, check->len) != check->checkSumByteAdd) {
      return FALSE;
    }
#endif
#if _CHECKSUM_ADD_WORD
    if (_Checksum_CheckAreaWordAdd(check->start, check->len) != check->checkSumWordAdd) {
      return FALSE;
    }
#endif
#if _CHECKSUM_ADD_LONG
    if (_Checksum_CheckAreaLongAdd(check->start, check->len) != check->checkSumLongAdd) {
      return FALSE;
    }
#endif
#if _CHECKSUM_XOR_BYTE
    if (_Checksum_CheckAreaByteXor(check->start, check->len) != check->checkSumByteXor) {
      return FALSE;
    }
#endif
#if _CHECKSUM_XOR_WORD
    if (_Checksum_CheckAreaWordXor(check->start, check->len) != check->checkSumWordXor) {
      return FALSE;
    }
#endif
#if _CHECKSUM_XOR_LONG
    if (_Checksum_CheckAreaLongXor(check->start, check->len) != check->checkSumLongXor) {
      return FALSE;
    }
#endif
    check++;
  }
  return TRUE;
}

/*****************************************************************************/
/********* Utility functions calculating the single checksum for multiple memory areas. ************/
/*****************************************************************************/

/* _Checksum_CheckAreasLongXor: long xor checksum of multiple mem areas */

_CheckSum4ByteType _Checksum_CheckAreasLongXor(const struct __ChecksumArea * areas,int num) {
  _CheckSum4ByteType checkVal=0;
  int i;
  unsigned int len;

  for (i=0 ; i<num; i++) {
    const _CheckSum4ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum4ByteType* _CHECKSUM_QUALI)areas[i].start;
    len = areas[i].len;
    while (len > 0) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal ^= (*ptr);
      ptr++;
      len-= sizeof(*ptr);
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasWordXor: word xor checksum of multiple mem areas */

_CheckSum2ByteType _Checksum_CheckAreasWordXor(const struct __ChecksumArea * areas,int num) {
  _CheckSum2ByteType checkVal=0;
  int i;
  unsigned int len;
  for (i=0 ; i<num; i++) {
    const _CheckSum2ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum2ByteType* _CHECKSUM_QUALI )areas[i].start;
    len = areas[i].len;
    while (len > 0) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal ^= (*ptr);
      ptr++;
      len-= sizeof(*ptr);
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasByteXor: byte xor checksum of multiple mem areas */

_CheckSum1ByteType _Checksum_CheckAreasByteXor(const struct __ChecksumArea * areas,int num) {
  _CheckSum1ByteType checkVal=0;
  int i;

  for (i=0 ; i<num; i++) {
    const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    while (ptr != endPtr) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal ^= (*ptr);
      ptr++;
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasLongAdd: long summation checksum of multiple mem areas */

_CheckSum4ByteType _Checksum_CheckAreasLongAdd(const struct __ChecksumArea * areas,int num) {
  _CheckSum4ByteType checkVal=0;
  int i;
  unsigned int len;

  for (i=0 ; i < num; i++) {
    const _CheckSum4ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum4ByteType* _CHECKSUM_QUALI)areas[i].start;
    len = areas[i].len;
    while (len > 0) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal += (*ptr);
      ptr++;
      len-= sizeof(*ptr);
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasWordAdd: word summation checksum of multiple mem areas */

_CheckSum2ByteType _Checksum_CheckAreasWordAdd(const struct __ChecksumArea * areas,int num) {
  _CheckSum2ByteType checkVal=0;
  int i;
  unsigned int len;

  for (i=0 ; i<num; i++) {
    const _CheckSum2ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum2ByteType* _CHECKSUM_QUALI)areas[i].start;
    len = areas[i].len;
    while (len > 0) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal = (_CheckSum2ByteType)(checkVal + (*ptr));
      ptr++;
      len-= sizeof(*ptr);
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasByteAdd: byte summation checksum of multiple mem areas */

_CheckSum1ByteType _Checksum_CheckAreasByteAdd(const struct __ChecksumArea * areas,int num) {
  _CheckSum1ByteType checkVal=0;
  int i;

  for (i=0 ; i<num; i++) {
    const _CheckSum1ByteType*  _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType*  _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    while (ptr != endPtr) {
      __FEED_COP;     /* COP enabled? If so, feed it */
      checkVal = (_CheckSum1ByteType)(checkVal + (*ptr));
      ptr++;
    }
  }
  return checkVal;
}

/* _Checksum_CheckAreasCRC32: CRC32 checksum of multiple mem areas  */

_CheckSum4ByteType _Checksum_CheckAreasCRC32(const struct __ChecksumArea * areas,int num, _CheckSum4ByteType poly, _CheckSum4ByteType init) {
  _CheckSum4ByteType crc = init;
  int i;

  for (i=0 ; i<num; i++) {
    const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType*  _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    while (ptr != endPtr) {
      crc= CheckSumByteCRC32(crc, *ptr, poly);
      __FEED_COP;     /* COP enabled? If so, feed it */
      ptr++;
    }
  }
  return crc; /*== check->checkSumCRC32 */
}

_CheckSum1ByteType _Checksum_CheckAreasCRC8(const struct __ChecksumArea * areas,int num, _CheckSum1ByteType poly, _CheckSum1ByteType init) {
  _CheckSum1ByteType crc = init;
  int i;
  unsigned int len;

  for (i=0 ; i<num; i++) {
    const _CheckSum1ByteType * _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    len = areas[i].len;
    while (ptr != endPtr) {
      crc= CheckSumByteCRC8(crc, *ptr, poly);
      __FEED_COP;     /* COP enabled? If so, feed it */
      ptr++;
    }
  }
  return crc; /* == check->checkSumCRC8 */
}

/* _Checksum_CheckAreasCRC_CCITT: CRC CCITT checksum of multiple mem areas */

_CheckSum2ByteType _Checksum_CheckAreasCRC_CCITT(const struct __ChecksumArea * areas,int num,_CheckSum2ByteType init ) {
  /* ITU-TSS CRC for polynom G(x)=x**16+x**12+x**5+1  ("**" is for exponentiation) */
  _CheckSum2ByteType crc = init;
  int i;
  unsigned int len;

  for (i=0 ; i < num; i++) {
    const _CheckSum1ByteType* _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType* _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    len = areas[i].len;
    while (ptr != endPtr) {
      crc= CheckSumByteCRC_CCITT(crc, *ptr);
      __FEED_COP;     /* COP enabled? If so, feed it */
      ptr++;
    }
  }
  return crc; /* == check->checkSumCRC_CCITT */
}

/* _Checksum_CheckAreasCRC16: CRC16 checksum of multiple mem areas  */

_CheckSum2ByteType _Checksum_CheckAreasCRC16(const struct __ChecksumArea * areas,int num, _CheckSum2ByteType poly, _CheckSum2ByteType init) {
  _CheckSum2ByteType crc = init;
  int i;

  for (i=0 ; i<num; i++) {
    const _CheckSum1ByteType*  _CHECKSUM_QUALI ptr= (const _CheckSum1ByteType* _CHECKSUM_QUALI)areas[i].start;
    const _CheckSum1ByteType*  _CHECKSUM_QUALI endPtr= ptr + areas[i].len;
    while (ptr != endPtr) {
      crc= CheckSumByteCRC16(crc, *ptr, poly);
      __FEED_COP;     /* COP enabled? If so, feed it */
      ptr++;
    }
  }
  return crc; /* == check->checkSumCRC16 */
}

#if ENABLE_CALCULATE_TABLES
/* code which calculates and prints the tables above to stdout */
/* This code is intended for a host C compiler */

#include <stdio.h>

_CheckSum1ByteType TableCRC8[256];
_CheckSum2ByteType TableCRC16[256];
_CheckSum4ByteType TableCRC32[256];
_CheckSum2ByteType Table_CCITT[256];

int main(void) {
  int i;
  const int entriesPerLine16= 8;
  const int entriesPerLine32= 4;
  ComputeCRC8_PreCalc( TableCRC8,  DEFAULT_CRC8_CHECKSUM);
  ComputeCRC16_PreCalc(TableCRC16, DEFAULT_CRC16_CHECKSUM);
  ComputeCRC32_PreCalc(TableCRC32, DEFAULT_CRC32_CHECKSUM);
  ComputeCRC_CCITT_PreCalc(Table_CCITT);

  printf("/* CRC8 */\n");
  printf("static const _CheckSum1ByteType TableCRC8[256]= {\n/*       ");
  for (i= 0; i < entriesPerLine16; i++) {
    printf("%6u,", i);
  }
  printf("*/");
  for (i= 0; i < 256; i++) {
    if (i % entriesPerLine16 == 0) {
      printf("\n/*%4u */", i);
    }
    printf("%6u,", TableCRC8[i]);
  }
  printf("\n};\n\n");

  printf("/* CRC16 */\n");
  printf("static const _CheckSum2ByteType TableCRC16[256]= {\n/*       ");
  for (i= 0; i < entriesPerLine16; i++) {
    printf("%6u,", i);
  }
  printf("*/");
  for (i= 0; i < 256; i++) {
    if (i % entriesPerLine16 == 0) {
      printf("\n/*%4u */", i);
    }
    printf("%6u,", TableCRC16[i]);
  }
  printf("\n};\n\n");

  printf("/* CRC32 */\n");
  printf("static const _CheckSum4ByteType TableCRC32[256]= {\n/*       ");
  for (i= 0; i < entriesPerLine32; i++) {
    printf("%11u,", i);
  }
  printf("*/");
  for (i= 0; i < 256; i++) {
    if (i % entriesPerLine32 == 0) {
      printf("\n/*%4u */", i);
    }
    printf("%11u,", TableCRC32[i]);
  }
  printf("\n};\n\n");

  printf("/* CRC_CCITT */\n");
  printf("static const _CheckSum2ByteType Table_CCITT[256]= {\n/*       ");
  for (i= 0; i < entriesPerLine16; i++) {
    printf("%6u,", i);
  }
  printf("*/");
  for (i= 0; i < 256; i++) {
    if (i % entriesPerLine16 == 0) {
      printf("\n/*%4u */", i);
    }
    printf("%6u,", Table_CCITT[i]);
  }
  printf("\n};\n\n");
  return 0;
}

#endif /* ENABLE_CALCULATE_TABLES */
