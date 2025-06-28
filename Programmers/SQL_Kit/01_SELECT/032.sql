SELECT ID -- 3세대
FROM ECOLI_DATA 
WHERE PARENT_ID IN (
                    SELECT ID -- 2세대
                    FROM ECOLI_DATA 
                    WHERE PARENT_ID IN (
                                        SELECT ID -- 1세대
                                        FROM ECOLI_DATA 
                                        WHERE PARENT_ID IS NULL
                                       )
                   )
ORDER BY ID ASC;