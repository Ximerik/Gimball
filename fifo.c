#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <inttypes.h>

#define SIZE 5

struct ring_bufer{
    uint16_t memory[SIZE];
    uint8_t write_count,
            read_count;
};
/**< Доработать проверку на полный и пустой буфер.
     Вставить проверку в запись и чтение*/
int is_full(struct ring_bufer *this_bufer){
    if ((( this_bufer->write_count) - (this_bufer->read_count)) != 0
        || this_bufer->write_count == 0 && this_bufer->read_count == 0)
        return 0;
    else
        return 1;
}
int is_empty(struct ring_bufer *this_bufer){
    if (((this_bufer->write_count) - (this_bufer->read_count)) == 0)
        return 1;
    else
        return 0;
}
void write(char data, struct ring_bufer *this_bufer){
    while (is_full(this_bufer)!=1 && data != '\0')
            this_bufer -> memory[(this_bufer -> write_count)++] = data;
    if (this_bufer -> write_count > SIZE-1)
    this_bufer -> write_count = 0;
}
void read(char* data, struct ring_bufer *this_bufer){
        *data++ = this_bufer -> memory[(this_bufer -> read_count)++];
        if (this_bufer -> read_count > SIZE-1)
            this_bufer -> read_count = 0;
}
void clear_bufer(struct ring_bufer *this_bufer){
    this_bufer -> write_count = 0;
    this_bufer -> read_count = 0;
}
uint16_t getdata_pid(struct ring_bufer *this_bufer){
    while(is_empty(this_bufer) != 1){
        return this_bufer -> memory[(this_bufer -> read_count)++];
        if (this_bufer -> read_count > SIZE-1)
            this_bufer -> read_count = 0;
    }
    return 1;
    /**< if bufer is empty - foo return COMAND value for zero PID output */
}

/*
* GLOBAL
*/
struct ring_bufer bufer;

int main()
{
    write('a', &bufer);
    write('a', &bufer);
    return 0;
}
