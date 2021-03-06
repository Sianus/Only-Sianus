#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string a; // 16진수로 입력받을 것이므로 string형으로 정의
    cin >> a; // 입력
    int result = 0; // for문을 통해 반복덧셈을 할 것이므로 0으로 미리 초기화
    int b = a.length(); // a의 길이를 알아야 16진수를 10진수로 변환 가능
    int k; // a의 자릿수 별로 특정값을 지정해주기 위함
    for(int i=0; i<a.length(); i++){
        if(a[i]=='A') k=10;
        else if(a[i]=='B') k=11;
        else if(a[i]=='C') k=12;
        else if(a[i]=='D') k=13;
        else if(a[i]=='E') k=14;
        else if(a[i]=='F') k=15;
        else k = a[i] - '0'; // char형에서 int형 변환하는 방법 중 하나. char형은 이미 정수형이므로 '0'을 빼줌으로써 정수형태로 변형
        // stoi 사용 시 에러가 나는데, 그 이유는 string 형태 중 하나의 인덱스만 뽑아왔기 때문이다.
        result += k*pow(16,b-1); // 16진수를 10진수로 바꾸는 공식
        b-=1; // 자릿수에 맞추기 위해
    }
    cout << result << endl;
    return 0;
    //이후 stoi를 이용하여 쉽게 풀어보기
    //https://godog.tistory.com/entry/C-string-to-int-int-to-string-%ED%98%95%EB%B3%80%ED%99%98-%ED%95%98%EA%B8%B0#:~:text=C%2B%2B%20string%20to%20int%2C%20int%20to%20string%20%ED%98%95%EB%B3%80%ED%99%98,%EC%A4%80%EB%8B%A4.%20%28stoi%20-%3E%20string%20to%20integer%EB%A5%BC%20%EC%A4%84%EC%9D%B8%20%EA%B2%83%EC%9D%B4%EB%8B%A4.
    //위 링크는 참조
}