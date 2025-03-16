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

-- PERCENT_RANK() OVER (ORDER BY 비율을 나눌 속성) : 속성의 값을 전체 데이터 기반의 백분율 값으로 환산