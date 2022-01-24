#include <iostream>

using namespace std;

int main(){
    int num, min, max;
    cin >> num;
    int integer[num];

    for(int i=0;i<num; i++){
        cin >> integer[i];
    };// integer 배열 초기화
    
    // min 과 max 기본값 설정
    min=integer[0];
    max=integer[0];

    for(int x=0;x<num;x++){
        if(min>integer[x]) min=integer[x];
        else if(max<integer[x]) max=integer[x];
    };

    cout << min << " " << max << endl;
    return 0;
}