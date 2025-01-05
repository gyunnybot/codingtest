SELECT FIRST_HALF.FLAVOR
FROM FIRST_HALF LEFT OUTER JOIN ICECREAM_INFO
ON FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
WHERE FIRST_HALF.TOTAL_ORDER > 3000
AND ICECREAM_INFO.INGREDIENT_TYPE = 'fruit_based'
ORDER BY FIRST_HALF.TOTAL_ORDER DESC;

/*
외부 조인: 조건 컬럼이 중복되어 출력됨. orders 레코드는 customer에 상관없이(null 처리) 무조건 출력
select *
from orders left join customer
on orders.custid = customer.custid;

내부 조인: 조건 컬럼이 중복되어 출력됨. 조건에 맞는 레코드만 출력된다
select *
from orders, customer
where orders.custid = customer.custid;

자연 조인: 겹치는 컬럼이 반드시 하나여야 한다. 겹치는 컬럼은 한 번만 출력됨
select *
from orders natural join customer;
*/