#include "book.h"

void Book::cls(){
    strcpy(this->info.book_author,"author");
    strcpy(this->info.book_title,"title");
    strcpy(this->info.rfid,"00000000");
    this->info.book_x = 0;
    this->info.book_y = 0;
    this->info.book_z = 0;
    this->info.condition = 0;
}
