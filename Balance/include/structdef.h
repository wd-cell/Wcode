#ifndef _STRUCT_DEF_
#define _STRUCT_DEF_

#include <string>
#include "hncparamandef.h"
#include "eventdef.h"
#include "hncverifydef.h"
#include "decoderdef.h"
using namespace std;

typedef struct _SParmProperty
{
	Bit32 id;
	Bit32 access;
	Bit32 actType;
	Bit32 storeType;
	Bit8 name[DATA_STRING_LEN];
	Bit8 defaltVal[DATA_STRING_LEN];
	Bit8 minVal[DATA_STRING_LEN];
	Bit8 maxVal[DATA_STRING_LEN];
	Bit8 value[DATA_STRING_LEN];
}SParmProperty;

typedef struct _NCChannel
{
	Bit8 name[8];
	Bit32 macType;
	Bit32 axesMask;
	Bit32 axesMask1;
	Bit32 cmdType;
	fBit64 cmdFeedRate;
	fBit64 actFeedRate;
	fBit64 progFeedRate;
	Bit32 feedOverride;
	Bit32 rapidOverride;
	Bit32 mCode;
	Bit32 tCode;
	Bit32 tOffs;
	Bit32 toolUse;
	Bit32 toolRdy;
	Bit32 chanMode;
	Bit32 isMdi;
	Bit32 isCycle;
	Bit32 isHold;
	Bit32 isProgSel;
	Bit32 isProgEnd;
	Bit32 isThreading;
	Bit32 isRigid;
	Bit32 isRewinded;
	Bit32 isEstop;
	Bit32 isReseting;
	Bit32 isRunning;
	Bit32 isHoming;
	Bit32 isMoving;
	Bit32 diameter;
	Bit32 isVerify;
	Bit32 runRow;
	Bit32 dcdRow;
	Bit32 selProg;
	Bit32 runProg;
	Bit32 partCntr;
	Bit32 partTotalNum;
	Bit32 hOff;
	Bit32 dOff;
	Bit8 progName[64];
	Bit32 chanLax[CHAN_AXES_NUM];
	Bit8 chanAxisName[CHAN_AXES_NUM][8];
	Bit8 chanSpdlName[CHAN_SPDL_NUM][8];
	Bit32 chanModal[MAX_GGRP_NUM];
	Bit32 chanSpdlLax[CHAN_SPDL_NUM];
	Bit32 chanSpdlParaLax[CHAN_SPDL_NUM];
	fBit64 cmdSpdlSpeed[CHAN_SPDL_NUM];
	fBit64 actSpdlSpeed[CHAN_SPDL_NUM];
	Bit32 spdlOverride[CHAN_SPDL_NUM];
	fBit64 bpPos[CHAN_AXES_NUM];
}NCChannel;

typedef struct _NCAxis
{
	Bit8 name[8];
	Bit8 svVer[32]; //AXIS_DATA_LEN = 32
	Bit8 svType[32]; //AXIS_DATA_LEN = 32
	Bit32 type;
	Bit32 chanNo;
	Bit32 chAxisNo;
	Bit32 leadAxisNo;
	Bit32 actPulse;
	Bit32 cmdPulse;
	Bit32 encCntr;
	Bit32 isHomed;
	Bit32 zSpace1;
	Bit32 zSpace2;
	fBit64 actPos;
	fBit64 cmdPos;
	fBit64 actWcsPos;
	fBit64 cmdWcsPos;
	fBit64 actRcsPos;
	fBit64 cmdRcsPos;
	fBit64 progPos;
	fBit64 cmdVel;
	fBit64 actVel;
	fBit64 leftToGo;
	fBit64 wcsZero;
	fBit64 wheelOff;
	fBit64 followErr;
	fBit64 synErr;
	fBit64 compVal;
	fBit64 zDist;
	fBit64 relZero;
	fBit64 motorRev;
	fBit64 loadCurrent;
	fBit64 ratedCurrent;
	fBit64 waveFreq;
}NCAxis;

#endif