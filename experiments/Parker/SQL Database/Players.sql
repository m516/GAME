use game_database;

Select * from Players;
-- TABLE FOR STORING ID#S, FIRST NAME, LAST NAME, USERNAME, AND DATE JOINED
CREATE TABLE Players (
	player_id INT AUTO_INCREMENT,
    first_name VARCHAR(20),
    last_name VARCHAR(20),
	username VARCHAR(20) UNIQUE,
    primary key(player_id)
);

Describe Players;

INSERT INTO Players(first_name, last_name, username) VALUES('Isaac', 'Spainer', 'Isaac_S');

