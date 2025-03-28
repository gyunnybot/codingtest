SELECT A.ID, CASE WHEN A.PER <= 0.25 THEN 'CRITICAL'
                  WHEN A.PER <= 0.5 THEN 'HIGH'
                  WHEN A.PER <= 0.75 THEN 'MEDIUM'
                  ELSE 'LOW'
             END AS COLONY_NAME
FROM (
      SELECT ID, PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS PER
      FROM ECOLI_DATA        
     ) AS A
ORDER BY A.ID;

-- PERCENT_RANK() OVER (ORDER BY 비율을 나눌 속성) : 속성 값을 전체 기준 백분율로 환산