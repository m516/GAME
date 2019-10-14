use company;

SELECT *
From employee
order by salary desc;

Select *
From employee
order by sex, first_name, last_name;

select first_name as forename, last_name as surname
from employee;

Select distinct branch_id
from employee;

-- Functions
Select count(super_id)
from employee;

select count(emp_id)
from employee
where sex = 'F' and birth_day > '1971-01-01';

select avg(salary)
from employee
where sex = 'M';

select avg(salary)
from employee
where sex = 'F';

select sum(salary)
from employee;

select count(sex), sex
from employee
group by sex;

select sum(total_sales), emp_id
from works_with
group by emp_id;

select sum(total_sales), client_id
from works_with
group by client_id;

-- Wildcards
 



 