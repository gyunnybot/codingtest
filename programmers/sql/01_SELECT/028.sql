SELECT ID, CASE WHEN SIZE_OF_COLONY <= 100 THEN 'LOW'
                WHEN 100 < SIZE_OF_COLONY AND SIZE_OF_COLONY <= 1000 THEN 'MEDIUM'
                ELSE 'HIGH'
                END AS SIZE
FROM ECOLI_DATA
ORDER BY ID ASC;

/*
CASE WHEN 조건문 1 THEN 결과 1
        WHEN 조건문 2 THEN 결과 2
        ELSE 결과 3
        END AS '별명 컬럼'
*/