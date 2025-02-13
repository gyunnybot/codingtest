SELECT A.ID, IFNULL(B.CHILD_COUNT, 0) AS CHILD_COUNT
FROM ECOLI_DATA AS A LEFT OUTER JOIN (
                                        SELECT PARENT_ID, COUNT(*) AS CHILD_COUNT
                                        FROM ECOLI_DATA
                                        WHERE PARENT_ID IS NOT NULL
                                        GROUP BY PARENT_ID
                                     ) AS B
ON A.ID = B.PARENT_ID
ORDER BY ID ASC;

-- IFNULL(속성, 대신할 값) : 필드 값이 NULL일 때 대신할 값 삽입되어 출력