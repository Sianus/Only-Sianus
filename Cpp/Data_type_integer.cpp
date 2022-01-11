#include <iostream>
#include <climits> //INT_MAX 등의 상수가 저장되어 있음
using namespace std;

int main(){
    // 정수형 : 소수부가 없는 수(음의 정수, 0, 양의 정수)
    // 컴퓨터가 어떤 변수를 저장할 때, 메모리 영역에 저장한다.
    // 메모리 용량에는 한계가 있으므로, 무한하게 큰 정수를 저장할 수 없다.
    // 정수형은 short, int, long, long long. 이렇게 4가지의 자료형을 가진다.
    // Why? -> 상황에 가장 알맞은 정수를 골라 사용하기 위함.
    // 위 4개의 자료형은 표현할 수 있는 정수형의 크기가 다름.

    int n_int = INT_MAX; // int 자료형이 저장할 수 있는 최대 크기
    short n_short = SHRT_MAX; // short 자료형 최대 크기
    long n_long = LONG_MAX; // long 자료형 최대 크기
    long long n_llong = LLONG_MAX; //double long 자료형 최대 크기

    cout << "int는 " << sizeof n_int << "바이트이다" << endl;
    cout << "이 바이트의 최대값은 " << n_int << " 이다." << endl;

    cout << "short는 " << sizeof n_short << "바이트이다" << endl;
    cout << "이 바이트의 최대값은 " << n_short << " 이다." << endl;

    cout << "long은 " << sizeof n_long << "바이트이다" << endl;
    cout << "이 바이트의 최대값은 " << n_long << " 이다." << endl;

    cout << "long long은 " << sizeof n_llong << "바이트이다" << endl;
    cout << "이 바이트의 최대값은 " << n_llong << " 이다." << endl;

    // short은 -32768 ~ 0 ~ 32767 까지 표현 가능
    // int, short, long, long long 은 음의 값을 저장할 수 없는 unsigned 개념을 하나씩 가지고 있음.

    unsigned int a; // unsigned가 자료형 앞에 붙는다면, 음의 값을 저장할 필요가 없음으로 저장할 수 있는 최댓값을 늘릴 수 있음
    unsigned short b; // 0~ 65535 까지 저장가능
    unsigned long c;
    unsigned long long d;
    return 0;
}