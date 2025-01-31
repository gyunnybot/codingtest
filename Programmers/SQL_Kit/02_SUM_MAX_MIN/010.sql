SELECT YEAR(A.DIFFERENTIATION_DATE) AS YEAR, ABS(A.SIZE_OF_COLONY - B.MAX_VAL) AS YEAR_DEV, A.ID
FROM ECOLI_DATA AS A LEFT OUTER JOIN (
                                        SELECT MAX(SIZE_OF_COLONY) AS MAX_VAL, YEAR(DIFFERENTIATION_DATE) AS YEAR
                                        FROM ECOLI_DATA
                                        GROUP BY YEAR
                                     ) AS B
ON YEAR(A.DIFFERENTIATION_DATE) = B.YEAR
ORDER BY YEAR, YEAR_DEV;