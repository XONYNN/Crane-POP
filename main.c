#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define FINGER_BEGIN    4
#define FINGER_END      8

typedef enum { EXIT, LEFT, RIGHT, UP, DOWN, LOWER, UPPER, GRAB, LETGO} COMMAND;

typedef enum { FORWARD = 1, BACKWARD = -1, IDLE = 0 } STATUS;

typedef struct Motor{ STATUS status; } Motor;

typedef struct Crane { int x, y, z; } Crane;

Motor motor[9];
Crane crane;

void Left(int distance);
void Right(int distance);
void Up(int distance);
void Down(int distance);
void Lower();
void Upper();
void Grab();
void LetGo();
void Err(int index, char *status);

int main() {
    int command;
    
    crane.x = 0;
    crane.y = 0;
    crane.z = 0;
    
    while(1){
        printf("=== 절차지향 크레인 프로그램 : 명령어를 입력하세요 ===\n");
        printf("[1] LEFT : 크레인을 왼쪽으로 이동\n");
        printf("[2] RIGHT : 크레인을 오른쪽으로 이동\n");
        printf("[3] UP : 크레인을 위로 이동\n");
        printf("[4] DOWN : 크레인을 아래로 이동\n");
        printf("[5] LOWER : 크레인의 집게 내리기\n");
        printf("[6] UPPER : 크레인의 집게 올리기\n");
        printf("[7] GRAB : 크레인의 집게 로 물건 집기\n");
        printf("[8] LETGO : 크레인의 집게 로 물건 놓기\n");
        printf("[0] EXIT : 프로그램 종료\n");

        printf(" > ");
        scanf("%d", &command);

        int distance = 0;
        
        if(command == LEFT){
            printf("움직일 거리를 입력하세요\n > ");
            scanf("%d", &distance);
            Left(distance);
        }
        else if(command == RIGHT){
            printf("움직일 거리를 입력하세요\n > ");
            scanf("%d", &distance);
            Right(distance);
        }
        else if(command == UP) {
            printf("움직일 거리를 입력하세요\n > ");
            scanf("%d", &distance);
            Up(distance);
        }
        else if(command == DOWN) {
            printf("움직일 거리를 입력하세요\n > ");
            scanf("%d", &distance);
            Down(distance);
        }
        else if(command == LOWER) Lower();
        else if(command == UPPER) Upper();
        else if(command == GRAB) Grab();
        else if(command == LETGO) LetGo();
        else if(command == EXIT){
            printf("[EXIT] : 절차지향 크레인 프로그램을 종료합니다.\n");
            break;
        }
        else{
            printf("[ERROR] : 올바른 명령어가 아닙니다!\n");
            continue;
        } 

        printf("현재 크레인 좌표 (x, y, z) = (%d, %d, %d)\n", crane.x, crane.y, crane.z);


    }

    return 0;
}

// 

void Err(int index, char * status) {
    printf("[ERROR] : motor[%d] 의 상태는 이미 %s 입니다\n", index, status);
}

void Left(int distance) {
    if(motor[1].status == IDLE){
        motor[1].status = BACKWARD;
        crane.x += BACKWARD * distance;
        motor[1].status = IDLE;
    }
}

void Right(int distance) {
    if(motor[1].status == IDLE){
        motor[1].status = FORWARD;
        crane.x += FORWARD * distance;
        motor[1].status = IDLE;
    }
}

void Up(int distance){
    if(motor[2].status == IDLE){
        motor[2].status = FORWARD;
        crane.y += FORWARD * distance;
        motor[2].status = IDLE;
    }
}

void Down(int distance){
    if(motor[2].status == IDLE){
        motor[2].status = BACKWARD;
        crane.y += BACKWARD * distance;
        motor[2].status = IDLE;
    }
}


void Lower() {
    if(motor[3].status == FORWARD){
        Err(3, "FORWARD");
        return;
    }
    motor[3].status = FORWARD;
    crane.z += FORWARD;
}

void Upper() {
    if(motor[3].status == BACKWARD) {
        Err(3, "BACKWARD");
        return;
    }
    motor[3].status = BACKWARD;
    crane.z += BACKWARD;
}

void FingerGrab(int fingerIndex) {
    if(motor[fingerIndex].status == FORWARD){
        Err(fingerIndex, "FORWARD");
        return;
    }
    motor[fingerIndex].status = FORWARD;
}

void FingerLetgo(int fingerIndex) {
    if(motor[fingerIndex].status == BACKWARD){
        Err(fingerIndex, "BACKWARD");
        return;
    }
    motor[fingerIndex].status = BACKWARD;
}

void Grab() {
    for(int index = FINGER_BEGIN ; index < FINGER_END ; index++){
        FingerGrab(index);
    }
}

void LetGo() {
    for(int index = FINGER_BEGIN ; index < FINGER_END ; index++){
        FingerLetgo(index);
    }
}
