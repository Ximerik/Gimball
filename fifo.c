or#include "settings.h"

struct ring_bufer{
    uint16_t memory[SIZE];
    int write_count,
        read_count;
}angle, angular_speed;
int is_full(struct ring_bufer *this_bufer){
    if (((this_bufer->write_count) - (this_bufer->read_count)) != 0)
        return 0;
    else
        return 1;
}
int is_empty(struct struct ring_bufer *this_bufer){
    if ((((*this_bufer->write_count) - (*this_bufer->read_count)) == 0)
        return 1;
    else
        return 0;
}
void write(char data, struct ring_bufer *this_bufer){
    while(isfull() != 1){
        this_bufer -> memory[(*this_bufer -> write_count)++] = data;
        if (*this_bufer -> write_count > SIZE-1)
            *this_bufer -> write_count = 0;
    }
}
void read(char* data, struct ring_bufer *this_bufer){
    while(isempty() != 1){
        *data++ = this_bufer -> memory[(*this_bufer -> read_count)++];
        if (*this_bufer -> read_count > SIZE-1)
            *this_bufer -> read_count = 0;
    }
}
void clear_bufer(struct ring_bufer *this_bufer){
    *this_bufer -> write_count = 0;
    *this_bufer -> read_count = 0;
}
uint16_t getdata_pid(struct ring_bufer *this_bufer){
    while(isempty() != 1){
        return this_bufer -> memory[(*this_bufer -> read_count)++];
        if (*this_bufer -> read_count > SIZE-1)
            *this_bufer -> read_count = 0;
    }
    return COMAND; 
    // if bufer is empty - foo return COMAND value for zero PID output
}
