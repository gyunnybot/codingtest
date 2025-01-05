SELECT ROUND(AVG(DAILY_FEE), 0) AS AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR 
WHERE CAR_TYPE = 'SUV';

-- ROUND(num, i) : 숫자 값 num을 소수 n번째 자릿수까지 반올림하여 출력. 음수를 사용하면 정수 자릿수 또한 제한할 수 있다