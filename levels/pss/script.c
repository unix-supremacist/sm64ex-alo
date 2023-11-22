#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/pss/header.h"

const LevelScript level_pss_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0        (/*seg*/ 0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _mountain_mio0SegmentRomStart, _mountain_mio0SegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0C, _group8_geoSegmentRomStart,  _group8_geoSegmentRomEnd),
    LOAD_MIO0        (/*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW         (/*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*bhvParam*/ BPARAM4(0x01), /*bhv*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_9),

    AREA(/*index*/ 1, pss_geo_000100),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 5632, 6751, -5631, /*angle*/ 0, 270, 0, /*bhvParam*/ BPARAM2(WARP_NODE_0A), /*bhv*/ bhvAirborneWarp),
		OBJECT(/*model*/ MODEL_STAR,/*pos*/  6072, 7381, -5732, /*angle*/ 0, 0, 0,    /*behParam*/ 0x02000000, /*beh*/ bhvStar),
		OBJECT(/*model*/ MODEL_STAR,/*pos*/  358, -1169, -5030, /*angle*/ 0, 0, 0,    /*behParam*/ 0x03000000, /*beh*/ bhvStar),
		OBJECT(/*model*/ MODEL_STAR,/*pos*/  -2517, -2669, -4939, /*angle*/ 0, 0, 0,    /*behParam*/ 0x04000000, /*beh*/ bhvStar),
		OBJECT(/*model*/ MODEL_STAR,/*pos*/  -4752, -2819, -2988, /*angle*/ 0, 0, 0,    /*behParam*/ 0x05000000, /*beh*/ bhvStar),
		OBJECT(/*model*/ MODEL_NONE,/*pos*/ -5552, -4229,  4766, /*angle*/ 0, 0, 0,    /*behParam*/ 0x06000000, /*beh*/ bhvHiddenRedCoinStar),
    	OBJECT(/*model*/ MODEL_NONE,/*pos*/ -7196, -4229,  4519, /*angle*/ 0, 0, 0,    /*behParam*/ 0x07040000, /*beh*/ bhvHiddenStar),
        WARP_NODE(/*id*/ WARP_NODE_0A,         /*destLevel*/ LEVEL_PSS,    /*destArea*/ 1, /*destNode*/ WARP_NODE_0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_WARP_FLOOR, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_20, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_SUCCESS,    /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_26, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ WARP_NODE_DEATH,      /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 1, /*destNode*/ WARP_NODE_23, /*flags*/ WARP_NO_CHECKPOINT),
        TERRAIN(/*terrainData*/ pss_seg7_collision),
        MACRO_OBJECTS(/*objList*/ pss_seg7_macro_objs),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_SLIDE),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0001, /*seq*/ SEQ_LEVEL_SLIDE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 270, /*pos*/ 5632, 6451, -5631),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
