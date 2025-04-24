# lower_bound의 시간 복잡도와 반복자 종류에 따른 차이점

## 1. `std::lower_bound`의 기본 동작
- **정렬된 범위**에서 작동하는 이진 탐색 알고리즘.
- 일반적으로 `O(log N)`의 시간 복잡도를 가짐.
- 하지만, **사용하는 반복자의 종류**에 따라 시간 복잡도가 달라짐.

---

## 2. 반복자 종류에 따른 시간 복잡도
| 반복자 종류             | 컨테이너 예시                    | 시간 복잡도 | 이유                                                                                                                                     |
|-------------------------|----------------------------------|-------------|------------------------------------------------------------------------------------------------------------------------------------------|
| **임의 접근 반복자** (Random Access Iterator) | `std::vector`, `std::deque`, `std::array` | `O(log N)`   | 반복자를 특정 위치로 직접 이동 가능 (`begin + k` 연산 지원).                                                                               |
| **양방향 반복자** (Bidirectional Iterator)   | `std::list`, `std::set`, `std::multiset`  | `O(N)`       | 반복자 간 이동이 순차적(`++` 또는 `--`)으로만 가능. 이진 탐색이 효율적이지 않음.                                                              |

---

## 3. `std::multiset`에서 발생하는 문제
- `std::multiset`의 반복자는 **양방향 반복자(Bidirectional Iterator)**.
- `std::lower_bound(bag.begin(), bag.end(), m)` 호출 시:
  - 내부적으로 이진 탐색을 수행하려 하지만, 반복자 이동이 순차적으로 이루어져 `O(N)`의 시간 복잡도를 가짐.
- 반면, `std::multiset::lower_bound(m)` 호출 시:
  - `std::multiset`은 **레드-블랙 트리** 기반으로 구현되어 있으며, 트리 구조를 활용하여 효율적으로 탐색.
  - `O(log N)`의 시간 복잡도를 유지.

---

## 4. 코드 예시

```cpp
#include<iostream>
#include<set> //multiset::lower_bound 
#include<algorithm> //std::lower_bound

int main() {
    std::multiset<int> bag = {1, 2, 3, 5, 7, 9};

    //1. 멤버 함수 lower_bound
    auto it1 = bag.lower_bound(5); //O(log N)

    if (it1 != bag.end()) {
        std::cout << "multiset::lower_bound: " << *it1 << std::endl; //출력: 5
    }

    //2. 범위 기반 lower_bound
    auto it2 = std::lower_bound(bag.begin(), bag.end(), 5); //O(N)

    if (it2 != bag.end()) {
        std::cout << "std::lower_bound: " << *it2 << std::endl; //출력: 5
    }

    return 0;
}
```

## 결론
- **`std::lower_bound`의 시간 복잡도는 반복자의 종류에 따라 달라집니다.**
  - 임의 접근 반복자: **`O(log N)`**
  - 양방향 반복자: **`O(N)`**

- `std::list`, `std::set`, `std::multiset`과 같이 연속된 주소가 아닌 컨테이너에서는 멤버 함수로 내장된 `lower_bound`를 사용하는 것이 훨씬 효율적입니다.