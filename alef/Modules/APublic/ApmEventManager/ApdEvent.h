#ifndef	_APDEVENT_H_
#define _APDEVENT_H_

#include "ApBase.h"
#include "ApMemory.h"

#include "AgpmFactors.h"

#define APDEVENT_MAX_EVENT					5
#define APDEVENT_FUNCTION_VALID(function)	((function) >= APDEVENT_FUNCTION_NONE && (function) < APDEVENT_MAX_FUNCTION)

#define APDEVENT_EID_FLAG_LOCAL				0x40000000

#define APDEVENT_TARGET_NUMBER				3

typedef enum
{
	APDEVENT_FUNCTION_NONE					= 0,
	APDEVENT_FUNCTION_SPAWN					, //1
	APDEVENT_FUNCTION_FACTOR				, //2
	APDEVENT_FUNCTION_VEHICLE				, //3
	APDEVENT_FUNCTION_SCHEDULE				, //4
	APDEVENT_FUNCTION_HIDDEN				, //5
	APDEVENT_FUNCTION_SHOP					, //6
	APDEVENT_FUNCTION_INFORMATION			, //7
	APDEVENT_FUNCTION_TELEPORT				, //8
	APDEVENT_FUNCTION_NPCTRADE				, //9
	APDEVENT_FUNCTION_CONVERSATION			, //10 
	APDEVENT_FUNCTION_NATURE				, //11
	APDEVENT_FUNCTION_STATUS				, //12
	APDEVENT_FUNCTION_ACTION				, //13
	APDEVENT_FUNCTION_SKILL					, //14
	APDEVENT_FUNCTION_SHRINE				, //15
	APDEVENT_FUNCTION_UVU_REWARD			, //16
	APDEVENT_FUNCTION_ITEM_REPAIR			, //17
	APDEVENT_FUNCTION_MASTERY_SPECIALIZE	, //18
	APDEVENT_FUNCTION_BINDING				, //19
	APDEVENT_FUNCTION_BANK					, //20
	APDEVENT_FUNCTION_NPCDAILOG				, //21
	APDEVENT_FUNCTION_ITEMCONVERT			, //22
	APDEVENT_FUNCTION_GUILD					, //23
	APDEVENT_FUNCTION_PRODUCT				, //24
	APDEVENT_FUNCTION_SKILLMASTER			, //25
	APDEVENT_FUNCTION_REFINERY				, //26
	APDEVENT_FUNCTION_QUEST					, //27
	APDEVENT_FUNCTION_AUCTION				, //28
	APDEVENT_FUNCTION_CHAR_CUSTOMIZE		, //29
	APDEVENT_FUNCTION_POINTLIGHT			, //30
	APDEVENT_FUNCTION_REMISSION				, //31
	APDEVENT_FUNCTION_WANTEDCRIMINAL		, //32
	APDEVENT_FUNCTION_SIEGEWAR_NPC			, //33
	APDEVENT_FUNCTION_TAX					, //34
	APDEVENT_FUNCTION_GUILD_WAREHOUSE		, //35
	APDEVENT_FUNCTION_ARCHLORD				, //36
	APDEVENT_FUNCTION_GAMBLE				, //37
	APDEVENT_FUNCTION_GACHA					, //38
	APDEVENT_FUNCTION_WORLD_CHAMPIONSHIP	, //39
	APDEVENT_MAX_FUNCTION
} ApdEventFunction;

typedef enum
{
	APDEVENT_AREA_SPHERE		= 0	,
	APDEVENT_AREA_FAN				,
	APDEVENT_AREA_BOX				,
	APDEVENT_MAX_AREA
} ApdEventArea;

typedef enum
{
	APDEVENT_COND_NONE			= 0x00,
	APDEVENT_COND_TARGET		= 0x01,
	APDEVENT_COND_AREA			= 0x02,
	APDEVENT_COND_ENVIRONMENT	= 0x04,
	APDEVENT_COND_TIME			= 0x08
} ApdEventCondFlag;

struct ApdEventConditionTarget : public ApMemory<ApdEventConditionTarget, 20>
{
	AgpdFactor					m_stFactor;
	//INT32						m_alItemTID[APDEVENT_TARGET_NUMBER];
	ApSafeArray<INT32, APDEVENT_TARGET_NUMBER>	m_alItemTID;
	INT32						m_lCID;

	ApdEventConditionTarget::ApdEventConditionTarget()
	{
		ZeroMemory(&m_stFactor, sizeof(m_stFactor));
		m_alItemTID.MemSetAll();
		m_lCID = 0;
	}
};

struct	ApdEventConditionEnv : public ApMemory<ApdEventConditionEnv, 20>
{
};

struct ApdEventConditionTime : public ApMemory<ApdEventConditionTime, 20>
{
	INT32						m_lActiveTimeOffset;
	INT32						m_lEndTimeOffset;

	ApdEventConditionTime::ApdEventConditionTime()
	{
		m_lActiveTimeOffset	= 0;
		m_lEndTimeOffset	= 0;
	}
};

struct ApdEventConditionArea : public ApMemory<ApdEventConditionArea, 20000>
{
	ApdEventArea				m_eType;
	union
	{
		FLOAT					m_fSphereRadius;
		struct
		{
			FLOAT				m_fRadius;
			FLOAT				m_f2BySinThetaDiv2;
		} m_stPan;
		AuBOX					m_stBox;
	} m_uoData;

	ApdEventConditionArea::ApdEventConditionArea()
	{
		m_eType	= (ApdEventArea) 0;
		ZeroMemory(&m_uoData, sizeof(m_uoData));
	}
};

struct ApdEventCondition : public ApMemory<ApdEventCondition, 20000>
{
	ApdEventConditionTarget *	m_pstTarget;
	ApdEventConditionEnv *		m_pstEnvironment;
	ApdEventConditionTime *		m_pstTime;
	ApdEventConditionArea *		m_pstArea;

	ApdEventCondition::ApdEventCondition()
	{
		m_pstTarget			= NULL;
		m_pstEnvironment	= NULL;
		m_pstTime			= NULL;
		m_pstArea			= NULL;
	}
};

typedef struct
{
	INT32				m_lEID;				// APDEVENT_EID_FLAG_LOCAL 이 Set되어 있으면, Local Generated Number이다.
											// 아니면, Sync를 위한 Unique ID이다.
	ApdEventFunction	m_eFunction;
	PVOID				m_pvData;
	ApdEventCondition *	m_pstCondition;
	ApBase *			m_pcsSource;

	UINT32				m_ulEventStartTime;

	ApMutualEx			m_Mutex;
} ApdEvent;

typedef struct
{
	UINT16				m_unFunction;
	//ApdEvent			m_astEvent[APDEVENT_MAX_EVENT];
	ApSafeArray<ApdEvent, APDEVENT_MAX_EVENT>	m_astEvent;
} ApdEventAttachData;

#endif //_APDEVENT_H_