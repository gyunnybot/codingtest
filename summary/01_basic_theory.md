# 코테 이론 기본

### IEEE 754

<br>
IEEE 754 :

    bit / exponent / fraction

    float = 1 / 8 / 23
    
    double = 1 / 11 / 52



<br>float bias = 2^(8-1)-1 =  127, double bias = 2^(11-1)-1 =1023

예를 들어, -6.75를 이진수로 나타내면 -1.1011 * 2^2가 된다. 따라서,

sign / exponent / fraction<br>
1 / 10000001 / 10110000....(나머지는 0으로 채워짐)

<br>

### BOJ, 구름 환경에서 빠른 I/O를 위한 CustomScanner
```java
static class CustomScanner {
    private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer st;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();

            if (line.isEmpty()) {
                continue;
            }

            st = new StringTokenizer(line);
        }

        return st.nextToken();
    }

    int nextInt() throws IOException {
        String s = next();

        return Integer.parseInt(s);
    }
}
```

문자 하나씩 받을 때는 일단 next()로 문자열 형태로 받은 후 s.charAt(0)을 통해 char 타입으로 저장한다.

```java
String s = new String("hello");

System.out.println(s.charAt(4)); // o
System.out.println(s.indexOf('o')); // 4
```

프로그래머스는 값을 입력받을 필요가 없으므로 CustomScanner 정의 불필요

<br>

### 자료구조 정리
입력으로 주어지는 고정 격자 배열이나, 정해진 범위가 있는 배열 바구니는 일반 배열 []을 사용한다.

재귀나 백트래킹처럼 원소를 뒤에서 추가, 삭제하는 상황이 빈번한 경우 컬랙션 배열 ArrayList를 사용한다.

배열을 제외한 나머지 자료구조는 웬만하면 컬랙션을 사용한다.

<br>

빈출되는 자료구조 : 우선순위 큐, 큐, 스택 정리 :
```java
PriorityQueue<Integer> pq = new PriorityQueue<>();

값 삽입 : offer(value);
값 조회 : peek();
값 반환+삭제 : poll();


Queue<Integer> q = new ArrayDeque<>();

값 삽입 : offer(value);
값 조회 : peek();
값 반환+삭제 : poll();


Deque<Integer> st = new ArrayDeque<>();

값 삽입 : push(value);
값 조회 : peek();
값 반환+삭제 : poll();
```

<br>

### 정렬
- 일반 [] 배열 정렬: `Arrays.sort(arr);`
- 일반 [] 내림차순 정렬: `Arrays.sort(arr, Collections.reverseOrder());`
    
    (단, 기본형인 경우에는 적용 불가. 래퍼형 `Integer[]`로 변경해야 함)
    
- 컬렉션(List 등) 정렬: `Collections.sort(list);`
- 내림차순 정렬: `Collections.sort(list, Collections.reverseOrder());`

<br>

- 일반 [] 배열 범위 정렬 : Arrays.sort(arr, 0, n); => 0번 인덱스부터 n-1번 인덱스까지 정렬

- 컬랙션 배열 범위 정렬 : subList 메서드로 범위 정렬 가능
    ```java
    List<Integer> list = new ArrayList<>(Arrays.asList(5, 4, 3, 2, 1));
        
        // 인덱스 1부터 3까지(4는 제외)만 정렬하고 싶을 때
        // [4, 3, 2] 부분만 오름차순 정렬됨
        Collections.sort(list.subList(1, 4)); // st, ed - 1

        System.out.println(list); // 출력: [5, 2, 3, 4, 1]
    ```
<br>

- Comparable, Comparator

    내가 만든 클래스가 정렬 가능하려면, Comparable 인터페이스를 구현해야 하는데, compareTo 메서드를 재정의하면 된다. 여기서의 정렬 기준이 클래스의 기본 정렬 방식이 된다. 근데, 특정 상황에서 다른 정렬 기준이 필요할 수 있다. 이럴때에는 Comparator 인터페이스를 구현한 클래스를 하나 만들고 sort의 두 번째 인자로 인스턴스를 넣어주면 된다.

    ```java
    // Comparable
    class Info implements Comparable<Info> {
        int start;
        int end;

        public Info(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Info other) {
            if(this.end == other.end) {
                return Integer.compare(this.start, other.start); // 시작하는 시각이 빠르게
            }

            return Integer.compare(this.end, other.end); // 오름차순 정렬
        }
    }

    Collections.sort(infos);

    // Comparator
    class StartComparator implements Comparator<Info> {
        @Override
        public int compare(Info i1, Info i2) {
            return Integer.compare(i1.start, i2.start);
        }
    }

    Collections.sort(list, new StartComparator());
    ```
일반 [] 정렬은 원시 타입의 경우 comparator 사용 불가, 래퍼형의 경우에만 사용 가능하다.

<br>

### 람다 표현식으로 Comparator 직접 구현 (코테에서의 일반적인 정렬 방법)
```java
class User {
    Long id;
    String name;

    public User(Long id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}

public static void main(String[] args) throws IOException {
    List<User> users = new ArrayList<>();
    users.add(new User(3L, "b"));
    users.add(new User(1L, "c"));
    users.add(new User(2L, "a"));

    Collections.sort(users, (u1, u2) -> Long.compare(u1.id, u2.id));

    for(User u : users) {
        System.out.println(u.toString()); // 숫자 기준 정렬
    }

    Collections.sort(users, (u1, u2) -> u1.name.compareTo(u2.name));

    for(User u : users) {
        System.out.println(u.toString()); // 문자열 기준 정렬
    }
}

User{id=1, name='c'}
User{id=2, name='a'}
User{id=3, name='b'}
User{id=2, name='a'}
User{id=3, name='b'}
User{id=1, name='c'}
```