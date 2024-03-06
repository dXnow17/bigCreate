#include "book.h"

void Book::cls(){
    strcpy(this->info.author,"author");
    strcpy(this->info.title,"title");
    strcpy(this->info.rfid,"00000000");
    this->info.x = 0;
    this->info.y = 0;
    this->info.z = 0;
    this->info.condition = 0;
}
