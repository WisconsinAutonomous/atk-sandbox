# ----------------------------------------------
# This is an auto generated file. DO NOT EDIT!!!
# ----------------------------------------------

# ---------------------
# Object_TrackA Message
# ---------------------

# The name of the message as defined in the DBC file.
string NAME="Object_TrackA"

# -------
# Signals
# -------

uint8 rolling_count 0 # Rolling_Count
uint8 objobjectid 0 # ObjObjectID
uint8 objobjecttype 0 # ObjObjectType
int16 longpos 0 # LongPos
int16 latpos 0 # LatPos
int16 rellongvel 0 # RelLongVel
int16 rellatvel 0 # RelLatVel
uint8 confidence 0 # Confidence
uint8 relative_lane 0 # Relative_Lane


# -----
# Enums
# -----

# Enum for ObjObjectType signal
uint8 OBJOBJECTTYPE_7=7 # Automatic Gate / Railroad
uint8 OBJOBJECTTYPE_4=4 # pedestrian
uint8 OBJOBJECTTYPE_3=3 # motocycle  / bicycle
uint8 OBJOBJECTTYPE_2=2 # Large vehicle (semi)
uint8 OBJOBJECTTYPE_1=1 # 4 Wheel Vehicle (car, small trk)
uint8 OBJOBJECTTYPE_0=0 # Unknown
uint8 OBJOBJECTTYPE_5=5 # fixed object / barricade
uint8 OBJOBJECTTYPE_6=6 # animal

# Enum for Confidence signal
uint8 CONFIDENCE_3=3 # confident
uint8 CONFIDENCE_2=2 # speculative
uint8 CONFIDENCE_1=1 # highly speculative
uint8 CONFIDENCE_0=0 # invalid

# Enum for Relative_Lane signal
uint8 RELATIVE_LANE_0=0 # Unknown
uint8 RELATIVE_LANE_1=1 # Host Lane
uint8 RELATIVE_LANE_3=3 # Left Shoulder
uint8 RELATIVE_LANE_4=4 # Left Lane
uint8 RELATIVE_LANE_5=5 # Right Lane
uint8 RELATIVE_LANE_6=6 # Right Shoulder
uint8 RELATIVE_LANE_7=7 # Overhead
uint8 RELATIVE_LANE_2=2 # Opposing Lane
uint8 RELATIVE_LANE_8=8 # Off Road
uint8 RELATIVE_LANE_9=9 # Rightbound Cross Traffic Lane
uint8 RELATIVE_LANE_10=10 # Leftbound Cross Traffic Lane

# ----------------------------------------------
# This is an auto generated file. DO NOT EDIT!!!
# ----------------------------------------------

