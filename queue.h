#define QUEUE_SIZE 10
//typedef enum commands {push = 1, skip = 2};
//nxtOSEK brokker sig over enums

//Queues...
int US1_queue[QUEUE_SIZE];
int US1_queue_head = 0;
int US1_queue_tail = 0;

int US2_queue[QUEUE_SIZE];
int US2_queue_head = 0;
int US2_queue_tail = 0;

int US3_queue[QUEUE_SIZE];
int US3_queue_head = 0;
int US3_queue_tail = 0;
//Queues...


void enqueue(int queue_ID)
{

 		switch(queue_ID){
 			case 1:
 				US1_queue[US1_queue_head] = 1;
 				US1_queue_head == QUEUE_SIZE -1 ? US1_queue_head = 0 : US1_queue_head++;				
 				break;

 			case 2:
 			 	US1_queue[US1_queue_head] = 2;
 				US2_queue[US2_queue_head] = 1;

 			    US1_queue_head == QUEUE_SIZE -1 ? US1_queue_head = 0 : US1_queue_head++;
 			    US2_queue_head == QUEUE_SIZE -1 ? US2_queue_head = 0 : US2_queue_head++;
 				break;

 			case 3:
 			 	US1_queue[US1_queue_head] = 2;
 			 	US2_queue[US2_queue_head] = 2;
 			 	US3_queue[US3_queue_head] = 1;

 				US1_queue_head == QUEUE_SIZE -1 ? US1_queue_head = 0 : US1_queue_head++;
 			    US2_queue_head == QUEUE_SIZE -1 ? US2_queue_head = 0 : US2_queue_head++;
 			    US3_queue_head == QUEUE_SIZE -1 ? US3_queue_head = 0 : US3_queue_head++;


 				break;

 			default:
 				//Wrong input! Take corrective actions!
 		}
}

int dequeue(int queue_ID)
{
	int retValue;
	switch(queue_ID){
		case 1:
			retValue = US1_queue[US1_queue_tail];
			US1_queue_tail == QUEUE_SIZE -1 ? US1_queue_tail = 0 : US1_queue_tail++;
			return retValue;
			break;

		case 2:
			retValue = US2_queue[US2_queue_tail];
			US2_queue_tail == QUEUE_SIZE -1 ? US2_queue_tail = 0 : US2_queue_tail++;
			return retValue;
			break;

		case 3:
			retValue = US3_queue[US3_queue_tail];
			US3_queue_tail == QUEUE_SIZE -1 ? US3_queue_tail = 0 : US3_queue_tail++;
			return retValue;
			break;

		default:
		return 003;
			//Wrong input! Take corrective actions!
	}

}
