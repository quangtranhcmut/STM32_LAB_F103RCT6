/*
 * scheduler.h
 *
 *  Created on: Nov 28, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "sched.h"
#include "main.h"

typedef struct{
	void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint8_t RunMe;
}sTask;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
unsigned char SCH_Delete_Task(const uint32_t TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
