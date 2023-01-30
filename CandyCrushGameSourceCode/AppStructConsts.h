#pragma once

#define FRAME_MENU                 100
#define FRAME_GAME_DISPLAY         101
#define FRAME_SETTINGS             102
#define FRAME_SAVE_GAME            103
#define FRAME_HOW_TO_PLAY          104
#define FRAME_GAME_MODE            105
#define FRAME_RESUME_GAME          106
#define FRAME_LOAD_GAME            107
#define FRAME_HEIGHST_SCORE        108
#define FRAME_CONGRATULATIONS      109

#define SHAPE_CIRCLE                   1
#define SHAPE_SQUARE                   2
#define SHAPE_YELLOW_BOX               3
#define SHAPE_ROUND_RECTANGLE          4
#define SHAPE_PILLAR                   5

#define CIRCLE_RADIUS                  15

#define SQUARE_SIZE                    30

#define YELLOW_BOX_SIZE                30

#define RECTANGLE_HEIGHT               40
#define RECTANGLE_WIDTH                20
#define RECTANGLE_ROUND_ANGLE          10

#define PILLAR_HEIGHT                   15
#define PILLAR_WIDTH                    30
#define PILLAR_ROUND_ANGLE              30

#define TOTAL_GRID_CELLS                36
#define INITIAL_POPULATED_GRID_CELLS    36


#define CIRCLE_COLOR                  MEDIUM_PURPLE

#define SQUARE_COLOR                  MEDIUM_TURQUOISE

#define RECTANGLE_COLOR               DARK_ORCHID

#define PILLAR_COLOR                  SEA_GREEN

#define TRIANGLE_COLOR                SIENNA

#define GRID_COLOR                     GREEN 

#define YELLOW_BOX_COLOR               YELLOW


#define GRID_OFFSET_X                   300            
#define GRID_OFFSET_Y                   350

#define GRID_NUMBER_OF_ROWS                   6            
#define GRID_NUMBER_OF_COLOMNS                6

#define GRID_CELL_SIZE                  50

typedef struct Coordinates
{
     int x;
     int y;
};


#define TRIANGLE_OFFSET_X1              5
#define TRIANGLE_OFFSET_Y1              5
#define TRIANGLE_OFFSET_X2              45 
#define TRIANGLE_OFFSET_Y2              5
#define TRIANGLE_OFFSET_X3              25
#define TRIANGLE_OFFSET_Y3              45

#define CIRCLE_OFFSET_X              25
#define CIRCLE_OFFSET_Y              25

#define ROUND_RECTANGLE_OFFSET_X               5
#define ROUND_RECTANGLE_OFFSET_Y              15

#define SQUARE_OFFSET_X              10
#define SQUARE_OFFSET_Y              10

#define PILLAR_OFFSET_X              20
#define PILLAR_OFFSET_Y              10

#define YELLOW_BOX_OFFSET_X                  10
#define YELLOW_BOX_OFFSET_Y                  10


#define GRID_PADING                  10

#define MAXIMUM_GROUPED_CELLS           6