# Call-by-Value, Call-by-Reference

## Call-by-Value

### 설명
- 함수에서 **기본형, 구조체, STL(예: vector) 타입의 변수**를 인자로 넘기면, **해당 값**이 복사되어 매개변수에 전달됩니다.
- 이 복사는 원본 데이터를 기반으로 **새로운 복사본**을 생성하기 때문에, 함수 내부에서 복사본이 변경되더라도 **원본 데이터는 영향을 받지 않습니다.**

### 특징
- 원본 데이터를 보호할 수 있습니다.
- 함수 호출 시 값을 복사하는 과정에서 전달 비용이 발생합니다. (특히, 구조체나 STL 객체처럼 담긴 데이터의 크기가 큰 경우)

---

## Call-by-Reference

### 설명
- **배열, 포인터, 참조자로 선언된 변수**를 함수 인자로 넘길 때, 매개변수는 **원본 변수의 메모리 주소를 참조**합니다.
- 함수 내부에서 해당 데이터에 직접 접근하며 **수정 시 원본 데이터가 변경**됩니다.

### 특징
- 데이터 복사가 이루어지지 않으므로, 메모리와 시간 면에서 효율적입니다.
- 원본 데이터를 보호하려면 `const` 키워드를 사용하여 읽기 전용 참조로 전달해야 합니다.

---

## 추가로 확인할 점

### 1. 배열의 전달은 항상 Call-by-Reference처럼 동작
- 배열을 단순하게 함수 인자로 전달할 때는 배열의 첫 번째 요소의 주소가 전달됩니다.
- 다만 배열의 크기 정보는 전달되지 않으므로, 크기를 별도로 인자로 넘겨야 합니다.

### 2. STL 객체(Call-by-Value vs Call-by-Reference)
- STL 객체(예: `std::vector`, `std::string`)를 단순히 인자로 넘기면 Call-by-Value(default) 데이터 복사가 이루어져 성능에 영향을 줄 수 있습니다.
- 시간복잡도 O(N)의 데이터 복사를 방지하려면 참조자(`&`) 또는 포인터(`*`)를 사용한 연산으로 전달하는 것이 좋습니다.

### 3. 참조를 사용할 때 주의
- 원본 데이터의 변경을 원치 않을 경우 `const` 키워드를 사용하여 함수 내부에서 수정되지 않도록 명시적으로 보호해야 합니다.

```cpp
void readOnlyFunction(const int& value) {
    //value는 읽기 전용으로 접근 가능
    //value = 10;  //컴파일 에러 발생
}
```

---

## Deep Copy, Shallow Copy와의 관련성
Call by Value와 Call by Reference는 함수에서의 인자 전달 방식을 설명하는 개념이고, Shallow Copy와 Deep Copy는 `=` 연산을 활용해 객체를 복사할 때의 동작 방식을 설명하는 개념입니다. 하지만 둘 다 데이터의 복사와 메모리 관리 방식과 관련이 있으므로 서로 유사한 개념으로 이해할 수 있습니다.

- 얕은 복사(Shallow Copy)는 Call by Reference(참조 전달)와 유사합니다. 복사 시 같은 주소를 공유하게 됩니다.
- 깊은 복사(Deep Copy)는 Call by Value(값 전달)와 유사합니다. 복사 시 데이터 값을 복사하며 주소는 공유되지 않습니다.

기본 자료형이나 구조체, STL 타입 변수의 `=` 연산이나 memcpy(), copy()의 경우 `Deep Copy`가 발생합니다. 그러나 O(N)이므로 연산 시 유의!

```cpp
int v[3] = {1, 2, 3}; //복사 대상
int ret[3]; //복사 결과를 담을 대상

memcpy(ret, v, sizeof(v)); //Deep Copy
```

```cpp
vector<int> v{1, 2, 3}; //복사 대상

/** 10 10 10
 * vector<int> v(3, 10); //since C++98
 * vector<int> v = {10, 10 ,10};
 * vector<int> v{10, 10, 10}; //since C++11(uniform initialization). 현재 표준 방식
 * */

vector<int> ret(3); //복사 결과를 담을 대상

copy(v.begin(), v.end(), ret.begin()); //Deep Copy. 벡터는 memcpy가 적용되지 않습니다
```