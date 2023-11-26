CREATE DATABASE vacation_data;

\c vacation_data

CREATE TABLE employees (
  id int NOT NULL AUTO_INCREMENT,
  name varchar(90),
  startofvacation DATE,
  endofvacation DATE
);

CREATE TABLE  standards (
   month_name varchar (10),
   numberofemployees int
);

INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Иван Иванович', '2023-11-05','2023-11-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Олег Иванович', '2023-12-05','2023-12-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Михаил Иванович', '2023-10-05','2023-10-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Степан Иванович', '2023-03-05','2023-03-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Роман Иванович', '2023-04-05','2023-04-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Данил Иванович', '2023-05-05','2023-05-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Илья Иванович', '2023-11-05','2023-11-26'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Павел Иванович', '2023-11-06','2023-11-26'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Ростислав Иванович', '2023-11-03','2023-11-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Дмитрий Иванович', '2023-11-07','2023-11-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Сергей Иванович', '2023-05-05','2023-05-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Максим Иванович', '2023-05-05','2023-05-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Игорь Иванович', '2023-05-05','2023-05-21'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Артем Иванович', '2023-05-05','2023-05-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Николай Иванович', '2023-05-05','2023-05-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Владимир Иванович', '2023-10-05','2023-10-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Виктор Иванович', '2023-09-05','2023-09-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Владислав Иванович', '2023-12-06','2023-12-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Филипп Иванович', '2023-11-06','2023-11-22'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Петр Иванович', '2023-01-05','2023-01-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Алексей Иванович', '2023-02-05','2023-02-25'); 
INSERT INTO employees (name, startofvacation, endofvacation) VALUES ('Иванов Александр Иванович', '2023-03-05','2023-03-25'); 

INSERT INTO standards (month_name, numberofemployees) VALUES ('ЯНВАРЬ', 3);
INSERT INTO standards (month_name, numberofemployees) VALUES ('ФЕВРАЛЬ', 4);
INSERT INTO standards (month_name, numberofemployees) VALUES ('МАРТ', 4);
INSERT INTO standards (month_name, numberofemployees) VALUES ('АПРЕЛЬ', 5);
INSERT INTO standards (month_name, numberofemployees) VALUES ('МАЙ', 4);
INSERT INTO standards (month_name, numberofemployees) VALUES ('ИЮНЬ', 6);
INSERT INTO standards (month_name, numberofemployees) VALUES ('ИЮЛЬ', 7);
INSERT INTO standards (month_name, numberofemployees) VALUES ('АВГУСТ', 7);
INSERT INTO standards (month_name, numberofemployees) VALUES ('СЕНТЯБРЬ', 10);
INSERT INTO standards (month_name, numberofemployees) VALUES ('ОКТЯБРЬ', 2);
INSERT INTO standards (month_name, numberofemployees) VALUES ('НОЯБРЬ', 5);
INSERT INTO standards (month_name, numberofemployees) VALUES ('ДЕКАБРЬ', 5); 

CREATE ROLE username LOGIN PASSWORD 'username';

GRANT CONNECT ON DATABASE vacation_data TO username;
GRANT USAGE ON SCHEMA public TO username;
GRANT SELECT ON ALL TABLES IN SCHEMA public TO username;