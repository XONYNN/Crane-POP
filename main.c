#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef enum { FORWARD = 1, BACKWRAD = -1, IDLE = 0 } STATUS;

typedef struct Motor{ STATUS status; } Motor;

typedef struct Crane { int x, y, z; } Crane;

Motor motor[9];
Crane crane;

void Up();
void Down();
void Left();
void Right();
void Lower();
void Upper();
void Grab();
void LetGo();

int main() {
    char command[10];
    
    do {
        printf("=== 절차지향 크레인 프로그램 : 명령어를 입력하세요 ===\n");
        printf("[1] UP : 크레인을 위로 이동\n");
        printf("[2] DOWN : 크레인을 아래로 이동\n");
        printf("[3] LEFT : 크레인을 왼쪽으로 이동\n");
        printf("[4] RIGHT : 크레인을 오른쪽으로 이동\n");
        printf("[5] LOWER : 크레인의 집게 내리기\n");
        printf("[6] UPPER : 크레인의 집게 올리기\n");
        printf("[7] GRAB : 크레인의 집게 로 물건 집기\n");
        printf("[7] LETGO : 크레인의 집게 로 물건 놓기\n");

        scanf("%s", command);
        
        if(command == "UP") Up();
        else if(command == "DOWN") {
            
        }
        else if(command == "LEFT"){

        }
        else if(command == "RIGHT"){

        }
        else if(command == "LOWER") {

        }
        else if(command == "UPPER"){

        }
        else if(command == "GRAB"){

        }
        else if(command == "LETGO"){

        }


    } while(strcmp(command, "Quit"));

    return 0;
}

// 

void Up(){
    if(motor[2].status == IDLE){
        motor[2].status = FORWARD;
        crane.y += FORWARD;
        motor[2].status = IDLE;
    }
}

void Down(){
    if(motor[2].status == IDLE){
        motor[2].status = BACKWRAD;
        crane.y += BACKWRAD;
        motor[2].status = IDLE;
    }
}

void Left() {
    if(motor[1].status == IDLE){
        motor[1].status = BACKWRAD;
        crane.x += BACKWRAD;
        motor[1].status = IDLE;
    }
}

void Right() {
    if(motor[1].status == IDLE){
        motor[1].status = FORWARD;
        crane.x += FORWARD;
        motor[1].status = IDLE;
    }
}

void Lower() {
    if(motor[3].status == IDLE) {
        motor[3].status = FORWARD;
        crane.z += FORWARD;
        motor[3].status = IDLE;
    }
}

void Upper() {
    if(motor[3].status == IDLE){
        motor[3].status = BACKWRAD;
        crane.z += BACKWRAD;
        motor[3].status = IDLE;
    }
}
void Grab();
void LetGo();