SELECT FIRST_HALF.FLAVOR
FROM FIRST_HALF LEFT OUTER JOIN ICECREAM_INFO
ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
WHERE FIRST_HALF.TOTAL_ORDER > 3000
AND ICECREAM_INFO.INGREDIENT_TYPE = 'fruit_based'
ORDER BY FIRST_HALF.TOTAL_ORDER DESC;

/*
외부 조인:
조건 컬럼이 중복되어 출력
orders에 속한 레코드는 무조건 출력되며 customer의 컬럼값은 null로 대체된다

SELECT *
FROM orders LEFT OUTER JOIN customer
ON orders.custid = customer.custid;
---------------------------------------------------

내부 조인:
조건 컬럼이 중복되어 출력
조건에 맞는 레코드만 출력된다

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