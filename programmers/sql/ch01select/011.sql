SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) >= 2
ORDER BY USER_ID ASC, PRODUCT_ID DESC;

-- GROUP BY로 묶여진 테이블은 HAVING으로 조건절을 생성할 수 있다

/*
SELECT attrib -- SELECT에서는 GROUP BY에서 사용된 속성 또는 집계함수만 사용할 수 있다
FROM table
WHERE cond1 -- 일반적인 테이블에서의 조건절 WHERE
GROUP BY attrib -- 그룹화
HAVING cond2 -- 그룹화된 테이블에서의 조건절 HAVING
*/