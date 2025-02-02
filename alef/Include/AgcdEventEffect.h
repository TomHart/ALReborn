#ifndef __AGCDEVENTEFFECT_H__
#define __AGCDEVENTEFFECT_H__

#include "ApBase.h"
#include "AgcdCharacter.h"
#include "AgcaEffectSet.h"
#include "AgcdEffectData.h"
#include <list>

#define AGCD_EVENT_EFFECT_CHAR_ATTACHED_DATA_KEY_NAME	"AGCD_EVENT_EFFECT"

#define D_AGCD_EFFECT_MAX_CUST_DATA									20
#define D_AGCD_EFFECT_CUST_DATA_START								'('
#define D_AGCD_EFFECT_CUST_DATA_END									')'
#define D_AGCD_EFFECT_CUST_DATA_SEP									'|'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_ANIM_POINT					'A'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_DESTROY_MATCH					'B'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_TARGET_STRUCK_ANIM			'C'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_EXCEPTION_TYPE				'D'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_CHECK_TIME_ON					'E'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_CHECK_TIME_OFF				'F'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_TARGET_OPTION					'G'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_CALC_DIST_OPTION				'H'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_LINK_SKILL					'I'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_DIRECTION_OPTION				'J'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_EXCEPTION_TYPE_CUST_DATA		'K'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_CHECK_USER					'L'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_ACTION_OBJECT					'M'
#define D_AGCD_EFFECT_CUST_DATA_INDEX_NATURE_CONDITION				'N' //. 2005. 09. 30 Nonstopdj
#define D_AGCD_EFFECT_CUST_DATA_INDEX_CASTING_EFFECT				'O'

enum eAgcdEventEffectCustDataIndex
{
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_ANIM_POINT = 0,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_DESTROY_MATCH,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_TARGET_STRUCK_ANIM,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_EXCEPTION_TYPE,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_CHECK_TIME_ON,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_CHECK_TIME_OFF,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_TARGET_OPTION,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_CALC_DIST_OPTION,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_LINK_SKILL,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_DIRECTION_OPTION,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_EXCEPTION_TYPE_CUST_DATA,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_CHECK_USER,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_ACTION_OBJECT,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_NATURE_CONDITION,		//. 2005. 09. 30 Nonstopdj
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_CASTING_EFFECT,
	E_AGCD_EVENT_EFFECT_CUST_DATA_INDEX_NUM,
};

enum eAgcdEventEffect_CustDataIndexActionObject
{
	E_AGCD_EVENT_EFFECT_CDI_ACTION_OBJ_NONE						= 0,
	E_AGCD_EVENT_EFFECT_CDI_ACTION_OBJ_HIDE_SHIELD_WEAPONS,
	E_AGCD_EVENT_EFFECT_CDI_ACTION_OBJ_NUM
};

enum eAgcdEventEffect_CustDataIndexUserType
{
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_NONE						= 0,
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_CHAR_PC					= 1,
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_CHAR_NPC					= 2,
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_CHAR_MONSTER				= 3,
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_CHAR_GM					= 4,
	E_AGCD_EVENT_EFFECT_CDI_USER_TYPE_NUM
};

enum eAgcdEventEffect_CustDataIndexExceptionType
{
	E_AGCD_EVENT_EFFECT_CDI_EXT_TYPE_NONE						= 0,
	E_AGCD_EVENT_EFFECT_CDI_EXT_TYPE_CONTINUATIVE_SKILL_EFFECT	= 1,
	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_THIRD_ATTACK			= 2,
	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_BUFFED_ATTACK		= 3,

	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_EVASION				= 5,
	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_DAMAGE_REFLECTION	= 6,
	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_CHANGE_VELOCIY		= 7,
	E_AGCD_EVNET_EFFECT_CDI_EXT_TYPE_SKILL_ABSORB_DAMAGE		= 8,
	E_AGCD_EVENT_EFFECT_CDI_EXT_TYPE_NUM
};

enum eAgcdEventEffect_CustDataIndexDirectionOption
{
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_NONE = 0,
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_ORG_TO_TAR,
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_TAR_TO_ORG,
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_ORG_TO_TAR_HEIGHT,
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_TAR_TO_ORG_HEIGHT,
	E_AGCD_EVENT_EFFECT_CDI_DIRECTION_OPTION_NUM
};

enum eAgcdEventEffect_CustDataIndexTargetOption
{
	E_AGCD_EVENT_EFFECT_CDI_TARGET_OPTION_NONE = 0,
	E_AGCD_EVENT_EFFECT_CDI_TARGET_OPTION_ALL,
	E_AGCD_EVENT_EFFECT_CDI_TARGET_OPTION_FIRST,
	E_AGCD_EVENT_EFFECT_CDI_TARGET_OPTOIN_CHAIN,
	E_AGCD_EVENT_EFFECT_CDI_TARGET_OPTION_NUM,
};

enum eAgcdEventEffectCharacterStatus
{
	E_AGCD_EVENT_EFFECT_CHARACTER_STATUS_NONE = 0x0000,
	E_AGCD_EVENT_EFFECT_CHARACTER_STATUS_INIT = 0x0001,
};

enum eAgceEventEffectCheckTimeOnOff
{
	E_AGCD_EVENT_EFFECT_CHECK_TIME_ON	= 0,
	E_AGCD_EVENT_EFFECT_CHECK_TIME_OFF,
	E_AGCD_EVENT_EFFECT_MAX_CHECK_TIME_ON_OFF
};

enum eAgcmEventEffectCharCustomFlags
{
	E_AEE_CHAR_CUSTOM_FLAGS_NONE					= 0x0000,
	E_AEE_CHAR_CUSTOM_FLAGS_PLAY_MOVING_SOUND		= 0x0001
};

// 새로운 녀석은 밑에다가 추가하자!
enum eAgcdEventEffectConditionType
{
	AGCDEVENTEFFECT_CONDITION_NONE	= -1,
	AGCDEVENTEFFECT_CONDITION_COMMON_OP_INIT,
	AGCDEVENTEFFECT_CONDITION_OBJECT_OP_WORK,
	AGCDEVENTEFFECT_CONDITION_COMMON_CHECK_TIME,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_WAIT,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_WALK,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_RUN,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_ATTACK,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_STRUCK,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_TARGET_STRUCK,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_DEAD,
	AGCDEVENTEFFECT_CONDITION_TEMP0008,
	AGCDEVENTEFFECT_CONDITION_TEMP,						// 내부적으로 쓰인다.
	AGCDEVENTEFFECT_CONDITION_TEMP0002,
	AGCDEVENTEFFECT_CONDITION_TEMP0003,
	AGCDEVENTEFFECT_CONDITION_TEMP0004,
	AGCDEVENTEFFECT_CONDITION_TEMP0005,
	AGCDEVENTEFFECT_CONDITION_TEMP0006,
	AGCDEVENTEFFECT_CONDITION_ITEM_OP_EQUIP,
	AGCDEVENTEFFECT_CONDITION_TEMP0009,
	AGCDEVENTEFFECT_CONDITION_SKILL_OP_TARGET,
	AGCDEVENTEFFECT_CONDITION_COMMON_OP_DESTROY,
	AGCDEVENTEFFECT_CONDITION_TEMP0001,					// 여기에 추가하자~
	AGCDEVENTEFFECT_CONDITION_TEMP0007,
	AGCDEVENTEFFECT_CONDITION_ITEM_OP_USE,
	AGCDEVENTEFFECT_CONDITION_TEMP00010,
	AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_CAST,
	AGCDEVENTEFFECT_CONDITION_NUM
};

enum eAgcdEventEffectConditionFlags
{
	AGCDEVENTEFFECT_CONDITION_FLAG_NONE						= 0,
	AGCDEVENTEFFECT_CONDITION_FLAG_COMMON_OP_INIT			= 1 << AGCDEVENTEFFECT_CONDITION_COMMON_OP_INIT,
	AGCDEVENTEFFECT_CONDITION_FLAG_COMMON_CHECK_TIME		= 1 << AGCDEVENTEFFECT_CONDITION_COMMON_CHECK_TIME,
	AGCDEVENTEFFECT_CONDITION_FLAG_OBJECT_OP_WORK			= 1 << AGCDEVENTEFFECT_CONDITION_OBJECT_OP_WORK,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_WAIT		= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_WAIT,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_WALK		= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_WALK,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_RUN		= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_RUN,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_ATTACK	= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_ATTACK,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_STRUCK	= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_STRUCK,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_TARGET_STRUCK	= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_TARGET_STRUCK,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_DEAD		= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_DEAD,
	AGCDEVENTEFFECT_CONDITION_FLAG_ITEM_OP_EQUIP			= 1 << AGCDEVENTEFFECT_CONDITION_ITEM_OP_EQUIP,	
	AGCDEVENTEFFECT_CONDITION_FLAG_ITEM_OP_USE				= 1 << AGCDEVENTEFFECT_CONDITION_ITEM_OP_USE,
	AGCDEVENTEFFECT_CONDITION_FLAG_SKILL_OP_TARGET			= 1 << AGCDEVENTEFFECT_CONDITION_SKILL_OP_TARGET,
	AGCDEVENTEFFECT_CONDITION_FLAG_COMMON_OP_DESTROY		= 1 << AGCDEVENTEFFECT_CONDITION_COMMON_OP_DESTROY,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP						= 1 << AGCDEVENTEFFECT_CONDITION_TEMP, // 내부적으로 쓰인다.
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0001					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0001,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0002					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0002,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0003					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0003,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0004					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0004,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0005					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0005,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0006					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0006,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0007					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0007,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0008					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0008,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP0009					= 1 << AGCDEVENTEFFECT_CONDITION_TEMP0009,
	AGCDEVENTEFFECT_CONDITION_FLAG_TEMP00010				= 1 << AGCDEVENTEFFECT_CONDITION_TEMP00010,
	AGCDEVENTEFFECT_CONDITION_FLAG_CHARACTER_ANIM_CAST		= 1 << AGCDEVENTEFFECT_CONDITION_CHARACTER_ANIM_CAST,
	AGCDEVENTEFFECT_CONDITION_FLAG_ALL						= ((1 << AGCDEVENTEFFECT_CONDITION_NUM) - 1)
};

enum eAgcdEventEffectOptionType
{
	AGCDEVENTEFFECT_OPTION_DIRECTION = 0,
	AGCDEVENTEFFECT_OPTION_HIT_EFFECT,
	AGCDEVENTEFFECT_OPTION_ONLY_TARGET,
	AGCDEVENTEFFECT_OPTION_LOOP,
	AGCDEVENTEFFECT_OPTION_ANIM_LOOP,
	AGCDEVENTEFFECT_OPTION_FIRST_TARGET,
	AGCDEVENTEFFECT_OPTION_CALC_DISTANCE,
	AGCDEVENTEFFECT_OPTION_NUM
};

enum eAgcdEventEffectOptionFlags
{
	AGCDEVENTEFFECT_OPTION_FLAG_NONE			= 0,
	AGCDEVENTEFFECT_OPTION_FLAG_DIRECTION		= 1 << AGCDEVENTEFFECT_OPTION_DIRECTION,
	AGCDEVENTEFFECT_OPTION_FLAG_HIT_EFFECT		= 1 << AGCDEVENTEFFECT_OPTION_HIT_EFFECT,
	AGCDEVENTEFFECT_OPTION_FLAG_ONLY_TARGET		= 1 << AGCDEVENTEFFECT_OPTION_ONLY_TARGET,
	AGCDEVENTEFFECT_OPTION_FLAG_FIRST_TARGET	= 1 << AGCDEVENTEFFECT_OPTION_FIRST_TARGET,
	AGCDEVENTEFFECT_OPTION_FLAG_LOOP			= 1 << AGCDEVENTEFFECT_OPTION_LOOP,
	AGCDEVENTEFFECT_OPTION_FLAG_ANIM_LOOP		= 1 << AGCDEVENTEFFECT_OPTION_ANIM_LOOP,
	AGCDEVENTEFFECT_OPTION_FLAG_CALC_DISTANCE	= 1 << AGCDEVENTEFFECT_OPTION_CALC_DISTANCE,
	AGCDEVENTEFFECT_OPTION_FLAG_ALL				= ((1 << AGCDEVENTEFFECT_OPTION_NUM) - 1)
};

typedef enum eAgcdEventEffectType
{
	E_AGCD_EE_TYPE_NONE	= 0,
	E_AGCD_EE_TYPE_ITEM,
	E_AGCD_EE_TYPE_CHARACTER,
	E_AGCD_EE_TYPE_NUM
} eAgcdEventEffectType;

class AgcdEventEffect
{
public:
	ApBase					*m_pcsBase;
	eAgcdEventEffectType	m_eType;

	AgcdEventEffect()
	{
		m_pcsBase		= NULL;
		m_eType			= E_AGCD_EE_TYPE_NONE;
	}
};

#define AGCDEVENTEFFECT_CONVERTEDITEM_TICKOFFSET		3000
#define AGCDEVENTEFFECT_CONVERTEDITEM_BLEND_TIME		200

class AgcdConvertedItemEffect// : public AgcdEventEffect
{
public:
	INT32				m_lCurIndex;
	UINT32				m_ulPrevTick;
	UINT32				m_ulCountTick;

	VOID	InitConvertedItemEffect()
	{
		m_lCurIndex				= -1;
		m_ulPrevTick			= 0;
		m_ulCountTick			= 0;
	}

	VOID	StartConvertedItemEffect()
	{
		m_lCurIndex		= -1;
		m_ulCountTick	= AGCDEVENTEFFECT_CONVERTEDITEM_TICKOFFSET;
		m_ulPrevTick	= 0;
	}
};

class AgcdEventEffectItem : public AgcdEventEffect
{
public:
	AgcdConvertedItemEffect	m_csConvertedItemAttrEffect;		// 속성 개조이펙트
	AgcaEffectSet			m_csConvertedItemGradEffect;		// 단게 개조이펙트
};

class AgcdEventEffectCharacter : public AgcdEventEffect
{
public:
	AgcaEffectSet			m_csContinuativeSkillList;
	UINT32					m_ulStatus;
	INT32					m_lWings;

	AgcdEventEffectCharacter()
	{
		m_ulStatus = 0;
		m_lWings = 0;
	}
};

enum eAgcdEventEffectCharAnimAttachedSoundDataConditions
{
	E_AEE_CAASD_CONDITION_NONE				= 0,
	E_AEE_CAASD_CONDITION_ATTACK_SUCCESS,
	E_AEE_CAASD_CONDITION_ATTACK_MISS,
	E_AEE_CAASD_MAX_CONDITION
};

class AEE_CharAnimAttachedSoundData
{
public:
	std::string		m_strSoundName;
	UINT8			m_unConditions;

	AEE_CharAnimAttachedSoundData():m_unConditions(0) {}
	AEE_CharAnimAttachedSoundData( const char * pStr , UINT8 uCondition = 0 ):m_strSoundName( pStr ),m_unConditions(uCondition) {}
};

class AEE_SoundIndexList
{
public:
	UINT32				m_ulIndex;
	AEE_SoundIndexList	*m_pcsNext;

	AEE_SoundIndexList()
	{
		m_ulIndex	= 0;
		m_pcsNext	= NULL;
	}
};

class AEE_CharAnimAttachedData
{
public:
	typedef	std::list< AEE_CharAnimAttachedSoundData >	SoundList;
	typedef SoundList::iterator							SoundListItr;

public:
	AEE_CharAnimAttachedData()	{	}	// 생성자 호출되지 못함.

	SoundList&	GetList()	{	if( m_plistSoundData ) return *m_plistSoundData; else return *( m_plistSoundData = new SoundList ); }
	void		Release()	{	if( m_plistSoundData ) delete m_plistSoundData; m_plistSoundData = NULL; }
	AEE_CharAnimAttachedSoundData*	GetHead(){ if( GetList().empty() ) return NULL; return &*GetList().begin(); }
	AEE_CharAnimAttachedSoundData*	GetTail(){ if( GetList().empty() ) return NULL; return &*GetList().rbegin(); }

protected:
	SoundList*		m_plistSoundData;
};

class AgcdEventEffectCheckTimeData
{
public:
	AgcdEventEffectCheckTimeData		*m_pcsNext;
	EFFCTRL_SET							*m_pcsEffectSetNode;
	AgcdUseEffectSetData				m_csData;

	AgcdEventEffectCheckTimeData()
	{
		m_pcsEffectSetNode	= NULL;
		m_pcsNext			= NULL;
	}
};

class AgcdEventEffectCheckTimeDataList
{
public:
	AgcdEventEffectCheckTimeDataList	*m_pcsNext;
	ApBase								*m_pcsKey;
	AgcdEventEffectCheckTimeData		*m_pcsData;

	AgcdEventEffectCheckTimeDataList()
	{
		m_pcsNext	= NULL;
		m_pcsKey	= NULL;
		m_pcsData	= NULL;
	}
};

#endif // __AGCDUSEEFFECTSET_H__