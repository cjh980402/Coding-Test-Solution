# Coding-Test-Solution
플랫폼별 코딩테스트 풀이 모음

## programmers
- https://programmers.co.kr
    - 문제 링크: `https://programmers.co.kr/learn/courses/30/lessons/{문제번호}`

## HackerRank
- https://www.hackerrank.com
    - 문제 링크: `https://www.hackerrank.com/challenges/{문제이름}/problem`

## Baekjoon
- https://www.acmicpc.net
    - 문제 링크: `https://www.acmicpc.net/problem/{문제번호}`

## 코딩테스트 관련 내용 정리
### 사용언어
- C++

### 자주 쓰이는 함수
- prev_permutation: 사전 순서의 이전 순열을 구하는 함수
- next_permutation: 사전 순서의 다음 순열을 구하는 함수
- sort: 정렬을 수행하는 함수(기본적으로 오름차순, 정렬의 기준으로 사용할 비교함수 지정 가능)
- min: 2개의 값 중 작은 값을 반환하는 함수
- max: 2개의 값 중 큰 값을 반환하는 함수
- min_element: 이터레이터로 주어진 범위에서 최솟값의 이터레이터를 반환하는 함수
- max_element: 이터레이터로 주어진 범위에서 최댓값의 이터레이터를 반환하는 함수
- transform: 이터레이터로 주어진 범위 전체에 콜백함수를 적용하는 함수
- toupper: 대문자로 변환하는 함수
- tolower: 소문자로 변환하는 함수
- isupper: 대문자면 true, 아니면 false를 반환하는 함수
- islower: 소문자면 true, 아니면 false를 반환하는 함수

### 자주 쓰이는 STL
- vector: 가변 배열
- stack: 스택
- queue: 큐
- priority_queue: 힙 구조로 구현된 우선순위 큐(기본적으로 큰 값이 앞에 있음)
- map: 맵
- set: 집합
- pair: 2개의 값 묶음

### 자주 쓰이는 알고리즘
- 완전탐색
- 이진탐색
    - 정렬된 대상에서의 단순한 값 탐색
    - 답이 될 수 있는 최소~최대 범위에서 중간값을 선택하고 답이라 가정한 후, 실제 답으로 사용 가능한지 검토하고 탐색의 방향을 결정하여 최종적으로 답을 찾는 역추적에도 사용이 가능
- DFS(스택 사용)
- BFS(큐 사용)
- 그리디
- DP
    - 탑다운 방식
    - 바텀업 방식
- 크루스칼
- 다익스트라(우선순위 큐 사용)
- 플로이드-워셜