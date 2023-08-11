SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId = d.id
WHERE (e.salary, d.name) IN (
    SELECT DISTINCT e1.salary, d1.name
    FROM Employee e1
    JOIN Department d1 ON e1.departmentId = d1.id
    WHERE (
        SELECT COUNT(DISTINCT e2.salary)
        FROM Employee e2
        WHERE e2.departmentId = e1.departmentId AND e2.salary >= e1.salary
    ) <= 3
);
