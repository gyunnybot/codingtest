SELECT ROUND(AVG(DAILY_FEE), 0) AS AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE = 'SUV';

-- ROUND(num, i) : 숫자 num(일반적으로 집계함수의 반환 값)을 소수 i번째 자릿수까지 반올림하여 출력