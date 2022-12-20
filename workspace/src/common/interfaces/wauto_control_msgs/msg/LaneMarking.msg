# Msg type for a road lane marking
# Refer to: https://www.mathworks.com/help/driving/ref/scenarioreader.html#mw_31c3add8-5453-4f95-a37e-b6923ce62508

# BoundaryType
uint8 UNMARKED=0
uint8 SOLID=1
uint8 DASHED=2
uint8 DOUBLESOLID=3
uint8 DOUBLEDASHED=4
uint8 SOLIDDASHED=5
uint8 DASHEDSOLID=6

# Msg fields
uint8 boundary_type
float64 lateral_offset
float64 heading_angle # rad
float64[20] coordinates_x
float64[20] coordinates_y
