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

INSERT INTO Snake_HS(id, Score) VALUES(1,37);
INSERT INTO Snake_HS(id, Score) VALUES(2,57);
INSERT INTO Snake_HS(id, Score) VALUES(3,39);
INSERT INTO Snake_HS(id, Score) VALUES(4,42);

SELECT players.player_id, Snake_HS.Score, Snake_HS.Score_date
FROM Snake_HS
JOIN players
ON players.id = Snake_HS.id;
