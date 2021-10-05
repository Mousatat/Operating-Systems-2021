#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char TEXT [] = "MahmoudMousatat";
void _free(void * p);
void * _malloc(size_t n);
size_t getsize(void * p);
void *realloc(void *ptr,size_t size);

int main() {
    char * _old = _malloc(50);
    char * _new ;
    printf("Old size is %ld\n",getsize(_old));
    strcpy(_old,TEXT);
    _new = realloc(_old,100);
    printf("New size is %ld\n",getsize(_new));
    printf("<%s>\n",_new);
    _free(_new);
}



void _free(void * p) {
    size_t * in = p;
    if (in) free(--in);
}
void * _malloc(size_t n) {
    size_t * result = malloc(n + sizeof(size_t));
    if (result)
    {
      *result = n;
      memset(++result,0,n);
    }
    return result;
}
size_t getsize(void * p) {
    size_t * in = p;
    if (in) return *(--in);
    return -1;
}
void *realloc(void *ptr,size_t size) {
    void *newptr;
    int old_size;
    old_size = getsize(ptr);
    if (size <= old_size)return ptr;
    newptr = _malloc(size);
    memcpy(newptr, ptr, old_size);
    _free(ptr);
    return newptr;
}
