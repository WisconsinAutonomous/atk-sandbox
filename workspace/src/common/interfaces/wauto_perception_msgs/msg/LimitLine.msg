#	This message defines a "Limit Line"
#
#	A limit line is a horizontal line that indicates a zone that a vehicle should stop. A good example
#	is a perpendicular line infront of a stop sign. 

# Unique id
int32 id 0

# Confidence
float32 confidence

# Position relative to the vehicle (ignore z)
geometry_msgs/Vector3 position

# Lane assignment
uint8 assignment

# Enum for limit line assignment
uint8 WA_LIMIT_LINE_ASSIGN_UNKNOWN=0
uint8 WA_LIMIT_LINE_ASSIGN_HOST_LANE=1
uint8 WA_LIMIT_LINE_ASSIGN_LEFT_SHOULDER=2
uint8 WA_LIMIT_LINE_ASSIGN_LEFT_LANE=3
uint8 WA_LIMIT_LINE_ASSIGN_RIGHT_LANE=4
uint8 WA_LIMIT_LINE_ASSIGN_RIGHT_SHOULDER=5
uint8 WA_LIMIT_LINE_ASSIGN_OVERHEAD=6
