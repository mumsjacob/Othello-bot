#ifndef MOVE_PLANNER_H
#define MOVE_PLANNER_H

#include "config.hpp"
#include "game.hpp"

#include <Stepper.h>
#include <Servo.h>

class MovePlanner {
    public:
        MovePlanner();

        void setup(void);
        void write(void);
        void addMove(Coordinate c, Player p); 
        bool isDone(void);

    private:
        Stepper xMotor = Stepper(CONF_STEPPER_STEPS, CONF_X_STEPPER_PINS);
        Stepper yMotor = Stepper(CONF_STEPPER_STEPS, CONF_Y_STEPPER_PINS);
        Servo zMotor = Servo();

        enum Action {MOVE_TO_TARGET, LOWER_ARM, RAISE_ARM, PICK_PIECE, DROP_PIECE};
        enum Action actQueue[CONF_PLANNER_QUEUE_SZ];
        int actQueueSize = 0;
        int currentActionId;
        enum Magnet {NEGATIVE, POSITIVE};
        int targetX;
        int targetY;
        enum Magnet targetPolarity;
        enum Magnet currentPolarity;
        int currentX;
        int currentY;

        void reset(void);
};

#endif // MOVE_PLANNER_H
