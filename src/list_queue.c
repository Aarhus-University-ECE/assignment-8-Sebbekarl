#include "list_queue.h"

void init_queue(queue *q)
{
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

int empty(queue *q)
{
  if (q->size == 0)
    return 1;
  return 0;
}

void enqueue(queue *q, int x)
{
  qnode *new_node = (qnode *)malloc(sizeof(qnode));
  new_node->next = NULL;
  new_node->data = x;

  if (q->size == 0)
  {
    q->rear = new_node;
    q->front = new_node;
  }
  else
  {
    qnode *temp_node = q->rear;
    temp_node->next = new_node;
    q->rear = new_node;
  }
  q->size++;
  return;
}

int dequeue(queue *q)
{
  if (q->size == 1)
  {
    qnode *temp = q->front;
    int data = q->front->data;
    q->front == NULL;
    q->rear == NULL;
    free(temp);
    q->size--;
    return data;
  }
  else if (q->size > 1)
  {
    qnode *temp = q->front;
    int data = q->front->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
  }
  exit(EXIT_FAILURE);
}
