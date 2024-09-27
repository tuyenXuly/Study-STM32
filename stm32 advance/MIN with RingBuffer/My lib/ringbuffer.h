#ifndef RING_BUFFER_H
#define RING_BUFFER_H
#include <stdint.h>

typedef struct
{
  uint8_t * buffer;  //tu khoa const tuc la khong the thay doi gia tri cua con tro
  uint16_t pHead;
	uint16_t pTail;
	uint16_t maxlen;
}RingBuffer;
void ring_buffer_init(RingBuffer *ring_buff,uint8_t *buff,uint16_t len);
int8_t ring_buffer_push(RingBuffer *ring_buff, uint8_t data);
int8_t ring_buffer_pop(RingBuffer *ring_buff, uint8_t *data);
uint16_t ring_buff_available(RingBuffer *ring_buff);
#endif