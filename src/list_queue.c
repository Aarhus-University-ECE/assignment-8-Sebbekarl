#include <assert.h>
#include "list_queue.h"

void init_queue(queue *q)
{
  /* initializes all the variables used in the queue struct */
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

int empty(queue *q)
{
  /* checks if the size of the queue is zero */
  return q->size == 0;
}

void enqueue(queue *q, int x)
{
  /* makes a new node to put in the queue */
  qnode *new_node = (qnode *)malloc(sizeof(qnode));
  new_node->next = NULL;
  new_node->data = x;

  /* checks if there's something in the queue to place it correctly */
  if (q->size == 0)
    q->front = new_node;
  else
    q->rear->next = new_node;

  q->rear = new_node;
  q->size++;
  return;
}

int dequeue(queue *q)
{
  /* precondition is that the queue is not empty */
  assert(q->size > 0);
  
  /*stores the data and node for later use */
  qnode *temp = q->front;
  int data = q->front->data;

  /* checks if there's something in the queue to remove it correctly */
  if (q->size == 1)
  {
    q->front = NULL;
    q->rear = NULL;
  }
  else if (q->size > 1)
  {
    q->front = q->front->next;
  }

  /* frees the node to not have memory leak */
  free(temp);
  q->size--;

  /* returns the data from the queue */
  return data;
}
