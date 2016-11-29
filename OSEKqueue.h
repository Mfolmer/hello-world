#ifndef OSEKQUEUE_H //include guard
#define OSEKQUEUE_H //include guard

#define QUEUE_SIZE 10

//error codes
#define EMPTYQUEUE_ERROR 400; 
#define WRONGINPUT_ERROR 401; 

//piston commands
typedef enum {push = 1, skip = 2} commands;

typedef enum {false, true} bool;
bool empty = true;

//Queues...
//Queues only contains 1s and 2s, 1 indicating a push, 2 a skip.
int IR1_queue[QUEUE_SIZE];
int IR1_queue_head = 0; //Represents at which index next 'enqueue' call should manipulate the queue i.e where next elements should be placed.
int IR1_queue_tail = 0; //Represents at which index next 'dequeue' call should manipulate the queue i.e which elements should be "removed".

int IR2_queue[QUEUE_SIZE];
int IR2_queue_head = 0; 
int IR2_queue_tail = 0;

int IR3_queue[QUEUE_SIZE];
int IR3_queue_head = 0;
int IR3_queue_tail = 0;
//Queues...


void enqueue(int queue_ID) //Formal parameters 'queue_ID' indicates which queue to manipulate
{

 		switch(queue_ID){
 			case 1:
 				IR1_queue[IR1_queue_head] = push;
 				IR1_queue_head == QUEUE_SIZE - 1 ? IR1_queue_head = 0 : IR1_queue_head++; //set head to 0 if end of queue is reached, else increments head			
 				empty = false;
 				break;

 			case 2:
 			 	IR1_queue[IR1_queue_head] = skip;
 				IR2_queue[IR2_queue_head] = push;

 			    IR1_queue_head == QUEUE_SIZE - 1 ? IR1_queue_head = 0 : IR1_queue_head++;
 			    IR2_queue_head == QUEUE_SIZE - 1 ? IR2_queue_head = 0 : IR2_queue_head++;
 				empty = false;
 				break;

 			case 3:
 			 	IR1_queue[IR1_queue_head] = skip;
 			 	IR2_queue[IR2_queue_head] = skip;
 			 	IR3_queue[IR3_queue_head] = push;

 				IR1_queue_head == QUEUE_SIZE - 1 ? IR1_queue_head = 0 : IR1_queue_head++;
 			    IR2_queue_head == QUEUE_SIZE - 1 ? IR2_queue_head = 0 : IR2_queue_head++;
 			    IR3_queue_head == QUEUE_SIZE - 1 ? IR3_queue_head = 0 : IR3_queue_head++;
 				empty = false;
 			    break;

 			default:
				break;
 				//Wrong input! Take corrective actions!
 		}
}

int dequeue(int queue_ID) //Formal parameters 'queue_ID' indicates which queue to manipulate. Function only returns 1(push)  or 2(skip).
{
	if(!empty)//ensures that no queue can be dequeue prior to a enqueue. Should possibly be for each queue?
	{
		int retValue; //return value of function
		switch(queue_ID){
			case 1:
				retValue = IR1_queue[IR1_queue_tail];
				IR1_queue_tail == QUEUE_SIZE - 1 ? IR1_queue_tail = 0 : IR1_queue_tail++; //set tail to 0 if end of queue is reached, else increments tail
				return retValue;
				break;

			case 2:
				retValue = IR2_queue[IR2_queue_tail];
				IR2_queue_tail == QUEUE_SIZE - 1 ? IR2_queue_tail = 0 : IR2_queue_tail++;
				return retValue;
				break;

			case 3:
				retValue = IR3_queue[IR3_queue_tail];
				IR3_queue_tail == QUEUE_SIZE - 1 ? IR3_queue_tail = 0 : IR3_queue_tail++;
				return retValue;
				break;

			default:
			return WRONGINPUT_ERROR;
				//Wrong input! Take corrective actions!
		}
	}
	else return EMPTYQUEUE_ERROR;
}

#endif //include guard