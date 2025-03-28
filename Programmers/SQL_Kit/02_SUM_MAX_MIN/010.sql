SELECT YEAR(A.DIFFERENTIATION_DATE) AS YEAR, B.MAX_SIZE - A.SIZE_OF_COLONY AS YEAR_DEV, A.ID
FROM ECOLI_DATA AS A LEFT OUTER JOIN (
                                      SELECT YEAR(DIFFERENTIATION_DATE) AS Y, MAX(SIZE_OF_COLONY) AS MAX_SIZE
                                      FROM ECOLI_DATA
                                      GROUP BY Y
                                     ) AS B
ON YEAR(A.DIFFERENTIATION_DATE) = B.Y -- 조건절에서는 완성되지 않은 테이블 속성의 alias를 사용할 수 없다
ORDER BY YEAR, YEAR_DEV;