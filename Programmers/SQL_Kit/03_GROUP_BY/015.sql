SET @hour := -1; -- SET @NAME := INTEGER -> @NAME 변수 선언

SELECT (@hour := @hour + 1) AS HOUR, (
    SELECT COUNT(*)
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) = @hour
) AS COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23;