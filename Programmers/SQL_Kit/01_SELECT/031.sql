SELECT A.ID, CASE WHEN A.PER > 0.75 THEN 'LOW'
                  WHEN A.PER > 0.5 THEN 'MEDIUM'
                  WHEN A.PER > 0.25 THEN 'HIGH'
                  ELSE 'CRITICAL'
             END AS COLONY_NAME
FROM (
        SELECT ID, PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS PER
        FROM ECOLI_DATA        
     ) AS A
ORDER BY A.ID;

-- PERCENT_RANK() OVER (ORDER BY 비율을 나눌 속성 DESC) : 속성의 값들을 백분위로 나누기