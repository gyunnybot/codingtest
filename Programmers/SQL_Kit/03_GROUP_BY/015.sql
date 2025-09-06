SET @hour := -1; -- SET @A := INTEGER -> INTEGER 타입의 변수 @A 선언

SELECT (@hour := @hour + 1) AS HOUR, ( -- 0부터~
    SELECT COUNT(*)
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) = @hour
) AS COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23; -- 23까지