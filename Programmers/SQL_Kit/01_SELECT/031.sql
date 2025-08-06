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

-- PERCENT_RANK() OVER (ORDER BY 속성 DESC) : 속성의 값들을 내림차순 정렬 후 비율 부여