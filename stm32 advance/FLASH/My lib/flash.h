#ifndef FLASH_H
#define FLASH_H
#include <stdint.h>
void flash_unlock();
void flash_lock();
void flash_erease(uint32_t addr);
void flash_write_arr(uint32_t addr,uint8_t *data,uint16_t len);
void flash_read_arr(uint32_t addr,uint8_t *data,uint16_t len);
#endif