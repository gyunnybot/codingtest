SELECT HR_EMPLOYEES.EMP_NO, HR_EMPLOYEES.EMP_NAME, CASE WHEN AVG(HR_GRADE.SCORE) >= 96 THEN 'S'
                                                        WHEN AVG(HR_GRADE.SCORE) >= 90 THEN 'A'
                                                        WHEN AVG(HR_GRADE.SCORE) >= 80 THEN 'B'
                                                        ELSE 'C'
                                                   END AS GRADE, 
                                                   CASE WHEN AVG(HR_GRADE.SCORE) >= 96 THEN HR_EMPLOYEES.SAL * 0.2
                                                        WHEN AVG(HR_GRADE.SCORE) >= 90 THEN HR_EMPLOYEES.SAL * 0.15
                                                        WHEN AVG(HR_GRADE.SCORE) >= 80 THEN HR_EMPLOYEES.SAL * 0.1
                                                        ELSE 0
                                                   END AS BONUS
FROM HR_EMPLOYEES LEFT OUTER JOIN HR_GRADE
ON HR_EMPLOYEES.EMP_NO = HR_GRADE.EMP_NO
GROUP BY HR_EMPLOYEES.EMP_NO, HR_EMPLOYEES.EMP_NAME
ORDER BY HR_EMPLOYEES.EMP_NO ASC;