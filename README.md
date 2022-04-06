# [42Seoul] get_next_line
> file descriptor로 부터 한 line을 받아오는 함수
[gnl - get next line](https://warm-salsa-f69.notion.site/gnl-get-next-line-13a626bdaef24856b48a79ad708db31c)
## 프로젝트 소개
- read 시스템 콜을 공부하게 된다.
- 한 번 read 할 buffer size가 주어졌을 때, 효율적으로 하나의 line을 읽는 법을 고민하게 된다.
 1. strjoin이나 strdup 사용으로 반복되는 문자열 copy를 줄이고자 했다.

## 주의 사항
다음 사항을 지키지 않으면 0점 받을 것이다.
- 코드는 [norm](https://warm-salsa-f69.notion.site/Norm-85024906b60243e99a060194620cef3e)을 준수해서 작성되어야 한다.
- 어떤 상황에서도 프로그램은 segment fault, bus error, dangling pointer 등으로 중단되어서는 안 된다. (평가자가 특정 상황을 저격해서 만들어 낼 수 있음)
- heap에 할당된 모든 메모리는 적절하게 해제되어야 한다. 메모리 누수가 생겨서는 안 된다.
- gcc -Wall -Wextra -Werror 플래그로 컴파일해야 한다.
- Makefile은 relink 되어서는 안 된다.

## 사용가능한 함수 (그 외 외부 라이브러리 함수 사용불가)
- read
- malloc, free

## 구현해야 할 것
### Mandatroy part
- 함수 원형 `int get_next_line(int fd, char **line);`
- 한 번 호출에 1개의 line을 반환한다. line에 '\n'은 포함되지 않고, '\0'으로 끝난다.
- read에 성공하면 1 return, 실패하면 -1 return, EOF를 만나면 0 return
- 한 번 read에 `cc -Wall -Wextra -Werror -D BUFFER_SIZE \[num\]` define된 BUFFER_SIZE 만큼 읽어야 한다.
- c 파일 2개만 쓸 수 있다. ([norm](https://warm-salsa-f69.notion.site/Norm-85024906b60243e99a060194620cef3e) 때문에 한 파일에 25 줄인 함수 5개 밖에 못 씀)

### Bonus Part
- static variable은 1개만 쓸 수 있다. (전역변수는 당연히 사용 못 함)
- 여러 개의 file descriptor를 왔다갔다 하면서 라인을 읽어들여도 결과가 서로 섞이지 않아야 한다.
- c 파일 2개만 쓸 수 있다. ([norm](https://warm-salsa-f69.notion.site/Norm-85024906b60243e99a060194620cef3e) 때문에 한 파일에 25 줄인 함수 5개 밖에 못 씀)
