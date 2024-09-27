#include "uart.h"
#include "ringbuffer.h"
#define RING_UART_LEN 64
uint8_t buff_uart[RING_UART_LEN];
RingBuffer ring_buffer;
void recive_rx(uint8_t data_rx)
{
  ring_buffer_push(&ring_buffer,data_rx);
}
uint16_t uart_available()
{
  return ring_buff_available(&ring_buffer);
}
uint8_t uart_read()
{
	uint8_t data;
	ring_buffer_pop(&ring_buffer,&data);
	return data;
}
void uart_init()
{
  ring_buffer_init(&ring_buffer,buff_uart,RING_UART_LEN);
}