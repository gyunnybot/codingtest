SELECT YEAR(A.DIFFERENTIATION_DATE) AS YEAR, B.MAX_SIZE - A.SIZE_OF_COLONY AS YEAR_DEV, A.ID
FROM ECOLI_DATA AS A LEFT OUTER JOIN (
                                      SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR, MAX(SIZE_OF_COLONY) AS MAX_SIZE
                                      FROM ECOLI_DATA
                                      GROUP BY YEAR -- ORDER BY, GROUP BY 절은 테이블이 완성되지 않아도 속성의 alias가 적용된다
                                     ) AS B
ON YEAR(A.DIFFERENTIATION_DATE) = B.YEAR -- WHERE, ON 절은 테이블이 완성되지 않으면 속성에 대한 alias가 적용되지 않는다. (테이블 alias는 적용 가능)
ORDER BY YEAR, YEAR_DEV; -- ORDER BY, GROUP BY 절은 테이블이 완성되지 않아도 속성의 alias가 적용된다