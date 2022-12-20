# This message defines an object classification

# Value between 0 and 1 defining the percent confidence of the detection
float32 confidence

# The classification types
# See WA_OBJECT_CLASSIFICATION below
uint8 classification

# The Dynamic Property types
# See WA_DYNPROP_CLASSIFICATION below
uint8 dynprop

# Further custom classification types to be used to further define an object
# 	Example use case is a traffic light, which can be defined as green, red, etc.
# 	This variable should then be set to a different enum, as desired
uint8 custom_classification 

# Additional optional attribute that can be defined to show an objects "value"
# A good example is the value of a speed limit sign
uint8 value 0

# The possible classification types
uint8 WA_OBJECT_CLASSIFICATION_UNKNOWN=0
uint8 WA_OBJECT_CLASSIFICATION_CAR=1
uint8 WA_OBJECT_CLASSIFICATION_PEDESTRIAN=2
uint8 WA_OBJECT_CLASSIFICATION_DEER=3
uint8 WA_OBJECT_CLASSIFICATION_BARRICADE=4
uint8 WA_OBJECT_CLASSIFICATION_TRAFFIC_LIGHT=5
uint8 WA_OBJECT_CLASSIFICATION_TRAFFIC_SIGN=6
uint8 WA_OBJECT_CLASSIFICATION_BARREL=7

# Additional classification for traffic light signals
# Bit flags
uint8 WA_TRAFFIC_LIGHT_STATE_UNKNOWN=0
uint8 WA_TRAFFIC_LIGHT_STATE_RED=1
uint8 WA_TRAFFIC_LIGHT_STATE_YELLOW=2
uint8 WA_TRAFFIC_LIGHT_STATE_GREEN=4
uint8 WA_TRAFFIC_LIGHT_STATE_CIRCLE=8
uint8 WA_TRAFFIC_LIGHT_STATE_LEFT_ARROW=16
uint8 WA_TRAFFIC_LIGHT_STATE_RIGHT_ARROW=32
uint8 WA_TRAFFIC_LIGHT_STATE_FLASHING=64
# Additional classification for traffic signs
uint8 WA_TRAFFIC_SIGN_UNKNOWN=0
uint8 WA_TRAFFIC_SIGN_SPEED_LIMIT=1
uint8 WA_TRAFFIC_SIGN_STOP=2
uint8 WA_TRAFFIC_SIGN_YIELD=3

# Dynamic Property ENUM
uint8 WA_DYNPROP_UNKNOWN=0
uint8 WA_DYNPROP_NEVER=1
uint8 WA_DYNPROP_STOPPED=2
uint8 WA_DYNPROP_MOVING_SAME=3
uint8 WA_DYNPROP_MOVING_OPPOSITE=4
