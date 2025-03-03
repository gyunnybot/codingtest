SELECT FISH_INFO.ID, FISH_NAME_INFO.FISH_NAME, FISH_INFO.LENGTH
FROM FISH_INFO LEFT OUTER JOIN FISH_NAME_INFO
ON FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
WHERE (FISH_INFO.FISH_TYPE, FISH_INFO.LENGTH) IN (
                                                  SELECT FISH_TYPE, MAX(LENGTH)
                                                  FROM FISH_INFO
                                                  GROUP BY FISH_TYPE
                                                 )
ORDER BY FISH_INFO.ID;

-- GROUP BY로 묶어서 그룹별로 최대값을 각각 구할 수 있다
-- 001.sql의 경우 전체에서 최대값을 요구하고 있기 때문에 중첩문을 활용해야 한다