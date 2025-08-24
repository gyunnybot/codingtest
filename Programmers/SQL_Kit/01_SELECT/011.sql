SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) >= 2
ORDER BY USER_ID ASC, PRODUCT_ID DESC;

-- GROUP BY로 묶여진 테이블은 HAVING으로 조건문을 실행한다

/*
SELECT contribution
FROM table
WHERE condition1 -- 일반적인 테이블에서의 조건절 WHERE
GROUP BY contribution -- 그룹화
HAVING condition2 -- 그룹화된 테이블에서의 조건절 HAVING
*/