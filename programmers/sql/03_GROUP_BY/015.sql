SET @hour := -1; -- SET @A := val -> 변수 @A를 생성 후, val로 초기화

SELECT (@hour := @hour + 1) AS HOUR, ( -- @hour에 (@hour + 1) 값을 넣고, 그 결과를 반환한다. do-while처럼 한 번은 반드시 실행?
    SELECT COUNT(*)
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) = @hour
) AS COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23; -- @hour = 22까지 실행 -> @hour := @hour + 1로 23까지 출력