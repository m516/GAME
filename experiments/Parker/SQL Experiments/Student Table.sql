use parker_test;
Select * from student;

Describe student;

Drop Table student;

Create table student (
	student_id INT,
    name VARCHAR(20),
    major VARCHAR(20),
    primary key(student_id)
);

Create table student (
	student_id INT,
    name VARCHAR(20) NOT NULL,
    major VARCHAR(20) UNIQUE,  
     primary key(student_id)
);
#DEFAULT 'undecided;
#INT AUTO_INCREMENT;

ALTER TABLE student ADD gpa DECIMAL(3,2);

ALTER TABLE student DROP gpa;

INSERT INTO student VALUES(1, 'Jack', 'Biology');
INSERT INTO student VALUES(2, 'Katie', 'Sociology');
INSERT INTO student VALUES(3, 'Claire', 'English');
INSERT INTO student VALUES(4, 'Jack', 'Biology');
INSERT INTO student VALUES(5, 'Mike', 'Computer Science');

INSERT INTO student(student_id, name) VALUES(3,'Claire');

UPDATE student 
SET major = 'Com Sci'
WHERE major = 'Computer Science';

UPDATE student
SET major = 'Com Sci'
WHERE student_id = 4;

UPDATE student
SET major = 'Biochemistry'
WHERE major = 'Bio' OR major = 'Chemistry';

UPDATE student
SET name = 'Tom', major = 'undecided'
WHERE student_id = 1;

DELETE FROM student
WHERE student_id = 5;

SELECT student.name, student.major
FROM student
ORDER BY name DESC;
 
 SELECT student.name, student.major
FROM student
ORDER BY student_id asc;

 SELECT student_id, student.name
FROM student
ORDER BY student_id asc
LIMIT 2;

SELECT name, major
From student
WHERE major = 'Chemisty' OR name = 'Kate';

#<,>,<=,>=,=,<>,AND, OR

SELECT name, major
FROM student
WHERE student_id < 3;

SELECT *
FROM student
WHERE name IN ('Claire', 'Kate', 'Mike');

