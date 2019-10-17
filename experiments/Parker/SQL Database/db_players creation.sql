use db_players;

DROP TABLE Snake_HS;
DROP TABLE players;

CREATE TABLE players(
	id INT AUTO_INCREMENT PRIMARY KEY ,
    first_name VARCHAR(20),
    last_name VARCHAR(20),
    player_id VARCHAR(20) UNIQUE,
    data DATE
);

CREATE TABLE Snake_HS(
	id INT PRIMARY KEY,
    Score INT,
    Score_date DATE,
    FOREIGN KEY(id) REFERENCES players(id) ON DELETE CASCADE
    );
    
INSERT INTO players(first_name, last_name, player_id) VALUES('Parker', 'Larsen', 'Parker_L');
INSERT INTO players(first_name, last_name, player_id) VALUES('Isaac', 'Spanier', 'Isaac_S');
INSERT INTO players(first_name, last_name, player_id) VALUES('Micah', 'Mundy', 'Micah_M');
INSERT INTO players(first_name, last_name, player_id) VALUES('Ashton', 'Nelson', 'Ashton_N');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a1');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b1');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a2');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b2');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a3');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b3');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a4');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b4');
INSERT INTO players(first_name, last_name, player_id) VALUES('r', 'r', 'a5');
INSERT INTO players(first_name, last_name, player_id) VALUES('R', 'R', 'b5');

INSERT INTO Snake_HS(id, Score) VALUES(1,37);
INSERT INTO Snake_HS(id, Score) VALUES(2,57);
INSERT INTO Snake_HS(id, Score) VALUES(3,39);
INSERT INTO Snake_HS(id, Score) VALUES(4,42);
INSERT INTO Snake_HS(id, Score) VALUES(5,37);
INSERT INTO Snake_HS(id, Score) VALUES(6,57);
INSERT INTO Snake_HS(id, Score) VALUES(7,39);
INSERT INTO Snake_HS(id, Score) VALUES(8,42);
INSERT INTO Snake_HS(id, Score) VALUES(9,37);
INSERT INTO Snake_HS(id, Score) VALUES(10,57);
INSERT INTO Snake_HS(id, Score) VALUES(11,39);
INSERT INTO Snake_HS(id, Score) VALUES(12,42);

-- Only keeps the top 10 scores
delete from Snake_HS where id in (select * from (
select id from Snake_HS order by Score desc limit 10,18446744073709551615) as t);

SELECT players.player_id, Snake_HS.Score, Snake_HS.Score_date
FROM Snake_HS
JOIN players
ON players.id = Snake_HS.id;