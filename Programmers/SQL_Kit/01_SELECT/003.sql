SELECT I.REST_ID, I.REST_NAME, I.FOOD_TYPE, I.FAVORITES, I.ADDRESS, ROUND(AVG(R.REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO AS I LEFT OUTER JOIN REST_REVIEW AS R
ON I.REST_ID = R.REST_ID
WHERE I.ADDRESS LIKE '서울%'
AND R.REVIEW_SCORE IS NOT NULL -- SELECT * FROM 테이블을 통해 NULL 값이 있는지 확인
GROUP BY I.REST_ID, I.REST_NAME, I.FOOD_TYPE, I.FAVORITES, I.ADDRESS -- SELECT 절에는 GROUP BY에서 사용한 속성 또는 집계함수만 사용 가능
ORDER BY SCORE DESC, I.FAVORITES DESC;

/*
외부 조인:
조건 컬럼이 중복되어 출력
아래 SQL의 경우, orders에 속한 레코드는 무조건 출력되며 조건이 맞지 않는 customer의 컬럼값은 null로 대체되어 출력

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