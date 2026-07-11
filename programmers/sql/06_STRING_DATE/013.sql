SELECT ANIMAL_ID, NAME, CASE WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%' THEN 'O'
                             ELSE 'X'
                             END AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;

-- IN은 "정확히 같은 값"을 비교하고, %는 LIKE에서만 와일드카드로 동작한다
-- SEX_UPON_INTAKE IN ('%Neutered%', '%Spayed%') 불가능