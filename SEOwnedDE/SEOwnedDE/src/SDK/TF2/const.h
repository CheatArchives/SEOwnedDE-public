#pragma once

#pragma warning (disable : 26812)

#define MAX_PLAYERS 33

#define STEAM_PARM "-steam"
#define AUTO_RESTART "-autoupdate"
#define INVALID_STEAM_TICKET "Invalid STEAM UserID Ticket\n"
#define INVALID_STEAM_VACBANSTATE "VAC banned from secure server\n"
#define INVALID_STEAM_LOGGED_IN_ELSEWHERE "This Steam account is being used in another location\n"
#define INVALID_STEAM_LOGON_NOT_CONNECTED "Client not connected to Steam\n"
#define INVALID_STEAM_LOGON_TICKET_CANCELED "Client left game (Steam auth ticket has been canceled)\n"
#define CLIENTNAME_TIMED_OUT "%s timed out"

#define DEFAULT_TICK_INTERVAL (0.015)
#define MINIMUM_TICK_INTERVAL (0.001)
#define MAXIMUM_TICK_INTERVAL (0.1)
#define ABSOLUTE_PLAYER_LIMIT 255
#define ABSOLUTE_PLAYER_LIMIT_DW ((ABSOLUTE_PLAYER_LIMIT/32) + 1)
#define MAX_PLAYER_NAME_LENGTH 32
#define MAX_PLAYERS_PER_CLIENT 1
#define MAX_MAP_NAME 96
#define MAX_MAP_NAME_SAVE 32
#define MAX_DISPLAY_MAP_NAME 32
#define	MAX_NETWORKID_LENGTH 64
#define SP_MODEL_INDEX_BITS 13
#define	MAX_EDICT_BITS 11
#define	MAX_EDICTS (1<<MAX_EDICT_BITS)
#define MAX_SERVER_CLASS_BITS 9
#define MAX_SERVER_CLASSES (1<<MAX_SERVER_CLASS_BITS)
#define SIGNED_GUID_LEN 32
#define NUM_ENT_ENTRY_BITS (MAX_EDICT_BITS + 1)
#define NUM_ENT_ENTRIES (1 << NUM_ENT_ENTRY_BITS)
#define ENT_ENTRY_MASK (NUM_ENT_ENTRIES - 1)
#define INVALID_EHANDLE_INDEX 0xFFFFFFFF
#define NUM_SERIAL_NUM_BITS (32 - NUM_ENT_ENTRY_BITS)
#define NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS 10
#define NUM_NETWORKED_EHANDLE_BITS (MAX_EDICT_BITS + NUM_NETWORKED_EHANDLE_SERIAL_NUMBER_BITS)
#define INVALID_NETWORKED_EHANDLE_VALUE ((1 << NUM_NETWORKED_EHANDLE_BITS) - 1)
#define MAX_PACKEDENTITY_DATA (16384)
#define MAX_PACKEDENTITY_PROPS (4096)
#define MAX_CUSTOM_FILES 4
#define MAX_CUSTOM_FILE_SIZE 524288

#define	FL_ONGROUND (1<<0)
#define FL_DUCKING (1<<1)
#define	FL_WATERJUMP (1<<2)
#define FL_ONTRAIN (1<<3)
#define FL_INRAIN (1<<4)
#define FL_FROZEN (1<<5)
#define FL_ATCONTROLS (1<<6)
#define	FL_CLIENT (1<<7)
#define FL_FAKECLIENT (1<<8)
#define	FL_INWATER (1<<9)
#define PLAYER_FLAG_BITS 10

enum MoveType_t
{
	MOVETYPE_NONE = 0,
	MOVETYPE_ISOMETRIC,
	MOVETYPE_WALK,
	MOVETYPE_STEP,
	MOVETYPE_FLY,
	MOVETYPE_FLYGRAVITY,
	MOVETYPE_VPHYSICS,
	MOVETYPE_PUSH,
	MOVETYPE_NOCLIP,
	MOVETYPE_LADDER,
	MOVETYPE_OBSERVER,
	MOVETYPE_CUSTOM,
	MOVETYPE_LAST = MOVETYPE_CUSTOM,
	MOVETYPE_MAX_BITS = 4
};

enum MoveCollide_t
{
	MOVECOLLIDE_DEFAULT = 0,
	MOVECOLLIDE_FLY_BOUNCE,
	MOVECOLLIDE_FLY_CUSTOM,
	MOVECOLLIDE_FLY_SLIDE,
	MOVECOLLIDE_COUNT,
	MOVECOLLIDE_MAX_BITS = 3
};

enum SolidType_t
{
	SOLID_NONE = 0,
	SOLID_BSP = 1,
	SOLID_BBOX = 2,
	SOLID_OBB = 3,
	SOLID_OBB_YAW = 4,
	SOLID_CUSTOM = 5,
	SOLID_VPHYSICS = 6,
	SOLID_LAST
};

enum SolidFlags_t
{
	FSOLID_CUSTOMRAYTEST = 0x0001,
	FSOLID_CUSTOMBOXTEST = 0x0002,
	FSOLID_NOT_SOLID = 0x0004,
	FSOLID_TRIGGER = 0x0008,
	FSOLID_NOT_STANDABLE = 0x0010,
	FSOLID_VOLUME_CONTENTS = 0x0020,
	FSOLID_FORCE_WORLD_ALIGNED = 0x0040,
	FSOLID_USE_TRIGGER_BOUNDS = 0x0080,
	FSOLID_ROOT_PARENT_ALIGNED = 0x0100,
	FSOLID_TRIGGER_TOUCH_DEBRIS = 0x0200,
	FSOLID_MAX_BITS = 10
};

inline bool IsSolid(SolidType_t solidType, int nSolidFlags)
{
	return (solidType != SOLID_NONE) && ((nSolidFlags & FSOLID_NOT_SOLID) == 0);
}

#define	LIFE_ALIVE 0
#define	LIFE_DYING 1
#define	LIFE_DEAD 2
#define LIFE_RESPAWNABLE 3
#define LIFE_DISCARDBODY 4

enum
{
	EF_BONEMERGE = 0x001,
	EF_BRIGHTLIGHT = 0x002,
	EF_DIMLIGHT = 0x004,
	EF_NOINTERP = 0x008,
	EF_NOSHADOW = 0x010,
	EF_NODRAW = 0x020,
	EF_NORECEIVESHADOW = 0x040,
	EF_BONEMERGE_FASTCULL = 0x080,
	EF_ITEM_BLINK = 0x100,
	EF_PARENT_ANIMATES = 0x200,
	EF_MAX_BITS = 10
};

#define EF_PARITY_BITS 3
#define EF_PARITY_MASK ((1<<EF_PARITY_BITS)-1)
#define EF_MUZZLEFLASH_BITS 2
#define	PLAT_LOW_TRIGGER 1
#define	SF_TRAIN_WAIT_RETRIGGER	1
#define SF_TRAIN_PASSABLE 8
#define FIXANGLE_NONE 0
#define FIXANGLE_ABSOLUTE 1
#define FIXANGLE_RELATIVE 2
#define BREAK_GLASS 0x01
#define BREAK_METAL 0x02
#define BREAK_FLESH 0x04
#define BREAK_WOOD 0x08
#define BREAK_SMOKE 0x10
#define BREAK_TRANS 0x20
#define BREAK_CONCRETE 0x40
#define BREAK_SLAVE 0x80
#define BOUNCE_GLASS BREAK_GLASS
#define	BOUNCE_METAL BREAK_METAL
#define BOUNCE_FLESH BREAK_FLESH
#define BOUNCE_WOOD	 BREAK_WOOD
#define BOUNCE_SHRAP 0x10
#define BOUNCE_SHELL 0x20
#define	BOUNCE_CONCRETE BREAK_CONCRETE
#define BOUNCE_SHOTSHELL 0x80
#define TE_BOUNCE_NULL 0
#define TE_BOUNCE_SHELL 1
#define TE_BOUNCE_SHOTSHELL	2

enum RenderMode_t
{
	kRenderNormal = 0,
	kRenderTransColor,
	kRenderTransTexture,
	kRenderGlow,
	kRenderTransAlpha,
	kRenderTransAdd,
	kRenderEnvironmental,
	kRenderTransAddFrameBlend,
	kRenderTransAlphaAdd,
	kRenderWorldGlow,
	kRenderNone,
	kRenderModeCount
};

enum RenderFx_t
{
	kRenderFxNone = 0,
	kRenderFxPulseSlow,
	kRenderFxPulseFast,
	kRenderFxPulseSlowWide,
	kRenderFxPulseFastWide,
	kRenderFxFadeSlow,
	kRenderFxFadeFast,
	kRenderFxSolidSlow,
	kRenderFxSolidFast,
	kRenderFxStrobeSlow,
	kRenderFxStrobeFast,
	kRenderFxStrobeFaster,
	kRenderFxFlickerSlow,
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,
	kRenderFxHologram,
	kRenderFxExplode,
	kRenderFxGlowShell,
	kRenderFxClampMinScale,
	kRenderFxEnvRain,
	kRenderFxEnvSnow,
	kRenderFxSpotlight,
	kRenderFxRagdoll,
	kRenderFxPulseFastWider,
	kRenderFxMax
};

enum Collision_Group_t
{
	COLLISION_GROUP_NONE = 0,
	COLLISION_GROUP_DEBRIS,
	COLLISION_GROUP_DEBRIS_TRIGGER,
	COLLISION_GROUP_INTERACTIVE_DEBRIS,
	COLLISION_GROUP_INTERACTIVE,
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_BREAKABLE_GLASS,
	COLLISION_GROUP_VEHICLE,
	COLLISION_GROUP_PLAYER_MOVEMENT,
	COLLISION_GROUP_NPC,
	COLLISION_GROUP_IN_VEHICLE,
	COLLISION_GROUP_WEAPON,
	COLLISION_GROUP_VEHICLE_CLIP,
	COLLISION_GROUP_PROJECTILE,
	COLLISION_GROUP_DOOR_BLOCKER,
	COLLISION_GROUP_PASSABLE_DOOR,
	COLLISION_GROUP_DISSOLVING,
	COLLISION_GROUP_PUSHAWAY,
	COLLISION_GROUP_NPC_ACTOR,
	COLLISION_GROUP_NPC_SCRIPTED,
	LAST_SHARED_COLLISION_GROUP
};

#define SOUND_NORMAL_CLIP_DIST	1000.0f
#define MAX_AREA_STATE_BYTES 32
#define MAX_AREA_PORTAL_STATE_BYTES 24
#define MAX_USER_MSG_DATA 255
#define MAX_ENTITY_MSG_DATA 255

#include "basetypes.h"

class CThreadMutex;
typedef CThreadMutex CSourceMutex;

#define STUDIO_NONE 0x00000000
#define STUDIO_RENDER 0x00000001
#define STUDIO_VIEWXFORMATTACHMENTS 0x00000002
#define STUDIO_DRAWTRANSLUCENTSUBMODELS 0x00000004
#define STUDIO_TWOPASS 0x00000008
#define STUDIO_STATIC_LIGHTING 0x00000010
#define STUDIO_WIREFRAME 0x00000020
#define STUDIO_ITEM_BLINK 0x00000040
#define STUDIO_NOSHADOWS 0x00000080
#define STUDIO_WIREFRAME_VCOLLIDE 0x00000100
#define STUDIO_NO_OVERRIDE_FOR_ATTACH 0x00000200
#define STUDIO_GENERATE_STATS 0x01000000
#define STUDIO_SSAODEPTHTEXTURE 0x08000000
#define STUDIO_SHADOWDEPTHTEXTURE 0x40000000
#define STUDIO_TRANSPARENCY 0x80000000

enum ETFHitboxes
{
	HITBOX_HEAD,
	HITBOX_NECK,
	HITBOX_LOWER_NECK,
	HITBOX_PELVIS,
	HITBOX_BODY,
	HITBOX_THORAX,
	HITBOX_CHEST,
	HITBOX_UPPER_CHEST,
	HITBOX_RIGHT_THIGH,
	HITBOX_LEFT_THIGH,
	HITBOX_RIGHT_CALF,
	HITBOX_LEFT_CALF,
	HITBOX_RIGHT_FOOT,
	HITBOX_LEFT_FOOT,
	HITBOX_RIGHT_HAND,
	HITBOX_LEFT_HAND,
	HITBOX_RIGHT_UPPER_ARM,
	HITBOX_RIGHT_FOREARM,
	HITBOX_LEFT_UPPER_ARM,
	HITBOX_LEFT_FOREARM,
	HITBOX_MAX
};

enum MinigunState_t
{
	AC_STATE_IDLE = 0,
	AC_STATE_STARTFIRING,
	AC_STATE_FIRING,
	AC_STATE_SPINNING,
	AC_STATE_DRYFIRE
};

enum minigun_weapontypes_t
{
	MINIGUN_STANDARD = 0,
	MINIGUN_STUN
};

typedef enum
{
	GROUND = 0,
	STUCK,
	LADDER
} IntervalType_t;

enum
{
	SPEED_CROPPED_RESET = 0,
	SPEED_CROPPED_DUCK = 1,
	SPEED_CROPPED_WEAPON = 2
};

#define MAX_NEW_COMMANDS 15
#define MAX_BACKUP_COMMANDS	7
#define MAX_COMMANDS MAX_NEW_COMMANDS + MAX_BACKUP_COMMANDS

typedef enum
{
	PREDICTION_SIMULATION_RESULTS_ARRIVING_ON_SEND_FRAME = 0,
	PREDICTION_NORMAL
} PREDICTION_REASON;

enum view_id_t
{
	VIEW_ILLEGAL = -2,
	VIEW_NONE = -1,
	VIEW_MAIN = 0,
	VIEW_3DSKY = 1,
	VIEW_MONITOR = 2,
	VIEW_REFLECTION = 3,
	VIEW_REFRACTION = 4,
	VIEW_INTRO_PLAYER = 5,
	VIEW_INTRO_CAMERA = 6,
	VIEW_SHADOW_DEPTH_TEXTURE = 7,
	VIEW_SSAO = 8,
	VIEW_ID_COUNT
};

enum medigun_weapontypes_t
{
	MEDIGUN_STANDARD = 0,
	MEDIGUN_UBER,
	MEDIGUN_QUICKFIX,
	MEDIGUN_RESIST
};

enum medigun_resist_types_t
{
	MEDIGUN_BULLET_RESIST = 0,
	MEDIGUN_BLAST_RESIST,
	MEDIGUN_FIRE_RESIST,
	MEDIGUN_NUM_RESISTS
};

enum PrecipitationType_t
{
	PRECIPITATION_TYPE_RAIN = 0,
	PRECIPITATION_TYPE_SNOW,
	PRECIPITATION_TYPE_ASH,
	PRECIPITATION_TYPE_SNOWFALL,
	NUM_PRECIPITATION_TYPES
};