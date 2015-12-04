struct message
{
    int sender_id;
    int receiver_id;
    int number;
    char *data;
};

struct Queue
{
    int front, rear, capacity;
    struct message* array;
};

#define true 1
#define false 0

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    
    queue->array = (struct message*) malloc(queue->capacity * (sizeof(struct message)));
    
    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1 ? true : false;
}

int isFull(struct Queue* queue)
{
    return queue->rear == queue->capacity - 1 ? true : false;
}

void enQueue(struct Queue* queue, struct message* item)
{
    if (isFull(queue))
        return;
        
    queue->array[++queue->rear] = *item;
    if (isEmpty(queue))
        ++queue->front;
}

struct message deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return;
        
    struct message item = queue->array[queue->front];
    
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
        
    else
        ++queue->front;
        
    return item;
}
