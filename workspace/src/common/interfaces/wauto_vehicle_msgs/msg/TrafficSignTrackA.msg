# ----------------------------------------------
# This is an auto generated file. DO NOT EDIT!!!
# ----------------------------------------------

# --------------------------
# TrafficSign_TrackA Message
# --------------------------

# The name of the message as defined in the DBC file.
string NAME="TrafficSign_TrackA"

# -------
# Signals
# -------

uint8 rolling_count 0 # Rolling_Count
uint8 signobjectid 0 # SignObjectID
uint8 confidence 0 # Confidence
int16 longpos 0 # LongPos
uint8 height_above_ground 0 # Height_Above_Ground
int16 latpos 0 # LatPos
uint8 sign_type 0 # Sign_Type
uint8 sign_value 0 # Sign_Value


# -----
# Enums
# -----

# Enum for Confidence signal
uint8 CONFIDENCE_3=3 # confident
uint8 CONFIDENCE_2=2 # speculative
uint8 CONFIDENCE_1=1 # highly speculative
uint8 CONFIDENCE_0=0 # invalid

# Enum for Sign_Type signal
uint8 SIGN_TYPE_0=0 # Unknown
uint8 SIGN_TYPE_1=1 # Speed Limit (MPH)
uint8 SIGN_TYPE_2=2 # Speed Limit (KPH)
uint8 SIGN_TYPE_3=3 # Stop
uint8 SIGN_TYPE_4=4 # Yield
uint8 SIGN_TYPE_5=5 # No Left Turn
uint8 SIGN_TYPE_6=6 # No Right Turn
uint8 SIGN_TYPE_7=7 # Do Not Enter
uint8 SIGN_TYPE_8=8 # Left Turn Only
uint8 SIGN_TYPE_9=9 # Right Turn Only
uint8 SIGN_TYPE_10=10 # Railroad Crossing
uint8 SIGN_TYPE_11=11 # Crosswalk
uint8 SIGN_TYPE_12=12 # No Turn On Red
uint8 SIGN_TYPE_13=13 # No U-Turn
uint8 SIGN_TYPE_14=14 # One Way (Left)
uint8 SIGN_TYPE_15=15 # One Way (Right)
uint8 SIGN_TYPE_16=16 # No Parking
uint8 SIGN_TYPE_17=17 # Handicap Parking

# ----------------------------------------------
# This is an auto generated file. DO NOT EDIT!!!
# ----------------------------------------------

