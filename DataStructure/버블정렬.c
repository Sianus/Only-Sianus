#include <stdio.h>
#include <stdlib.h>

/* <선택정렬>
- n개의 정렬되지 않은 데이터가 있을 때, 오름/내림 차순으로 정렬하는 알고리즘 중 하나
- (설명은 내림차순 기준) 선택 정렬은 n개 중에서 가장 작은 데이터를 "선택"해서 앞쪽으로 이동시키는 것.
- 한 번의 과정을 거치면 0번 인덱스 자리에는 이미 최솟값이 들어가 있으므로, 두번째로 작은 값은 1번 인덱스에 들어가야 한다.
 = 즉, n-1개 중에서 가장 작은 값을 찾아서 앞쪽으로 이동.
- 그래서, 위의 과정을 거치다보면 하나의 특징이 생긴다.
- n 개에서 한번의 정렬 과정을 거치면, 가장 작은 값이 제일 앞쪽으로 위치하고, 다음 정렬 대상이 n-1개가 된다. 즉 n개에서 빼기 해주는 값 만큼 정렬이 된 상태이다.
- 이 말은 즉, 반복문으로 표현할 때,
1) i = 0 => n개의 값이 정렬 대상임
2) i = 1 => n개의 값 중 1개의 값이 정렬되었음을 의미하며, 다음 정렬 대상은 n-1개임을 동시에 뜻한다.
    j = i 라고 작성했을 때, j는 정렬 대상을 직접적으로 다루는 역할을 한다.
*/

int main() {
    int n;
    scanf("%d", &n);
    int *list=(int *)malloc(4*n);
    /*
    1. malloc은 void라서 (int *)를 작성해줘야 함. 위의 예에서 list가 포인터값이기 때문에, void 자리에 (int *) 이 들어가는 것
    2. 4*n에서 4는 sizeof(int)
    */

    for(int i = 0; i<n; i++){
        scanf("%d", &list[i]);
    }
    int tmp;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(list[i]>list[j]){
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
            else continue;
        }
    }
    for(int i = 0; i<n; i++) printf("%d ", list[i]);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
/*
swap 함수에 포인터를 지정해주는 이유
1. parameter에 주소를 가리키는 포인터가 아닌 일반 변수가 들어간다면, 함수 안에서만 값이 변경될 뿐, 최종결과에는 영향을 미치지 않는다.
그렇기 때문에, 주소를 가리키는 포인터 값을 parameter를 사용해서, 주소값에 있는 내용끼리 연산을 실행한다.( = 주소값은 그대로지만, 주소값에 들어있는 내용이 변경된다.)
 = 가리키는 주소가 달라지는 것이 아니라, 가리키는 주소의 내용물이 변경되는 것
2. 함수가 void형이라 return 값이 존재하지 않기 때문에 포인터를 사용.
*/