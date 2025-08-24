SELECT I.REST_ID, I.REST_NAME, I.FOOD_TYPE, I.FAVORITES, I.ADDRESS, ROUND(AVG(R.REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO AS I, REST_REVIEW AS R
WHERE I.REST_ID = R.REST_ID
AND I.ADDRESS LIKE '서울%'
GROUP BY I.REST_ID -- pk
ORDER BY SCORE DESC, I.FAVORITES DESC;

-- ROUND(숫자, N) : 반올림하여 소수 N 번째 자리까지 출력

/*
일반적으로 SELECT 절은 GROUP BY에서 사용된 속성 또는 집계함수만 사용 가능하다
그러나, MySQL에서는 GROUP BY에 사용된 속성에 따라 유일하게 결정되는 속성이라면 SELECT에서 사용 가능하다
-> 함수적 종속성(functional dependency)
*/