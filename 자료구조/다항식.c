#include <stdio.h>
#define COMPARE(x,y) (x<y ? -1: (x==y ? 0:1))
#define MAX_TERMS 100

/* < 다항식 구조체 >
1. 지수와 차수가 멤버인 구조체 필요
2. 다항식 정보를 저장할 배열 필요
3. 다항식 연산에 필요한 현재 위치를 나타낼 변수 필요
*/
typedef struct{
    float coef;
    int expo;
}poly;

poly terms[MAX_TERMS];
int avail = 0;

/* < 덧셈을 하지않는 값들을 결과항에 넣어주기 위한 함수 >
1. 연산하지 않는 항의 다항식 정보
2. 어디에 추가할 것인지에 대한 정보
*/
void attach(float coeff, int expon){
    if(avail >= MAX_TERMS){
        printf("Too many poly!");
        exit(1);
    }
    terms[avail].coef = coeff;
    terms[avail++].expo = expon;
}

/* < 다항식의 덧셈을 실행하는 함수 >
1. 두 다항식의 시작과 끝, 결과값을 저장할 장소
2. 두 다항식을 비교하고, 각 식에 대한 덧셈 처리 필요
*/
void poly_add(int sa, int fa, int sb, int fb, int *sd, int *fd){
    *sd = avail; // 덧셈을 진행하면서 avail은 계속 변경되다가 마지막에 결과값 저장하는 부분에 avail 값이 나타남.
    while(sa<=fa && sb <= fb){
        switch(COMPARE(terms[sa].expo, terms[sb].expo)){
            case -1: // sa.expo < sb.expo
                attach(terms[sb].coef, terms[sb].expo);
                sb++;
                break;
            case 0: // sa.coef + sb.coef = 0 인 경우도 생각해야하므로 예외처리도 할 것.
                float coeff = terms[sa].coef + terms[sb].coef;
                if(coeff) attach(coeff, terms[sa].expo);
                sa++;
                sb++;
                break;
            case 1: // sa.expo > sb.expo
                attach(terms[sa].coef, terms[sa].expo);
                sa++;
                break;
        }
        for(; sa<=fa; sa++) attach(terms[sa].coef, terms[sa].expo);
        for(; sb<=fb; sb++) attach(terms[sb].coef, terms[sb].expo);
        *fd = avail - 1;
    }
}

int main(){
    
    return 0;
}