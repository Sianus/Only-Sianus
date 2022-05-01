#include <stdio.h>
#include <stdlib.h>

typedef struct tag1{
    int st_no;
    char name[20];
    enum tag2{female, male}gender;
    union {
        short int height;
        float weight;
    } value;
} address;

int main(){
    address temp;
    temp.st_no = 20061234;
    strcpy(temp.name, "Maria");
    temp.gender=female;
    temp.value.height = 170;
    printf("st_no : %d\nname : %s\ngender = %d\nheight : %d", temp.st_no, temp.name, temp.gender, temp.value.height);
    return 0;
}