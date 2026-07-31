SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_OUTS AS O LEFT OUTER JOIN ANIMAL_INS AS I
ON O.ANIMAL_ID = I.ANIMAL_ID
WHERE I.ANIMAL_ID IS NULL
ORDER BY O.ANIMAL_ID;

-- ANIMAL_OUTS 테이블의 ANIMAL_ID는 ANIMAL_INS의 ANIMAL_ID의 외래 키입니다. 원래는 I LFET OUTER JOIN O가 맞음

-- 그러나 일부 데이터가 유실되었으므로, OUTS에는 있는데 INS에는 없는 ID가 존재할 수 있음. 반대도 마찬가지
-- 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물 -> 문제 요구 사항에 따라 O LEFT OUTER JOIN I로 작성