#include "ringbuffer.h"
int8_t ring_buffer_push(RingBuffer *ring_buff, uint8_t data)
{
    uint16_t next;

    next = ring_buff->pHead + 1;  // next is where head will point to after this write.
    if (next >= ring_buff->maxlen)  // chi co the ghi den gia tri len - 1
        next = 0;

    if (next == ring_buff->pTail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    ring_buff->buffer[ring_buff->pHead] = data;  // Load data and then move
    ring_buff->pHead = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}
int8_t ring_buffer_pop(RingBuffer *ring_buff, uint8_t *data)
{
    int16_t next;

    if (ring_buff->pHead == ring_buff->pTail)  // if the head == tail, we don't have any data
        return -1;

    next = ring_buff->pTail + 1;  // next is where tail will point to after this read.
    if(next >= ring_buff->maxlen)
        next = 0;

    *data = ring_buff->buffer[ring_buff->pTail];  // Read data and then move
    ring_buff->pTail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}
// tra ve so luong phan tu co trong vong dem
uint16_t ring_buff_available(RingBuffer *ring_buff)
{
  if(ring_buff->pHead >= ring_buff ->pTail)
		return ring_buff->pHead - ring_buff ->pTail;
	
	else return ring_buff->maxlen - (ring_buff->pTail-ring_buff->pHead);
}
void ring_buffer_init(RingBuffer *ring_buff,uint8_t *buff,uint16_t len)
{
  ring_buff->buffer = buff;
	ring_buff->pHead =0;
	ring_buff->pTail =0;
	ring_buff->maxlen = len;
}