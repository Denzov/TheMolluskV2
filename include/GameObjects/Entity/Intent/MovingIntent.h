#ifndef _MOVING_ENTITY_INTENT_H_
#define _MOVING_ENTITY_INTENT_H_

struct MovingIntent{
    struct MoveNorth { bool status = 0; } move_north;
    struct MoveEast  { bool status = 0; } move_east;
    struct MoveWest  { bool status = 0; } move_west;
    struct MoveSouth { bool status = 0; } move_south;    
};

#endif // !_MOVING_ENTITY_INTENT_H_