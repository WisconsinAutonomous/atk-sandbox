#	This message defines a "Lane Marking"
#
#	A "Lane Marking" is defined by many characteristics, which may include marking color and marking type.

# Unique id
int32 id 0

# Lateral distance to lane markings
# Negative indicates left, positive right
int8 distance

# Lane marking type (see WA_LANE_MARKING_COLOR)
uint8 type

# Lane line color (see WA_LANE_MARKING_COLOR)
uint8 color

# Enum for lane marking types
uint8 WA_LANE_MARKING_TYPE_UNKNOWN=0
uint8 WA_LANE_MARKING_TYPE_SOLID=1
uint8 WA_LANE_MARKING_TYPE_DASHED=2
uint8 WA_LANE_MARKING_TYPE_DOTTED=3
uint8 WA_LANE_MARKING_TYPE_BOTTS_DOTS=4
uint8 WA_LANE_MARKING_TYPE_DOUBLE=5
uint8 WA_LANE_MARKING_TYPE_ROAD_EDGE=6

# Enum for lane marking colors
uint8 WA_LANE_MARKING_COLOR_UNKNOWN=0
uint8 WA_LANE_MARKING_COLOR_WHITE=1
uint8 WA_LANE_MARKING_COLOR_YELLOW=2
uint8 WA_LANE_MARKING_COLOR_OTHER=3
