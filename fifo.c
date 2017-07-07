#include "settings.h"
static struct ring{
    char angle[SIZE];
    int write;
    int read;
    int mask;
}bufer;
void maskini(){
    bufer.mask = SIZE-1;
}
bool isfull(){
    if (((bufer.write-bufer.read) & bufer.mask)!=0)
        return 1;
    else 
        return 0;
}
bool isempty(){
    return (bufer.write==bufer.read);
}
void write(char data){
    while(!isfull())
     bufer.angle[bufer.write++ & bufer.mask] = data;
}
void* read(char* data){
    while(!isempty())
        *data++ = bufer.angle[bufer.read++ & bufer.mask];
}
