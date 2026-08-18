# Write your MySQL query statement below
SELECT employee_id,
        case 
             when employee_id % 2 = 1
               and name NOT LIKE 'M%'
             THEN salary
             ELSE 0
        end AS bonus
     FROM Employees
     ORDER BY employee_id ASC;