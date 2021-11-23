# crc-implement
crc implement

표준 CRC 알고리즘을 사용하여 오류 감지 메커니즘을 구현하기

generator, verifier, alter 로 이루어져 있다.

## generator

표준 입력으로 다음을 읽음

1. 0과 1의 문자열로 구성된 n bit 메시지 ASCII 
2. k bit 다항식 ASCII

표준 출력으로 다음을 출력

1. n+k bit의 0과 1이 포함된 ASCII
2. 다항식

## verifier

generator의 출력을 읽고 올바른지 여부 출력

## alter

한 개의 특정 비트를 반전

## 실행

~~~
./generator < [파일명] | ./verifier
~~~

~~~
./generator < [파일명] | ./alter arg | ./verifier
~~~