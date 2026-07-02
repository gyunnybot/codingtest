SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION NOT IN ('Aged')
ORDER BY ANIMAL_ID;

-- 범위 내 조건 : IN, NOT IN ('value')

/*
숫자면 따옴표 X
문자면 따옴표 O
날짜/시간이면 따옴표 O
함수 결과는 "반환 타입" 기준

WHERE id = 1                  -- INT
WHERE name = 'Alice'         -- VARCHAR
WHERE created_at = '2026-07-02' -- DATE
WHERE YEAR(created_at) = 2026   -- YEAR() -> INT
WHERE MONTH(created_at) IN (1, 2, 3)
WHERE DAYNAME(created_at) = 'Monday' -- 문자열 반환
*/