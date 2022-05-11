#ifndef ENGINE_MANAGER_H
#define ENGINE_MANAGER_H

// Enums
typedef enum {
	FRONT,
	RIGHT,
	BACK,
	LEFT
} Direction;

// Prototypes
void ENGINE_test(void);
void ENGINE_goForward(void);
void ENGINE_goBackward(void);
void ENGINE_stopCar(void);
void ENGINE_turn(Direction direction, uint16_t angle);

#endif /*ENGINE_MANAGER_H*/
