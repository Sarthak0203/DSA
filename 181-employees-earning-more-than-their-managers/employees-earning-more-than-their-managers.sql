# Write your MySQL query statement below
select Employee.name as Employee from Employee join Employee as Manager on Employee.managerId = Manager.id where Employee.salary > Manager.salary