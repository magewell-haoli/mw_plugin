////////////////////////////////////////////////////////////////////////////////
// CONFIDENTIAL and PROPRIETARY software of Magewell Electronics Co., Ltd.
// Copyright (c) 2011-2026 Magewell Electronics Co., Ltd. (Nanjing)
// All rights reserved.
// This copyright notice MUST be reproduced on all authorized copies.
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t mw_fourcc_t;

#ifndef MW_FOURCC
#define MW_FOURCC(ch0, ch1, ch2, ch3)									\
	((uint32_t)(uint8_t)(ch0) | ((uint32_t)(uint8_t)(ch1) << 8) |		\
	((uint32_t)(uint8_t)(ch2) << 16) | ((uint32_t)(uint8_t)(ch3) << 24))
#endif

#define MW_FOURCC_UNK		MW_FOURCC('U', 'N', 'K', 'N')

#define MW_FOURCC_BLOB		MW_FOURCC('B', 'L', 'O', 'B')
#define MW_FOURCC_JSON		MW_FOURCC('J', 'S', 'O', 'N')

// 8bits grey
#define MW_FOURCC_GREY		MW_FOURCC('G', 'R', 'E', 'Y')	// Y0, Y1, Y2, ...
#define MW_FOURCC_Y800		MW_FOURCC('Y', '8', '0', '0')	// = GREY
#define MW_FOURCC_Y8		MW_FOURCC('Y', '8', ' ', ' ')	// = GREY

// 16bits grey
#define MW_FOURCC_Y16		MW_FOURCC('Y', '1', '6', ' ')	// Y0, Y1, Y2

// RGB 15-32bits
#define MW_FOURCC_RGB15		MW_FOURCC('R', 'G', 'B', '5')	// R0, G0, B0, A0, ...
#define MW_FOURCC_RGB16		MW_FOURCC('R', 'G', 'B', '6')	// R0, G0, B0, R1, ...
#define MW_FOURCC_RGB24		MW_FOURCC('R', 'G', 'B', ' ')	// R0, G0, B0, R1, ...
#define MW_FOURCC_RGBA		MW_FOURCC('R', 'G', 'B', 'A')	// R0, G0, B0, A0, R1, ...
#define MW_FOURCC_ARGB		MW_FOURCC('A', 'R', 'G', 'B')	// A0, R0, G0, B0, A1, ...

#define MW_FOURCC_BGR15		MW_FOURCC('B', 'G', 'R', '5')	// B0, G0, R0, A0, ...
#define MW_FOURCC_BGR16		MW_FOURCC('B', 'G', 'R', '6')	// B0, G0, R0, B1, ...
#define MW_FOURCC_BGR24		MW_FOURCC('B', 'G', 'R', ' ')	// B0, G0, R0, B1, ...
#define MW_FOURCC_BGRA		MW_FOURCC('B', 'G', 'R', 'A')	// B0, G0, R0, A0, B1, ...
#define MW_FOURCC_ABGR		MW_FOURCC('A', 'B', 'G', 'R')	// A0, B0, G0, R0, A1, ...

// Planar YUV 8bits 4:2:2 (16bits)
#define MW_FOURCC_NV16		MW_FOURCC('N', 'V', '1', '6')	// Y Plane, UV Plane
#define MW_FOURCC_NV61		MW_FOURCC('N', 'V', '6', '1')	// Y Plane, VU Plane
#define MW_FOURCC_I422		MW_FOURCC('I', '4', '2', '2')	// Y Plane, U Plane, V Plane
#define MW_FOURCC_YV16		MW_FOURCC('Y', 'V', '1', '6')	// Y Plane, V Plane, U Plane

// Packed YUV 8bits 4:2:2 (16bits)
#define MW_FOURCC_YUY2		MW_FOURCC('Y', 'U', 'Y', '2')	// Y0, U01, Y1, V01, ...
#define MW_FOURCC_YUYV		MW_FOURCC('Y', 'U', 'Y', 'V')	// = YUY2
#define MW_FOURCC_UYVY		MW_FOURCC('U', 'Y', 'V', 'Y')	// U01, Y0, V01, Y1, ...

#define MW_FOURCC_YVYU		MW_FOURCC('Y', 'V', 'Y', 'U')	// Y0, V01, Y1, U01, ...
#define MW_FOURCC_VYUY		MW_FOURCC('V', 'Y', 'U', 'Y')	// V01, Y0, U01, Y1, ...

// Planar YUV 8bits 4:2:0 (12bits)
#define MW_FOURCC_I420		MW_FOURCC('I', '4', '2', '0')	// Y Plane, U Plane, V Plane
#define MW_FOURCC_IYUV		MW_FOURCC('I', 'Y', 'U', 'V')	// = I420
#define MW_FOURCC_NV12		MW_FOURCC('N', 'V', '1', '2')	// Y Plane, UV Plane

// 3 Planar YUV 10bits 4:2:0 (24bits)
#define MW_FOURCC_I010 MW_FOURCC('I', '0', '1', '0')

// 3 Planar YUV 10bits 4:2:2 (32bits)
#define MW_FOURCC_I210 MW_FOURCC('I', '2', '1', '0')

#define MW_FOURCC_YV12		MW_FOURCC('Y', 'V', '1', '2')	// Y Plane, V Plane, U Plane
#define MW_FOURCC_NV21		MW_FOURCC('N', 'V', '2', '1')	// Y Plane, VU Plane

// Planar YUV 8bits 4:4:4 (24bits)
#define MW_FOURCC_NV24		MW_FOURCC('N', 'V', '2', '4')	// Y Plane, UV Plane
#define MW_FOURCC_NV42		MW_FOURCC('N', 'V', '4', '2')	// Y Plane, VU Plane

// Planar YUV 10bits 4:2:0 (24bits)
#define MW_FOURCC_P010		MW_FOURCC('P', '0', '1', '0')	// Y Plane, UV Plane

// Planar YUV 10bits 4:2:0 (16bits) (6 * 32 / 12 bits)
// Y Plane:  [2'b00,  Y2,  Y1,  Y0], [2'b00,  Y5,  Y4,  Y3], [2'b00,  Y8,  Y7,  Y6], [2'b00,  Y11,  Y10,  Y9]
// UV Plane: [2'b00, Cb1, Cr0, Cb0], [2'b00, Cr2, Cb2, Cr1]
#define MW_FOURCC_XV15		MW_FOURCC('X', 'V', '1', '5')
/*
 * Planar YUV 10bits 4:2:0 (16bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+----
 *  | Y0₀₋₉             | Y1₀₋₉             | Y2₀₋₉             | 00
 *  +-------------------+-------------------+-------------------+----
 *  | Y3₀₋₉             | Y4₀₋₉             | Y5₀₋₉             | 00
 *  -----------------------------------------------------------------
 * UV Plane: Two lines of Y share one line of UV.
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+----
 *  | U0₀₋₉             | V0₀₋₉             | U1₀₋₉             | 00
 *  +-------------------+-------------------+-------------------+----
 *  | V1₀₋₉             | U2₀₋₉             | V2₀₋₉             | 00
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_P030 MW_FOURCC('P', '0', '3', '0') // = MW_FOURCC_XV15

// Planar YUV 10bits 4:2:2 (24bits) (4 * 32 / 6 bits)
// Y Plane:  [2'b00,  Y2,  Y1,  Y0], [2'b00,  Y5,  Y4,  Y3]
// UV Plane: [2'b00, Cb1, Cr0, Cb0], [2'b00, Cr2, Cb2, Cr1]
#define MW_FOURCC_XV20		MW_FOURCC('X', 'V', '2', '0')

/*
 * Planar YUV 10bits 4:4:4 (32bits) (3 * 32 / 3 bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+----
 *  | Y0₀₋₉             | Y1₀₋₉             | Y2₀₋₉             | 00
 *  -----------------------------------------------------------------
 * UV Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+----
 *  | U0₀₋₉             | V0₀₋₉             | U1₀₋₉             | 00
 *  +-------------------+-------------------+-------------------+----
 *  | V1₀₋₉             | U2₀₋₉             | V2₀₋₉             | 00
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_XV30 MW_FOURCC('X', 'V', '3', '0')

/*
 * Planar YUV 12bits 4:2:0 (24bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +     Byte2     +     Byte3     +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------+-----------------------+-------+-----------------------+
 *  | 0     | Y0₀₋₁₁                | 0     | Y1₀₋₁₁                |
 *  -----------------------------------------------------------------
 * UV Plane: Two lines of Y share one line of UV.
 *  +     Byte0     +     Byte1     +     Byte2     +     Byte3     +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------+-----------------------+-------+-----------------------+
 *  | 0     | U0₀₋₁₁                | 0     | V0₀₋₁₁                |
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_P012 MW_FOURCC('P', '0', '1', '2')

// Planar YUV 10bits 4:2:2 (32bits)
#define MW_FOURCC_P210 MW_FOURCC('P', '2', '1', '0') // Y Plane, UV Plane

/*
 * Planar YUV 12bits 4:2:2 (32bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +     Byte2     +     Byte3     +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------+-----------------------+-------+-----------------------+
 *  | 0     | Y0₀₋₁₁                | 0     | Y1₀₋₁₁                |
 *  -----------------------------------------------------------------
 * UV Plane:
 *  +     Byte0     +     Byte1     +     Byte2     +     Byte3     +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------+-----------------------+-------+-----------------------+
 *  | 0     | U0₀₋₁₁                | 0     | V0₀₋₁₁                |
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_P212 MW_FOURCC('P', '2', '1', '2')

// Packed YUV 10bits 4:2:2 (24bits) (4 * 32 / 6 bits)
// Width must be of 2 pixels aligned, buffer must be 48 pixels aligned (Padding zeros for non-valid pixels)
// [2'b00, Cr0, Y0, Cb0], [2'b00, Y2, Cb1, Y1], [2'b00, Cb2, Y3, Cr1], [2'b00 Y5, Cr2, Y4]
#define MW_FOURCC_V210		MW_FOURCC('v', '2', '1', '0')

// Packed YUV 10bits 4:2:2 (32bits)
#define MW_FOURCC_Y210		MW_FOURCC('Y', '2', '1', '0')

// Planar YUV 10bits 4:2:0 (15bits)
#define MW_FOURCC_MV15		MW_FOURCC('M', 'V', '1', '5')	// Y Plane, UV Plane
// Planar YUV 10bits 4:2:2 (20bits)
#define MW_FOURCC_MV20		MW_FOURCC('M', 'V', '2', '0')	// Y Plane, UV Plane
// Planar YUV 10bits 4:4:4 (30bits)
#define MW_FOURCC_MV30		MW_FOURCC('M', 'V', '3', '0')	// Y Plane, UV Plane

// Packed YUV 8bits 4:4:4 (24bits)
#define MW_FOURCC_IYU2		MW_FOURCC('I', 'Y', 'U', '2')	// U0, Y0, V0, U1, Y1, V1, ...
#define MW_FOURCC_V308		MW_FOURCC('v', '3', '0', '8')	// V0, Y0, U0, V1, Y1, U1, ...
#define MW_FOURCC_YU24		MW_FOURCC('Y', 'U', '2', '4')	// Y0, U0, V0, Y1, U1, V1, ...
/*
 * Packed YUV 8bits 4:4:4 (24bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +---------------+---------------+---------------+
 *  | Y0₀₋₇         | U0₀₋₇         | V0₀₋₇         |
 *  -------------------------------------------------
 */
#define MW_FOURCC_YUV24 MW_FOURCC('Y', 'U', 'V', ' ') // Y0, U0, V0, Y1, U1, V1, ...

// Packed YUV 8bits 4:4:4 (32bits)
#define MW_FOURCC_AYUV		MW_FOURCC('V', 'U', 'Y', 'A')	// V0, U0, Y0, A0, ...
#define MW_FOURCC_UYVA		MW_FOURCC('U', 'Y', 'V', 'A')	// U0, Y0, V0, A0, U1, Y1, ...
#define MW_FOURCC_V408		MW_FOURCC('v', '4', '0', '8')	// = MW_FOURCC_UYVA
#define MW_FOURCC_VYUA		MW_FOURCC('V', 'Y', 'U', 'A')	// V0, Y0, U0, A0, V1, Y1, ...

// Packed YUV 10bits 4:4:4 (32bits)
#define MW_FOURCC_Y410		MW_FOURCC('Y', '4', '1', '0')	// U0, Y0, V0, A0, ...
#define MW_FOURCC_V410		MW_FOURCC('v', '4', '1', '0')	// A0, U0, Y0, V0, ...
#define MW_FOURCC_MV410		MW_FOURCC('M', '4', '1', '0')	// Y0, U0, V0, A0, ...

// Packed RGB 10bits 4:4:4 (32bits)
#define MW_FOURCC_RGB10		MW_FOURCC('R', 'G', '1', '0')	// R0, G0, B0, A0, ...
/*
* Packed RGB 10bits 4:4:4 (32bits)
*
*  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
*  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
*  +-------------------+-------------------+-------------------+----
*  | B0₀₋₉             | G0₀₋₉             | R0₀₋₉             | 00
*  -----------------------------------------------------------------
*/
#define MW_FOURCC_BGR10 MW_FOURCC('B', 'G', '1', '0')  // B0, G0, R0, A0, ...
#define MW_FOURCC_R210  MW_FOURCC('r', '2', '1', '0')  // = MW_FOURCC_BGR10

#define MW_FOURCC_H264		MW_FOURCC('H', '2', '6', '4')
#define MW_FOURCC_HEVC		MW_FOURCC('H', 'E', 'V', 'C')
#define MW_FOURCC_JPEG		MW_FOURCC('J', 'P', 'E', 'G')
#define MW_FOURCC_M264		MW_FOURCC('M', '2', '6', '4')
#define MW_FOURCC_SHQ0      MW_FOURCC('S', 'H', 'Q', '0')
#define MW_FOURCC_SHQ2      MW_FOURCC('S', 'H', 'Q', '2')
#define MW_FOURCC_SHQ7      MW_FOURCC('S', 'H', 'Q', '7')
#define MW_FOURCC_WEHO		MW_FOURCC('W', 'E', 'H', 'O')
#define MW_FOURCC_MP2V		MW_FOURCC('M', 'P', '2', 'V')
#define MW_FOURCC_APRS		MW_FOURCC('A', 'P', 'R', 'S')	// Apple Prores

/*
 * RAW Format Memory Layout:
 *
 * 444 8bit RGB:  same as MW_FOURCC_BGR24
 * 444 10bit RGB: same as MW_FOURCC_BGR30
 * 444 12bit RGB: same as MW_FOURCC_BGR36
 *
 * 444 8bit YUV:  same as MW_FOURCC_IYU2
 * 444 10bit YUV: same as MW_FOURCC_MV30
 * 444 12bit YUV: same as MW_FOURCC_MV36
 *
 * 422 8bit YUV:  same as MW_FOURCC_YUYV
 * 422 10bit YUV: same as MW_FOURCC_MV20
 * 422 12bit YUV: same as MW_FOURCC_MV24
 *
 * 420 8bit YUV:
 *       +     Byte0     +     Byte1     +    Byte2      +
 *       |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *       +---------------+---------------+---------------+
 * Line0 | U0₀₋₇         | Y00₀₋₇        | Y01₀₋₇        |
 *       -------------------------------------------------
 *       +---------------+---------------+---------------+
 * Line1 | V0₀₋₇         | Y10₀₋₇        | Y11₀₋₇        |
 *       -------------------------------------------------
 *
 * 420 10bit YUV:
 *       +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *       |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *       +-------------------+-------------------+-------------------+---
 * Line0 | U0₀₋₉             | Y00₀₋₉            | Y01₀₋₉            | U1₀₋₁
 *       ----------------+-------------------+-------------------+-------
 *        U1₂₋₉          | Y02₀₋₉            | Y03₀₋₉            | U2₀₋₃
 *       ------------+-------------------+-------------------+-----------
 *        U2₄₋₉      | Y04₀₋₉            | Y05₀₋₉            | U3₀₋₅
 *       --------+-------------------+-------------------+---------------
 *        U3₆₋₉  | Y06₀₋₉            | Y07₀₋₉            |
 *       -------------------------------------------------
 *       +-------------------+-------------------+-------------------+---
 * Line1 | V0₀₋₉             | Y10₀₋₉            | Y11₀₋₉            | V1₀₋₁
 *       ----------------+-------------------+-------------------+-------
 *        V1₂₋₉          | Y12₀₋₉            | Y13₀₋₉            | V2₀₋₃
 *       ------------+-------------------+-------------------+-----------
 *        V2₄₋₉      | Y14₀₋₉            | Y15₀₋₉            | V3₀₋₅
 *       --------+-------------------+-------------------+---------------
 *        V3₆₋₉  | Y16₀₋₉            | Y17₀₋₉            |
 *       -------------------------------------------------
 *
 * 420 12bit YUV:
 *       +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *       |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *       +-----------------------+-----------------------+----------------
 * Line0 | U0₀₋₁₁                |  Y00₀₋₁₁              | Y01₀₋₇
 *       --------+-----------------------+-----------------------+--------
 *        Y01₈₋₁₁| U1₀₋₁₁                | Y02₀₋₁₁               | Y03₀₋₃
 *       ----------------+------------------------------------------------
 *        Y03₄₋₁₁        |
 *       -----------------
 *       +-----------------------+-----------------------+----------------
 * Line1 | V0₀₋₁₁                |  Y10₀₋₁₁              | Y11₀₋₇
 *       --------+-----------------------+-----------------------+--------
 *        Y11₈₋₁₁| V1₀₋₁₁                | Y12₀₋₁₁               | Y13₀₋₃
 *       ----------------+------------------------------------------------
 *        Y13₄₋₁₁        |
 *       -----------------
 *
 * DSC:
 *   RAW bitstream.
 */
#define MW_FOURCC_RAW1 MW_FOURCC('R', 'A', 'W', '1') // RAW format version 1 ...


/*
 * Planar YUV 10bits 4:2:0 (15bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | Y0₀₋₉             | Y1₀₋₉             | Y2₀₋₉             | Y3₀₋₁
 *  ----------------+-----------------------------------------------
 *   Y3₂₋₉          |
 *  -----------------
 * UV Plane: Two lines of Y share one line of UV.
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | U0₀₋₉             | V0₀₋₉             | U1₀₋₉             | V1₀₋₁
 *  ----------------+-----------------------------------------------
 *   V1₂₋₉          |
 *  -----------------
 */
#define MW_FOURCC_NV15 MW_FOURCC('N', 'V', '1', '5')
/*
 * Planar YUV 10bits 4:2:2 (20bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | Y0₀₋₉             | Y1₀₋₉             | Y2₀₋₉             | Y3₀₋₁
 *  ----------------+-----------------------------------------------
 *   Y3₂₋₉          |
 *  -----------------
 * UV Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | U0₀₋₉             | V0₀₋₉             | U1₀₋₉             | V1₀₋₁
 *  ----------------+-----------------------------------------------
 *   V1₂₋₉          |
 *  -----------------
 */
#define MW_FOURCC_NV20 MW_FOURCC('N', 'V', '2', '0')
/*
 * Planar YUV 10bits 4:4:4 (30bits)
 *
 * Y Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | Y0₀₋₉             | Y1₀₋₉             | Y2₀₋₉             | Y3₀₋₁
 *  ----------------+-----------------------------------------------
 *   Y3₂₋₉          |
 *  -----------------
 * UV Plane:
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+----
 *  | U0₀₋₉             | V0₀₋₉             | U1₀₋₉             | V1₀₋₁
 *  ----------------+-------------------+-------------------+--------
 *   V1₂₋₉          | U2₀₋₉             | V2₀₋₉             | U3₀₋₁
 *  ------------+-------------------+--------------------------------
 *   U3₂₋₉      | V3₀₋₉             |
 *  ---------------------------------
 */
#define MW_FOURCC_NV30 MW_FOURCC('N', 'V', '3', '0')
/*
 * Packed YUV 12bits 4:2:2 (24bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-----------------------+-----------------------+----------------
 *  | U0₀₋₁₁                | Y0₀₋₁₁                | V0₀₋₇
 *  --------+-----------------------+-----------------------+--------
 *   V0₈₋₁₁| Y1₀₋₁₁                 | U1₀₋₁₁                | Y2₀₋₃
 *  ----------------+-----------------------+-----------------------+
 *   Y2₄₋₁₁         | V1₀₋₁₁                | Y3₀₋₁₁                |
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_MV24 MW_FOURCC('M', 'V', '2', '4')
/*
 * Packed YUV 12bits 4:4:4 (36bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-----------------------+-----------------------+----------------
 *  | U0₀₋₁₁                |  Y0₀₋₁₁               | V0₀₋₇
 *  --------+-----------------------+-----------------------+--------
 *   V0₈₋₁₁ | U1₀₋₁₁                | Y1₀₋₁₁                | V1₀₋₃
 *  ----------------+------------------------------------------------
 *   V1₄₋₁₁         |
 *  -----------------
 */
#define MW_FOURCC_MV36 MW_FOURCC('M', 'V', '3', '6') // B0/U0, G0/Y0, R0/V0, ...

/*
 * Packed YUV 8bits 4:4:4 (32bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +---------------+---------------+---------------+---------------+
 *  | Y0₀₋₇         | U0₀₋₇         | V0₀₋₇         | A0₀₋₇         |
 *  -----------------------------------------------------------------
 */
#define MW_FOURCC_YUVA MW_FOURCC('Y', 'U', 'V', 'A') // Y0, U0, V0, A0, Y0, U0, ...

/*
 * Packed RGB 10bits 4:4:4 (30bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-------------------+-------------------+-------------------+---
 *  | B0₀₋₉             | G0₀₋₉             | R0₀₋₉             | B1₀₋₁
 *  ----------------+-------------------+-------------------+-------
 *   B1₂₋₉          | G1₀₋₉             | R1₀₋₉             | B2₀₋₃
 *  ------------+-------------------+-------------------+-----------
 *   B2₄₋₉      | G2₀₋₉             | R2₀₋₉             | B3₀₋₅
 *  --------+-------------------+-------------------+---------------
 *   B3₆₋₉  | G3₀₋₉             | R3₀₋₉             |
 *  -------------------------------------------------
 */
#define MW_FOURCC_BGR30 MW_FOURCC('B', 'G', '3', '0')

/*
 * Packed RGB 12bits 4:4:4 (36bits)
 *
 *  +     Byte0     +     Byte1     +    Byte2      +    Byte3      +
 *  |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
 *  +-----------------------+-----------------------+----------------
 *  | B0₀₋₁₁                | G0₀₋₁₁                | R0₀₋₇
 *  --------+-----------------------+-----------------------+--------
 *   R0₈₋₁₁ | B1₀₋₁₁                | G1₀₋₁₁                | R1₀₋₃
 *  ----------------+------------------------------------------------
 *   R1₄₋₁₁         |
 *  -----------------
 */
#define MW_FOURCC_BGR36 MW_FOURCC('B', 'G', '3', '6') // B0, G0, R0, ...

// Audio
// Interleaved Singed LE 16 (2bytes)
#define MW_FOURCC_IS16		MW_FOURCC('I', 'S', '1', '6')
// Interleaved Singed LE 24 (3bytes)
#define MW_FOURCC_IS24_3	MW_FOURCC('I', '2', '4', '3')
// Interleaved Singed LE 24 (4bytes)
#define MW_FOURCC_IS24		MW_FOURCC('I', 'S', '2', '4')
// Interleaved Singed LE 32 (4bytes)
#define MW_FOURCC_IS32		MW_FOURCC('I', 'S', '3', '2')
// Interleaved Float LE 32 (4bytes)
#define MW_FOURCC_IF32		MW_FOURCC('I', 'F', '3', '2')
// Interleaved Float LE 64 (8bytes)
#define MW_FOURCC_IF64		MW_FOURCC('I', 'F', '6', '4')

// Non Interleaved, the data of each channel is stored separately.
// Singed LE 16 (2bytes)
#define MW_FOURCC_S16		MW_FOURCC('S', '1', '6', ' ')
// Singed LE 24 (3bytes)
#define MW_FOURCC_S24_3		MW_FOURCC('S', '2', '4', '3')
// Singed LE 24 (4bytes)
#define MW_FOURCC_S24		MW_FOURCC('S', '2', '4', ' ')
// Singed LE 32 (4bytes)
#define MW_FOURCC_S32		MW_FOURCC('S', '3', '2', ' ')
// Float LE 32 (4bytes)
#define MW_FOURCC_F32		MW_FOURCC('F', '3', '2', ' ')
// Float LE 64 (8bytes)
#define MW_FOURCC_F64		MW_FOURCC('F', '6', '4', ' ')

// Interleaved Singed BE 16 (2bytes)
#define MW_FOURCC_IS16_BE   MW_FOURCC('i', 's', '1', '6')
// Interleaved Singed BE 24 (3bytes)
#define MW_FOURCC_IS24_3_BE MW_FOURCC('i', '2', '4', '3')
// Interleaved Singed BE 24 (4bytes)
#define MW_FOURCC_IS24_BE   MW_FOURCC('i', 's', '2', '4')
// Interleaved Singed BE 32 (4bytes)
#define MW_FOURCC_IS32_BE   MW_FOURCC('i', 's', '3', '2')
// Interleaved Float BE 32 (4bytes)
#define MW_FOURCC_IF32_BE   MW_FOURCC('i', 'f', '3', '2')
// Interleaved Float BE 64 (8bytes)
#define MW_FOURCC_IF64_BE   MW_FOURCC('i', 'f', '6', '4')

// Non Interleaved, the data of each channel is stored separately.
// Singed BE 16 (2bytes)
#define MW_FOURCC_S16_BE    MW_FOURCC('s', '1', '6', ' ')
// Singed BE 24 (3bytes)
#define MW_FOURCC_S24_3_BE  MW_FOURCC('s', '2', '4', '3')
// Singed BE 24 (4bytes)
#define MW_FOURCC_S24_BE    MW_FOURCC('s', '2', '4', ' ')
// Singed BE 32 (4bytes)
#define MW_FOURCC_S32_BE    MW_FOURCC('s', '3', '2', ' ')
// Float BE 32 (4bytes)
#define MW_FOURCC_F32_BE    MW_FOURCC('f', '3', '2', ' ')
// Float BE 64 (8bytes)
#define MW_FOURCC_F64_BE    MW_FOURCC('f', '6', '4', ' ')

#define MW_FOURCC_OPUS		MW_FOURCC('O', 'P', 'U', 'S')
#define MW_FOURCC_MP3		MW_FOURCC('.', 'M', 'P', '3')
#define MW_FOURCC_LATM		MW_FOURCC('L', 'A', 'T', 'M')
#define MW_FOURCC_G711_A    MW_FOURCC('g', '7', '1', '1')
#define MW_FOURCC_G711_U    MW_FOURCC('G', '7', '1', '1')
#define MW_FOURCC_MP4A		MW_FOURCC('M', 'P', '4', 'A')
#define MW_FOURCC_ADTS		MW_FOURCC('A', 'D', 'T', 'S')

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif
