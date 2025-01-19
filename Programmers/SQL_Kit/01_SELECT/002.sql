SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE MONTH(DATE_OF_BIRTH) = 3
AND GENDER = 'W'
AND TLNO IS NOT NULL
ORDER BY MEMBER_ID;

-- DATE_FORMAT(DATE 타입의 컬럼, '나타낼 형식')
-- MONTH(DATE 타입 컬럼) : DATE 타입에서 '월'만 추출
-- 속성 IS NOT NULL : 속성값이 NULL이 아닌 레코드만 추출

/*
외부 조인:
조건 컬럼이 중복되어 출력
orders에 속한 레코드는 무조건 출력되며, orders와 조건이 맞지 않는 customer의 컬럼값은 null로 대체되어 출력

SELECT *
FROM orders LEFT OUTER JOIN customer
ON orders.custid = customer.custid;
---------------------------------------------------

내부 조인:
조건 컬럼이 중복되어 출력
조건에 맞는 레코드만 선택적으로 출력된다

SELECT *
FROM orders INNER JOIN customer
ON orders.custid = customer.custid;

SELECT *
FROM orders, customer
WHERE orders.custid = customer.custid;
---------------------------------------------------

자연 조인:
조건(겹치는) 컬럼이 반드시 하나여야 한다!
조건 컬럼이 중복되지 않고 한 번만 출력된다

SELECT *
FROM orders NATURAL JOIN customer;
---------------------------------------------------
*/