-- 재귀적인 테이블 PARENT 생성
WITH RECURSIVE PARENT AS (
                          -- 반복되지 않는 구문에서 새로운 레이블 GENERATION 선언
                          SELECT ID, PARENT_ID, 1 AS GENERATION -- 초기 세대 값을 1로 설정
                          FROM ECOLI_DATA
                          WHERE PARENT_ID IS NULL

                          UNION -- 중복을 포함하지 않는 합집합

                          -- 반복되는 구문에서 GENERATION을 1씩 추가한다
                          SELECT CHILD.ID, CHILD.PARENT_ID, PARENT.GENERATION + 1 AS GENERATION
                          FROM ECOLI_DATA AS CHILD, PARENT
                          WHERE PARENT.ID = CHILD.PARENT_ID
                         )

SELECT COUNT(ID) AS COUNT, GENERATION
FROM PARENT -- 재귀 테이블을 기반으로 결과 테이블 생성
WHERE ID NOT IN ( -- 자식이 없는 대장균 = 부모가 아닌 대장균
                 SELECT IFNULL(PARENT_ID, 0) AS PARENT_ID -- NULL의 NOT IN 연산은 값이 부정확하므로 IFNULL 처리
                 FROM ECOLI_DATA
                )
GROUP BY GENERATION
ORDER BY GENERATION;