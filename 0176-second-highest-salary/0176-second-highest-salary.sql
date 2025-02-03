# Write your MySQL query statement below
-- SELECT DISTINCT MAX(salary) FROM Employee
-- WHERE salary < (SELECT MAX(Salary) FROM Employee0);

# Write your MySQL query statement below
SELECT DISTINCT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);

-- // SELECT 
--     IFNULL(
--         (SELECT DISTINCT salary 
--          FROM Employee 
--          ORDER BY salary DESC 
--          LIMIT 1 OFFSET 1), 
--     NULL) AS SecondHighestSalary;