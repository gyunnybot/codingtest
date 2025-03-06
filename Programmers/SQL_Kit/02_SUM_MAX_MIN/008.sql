SELECT FISH_INFO.ID, FISH_NAME_INFO.FISH_NAME, FISH_INFO.LENGTH
FROM FISH_INFO LEFT OUTER JOIN FISH_NAME_INFO
ON FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
WHERE (FISH_INFO.FISH_TYPE, FISH_INFO.LENGTH) IN (
                                                  SELECT FISH_TYPE, MAX(LENGTH) AS LENGTH
                                                  FROM FISH_INFO
                                                  GROUP BY FISH_TYPE
                                                 )
ORDER BY FISH_INFO.ID;

-- GROUP BY로 묶어서 그룹별로 집계함수의 값을 개별적으로 구할 수 있다
-- 001.sql의 경우 전체 레코드 중 값이 겹치는 속성이 없으므로 중첩 쿼리 활용