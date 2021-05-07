CREATE TABLE J
(
    j_num VARCHAR(4) NOT NULL PRIMARY KEY,
    jname VARCHAR(12) NOT NULL,
    city VARCHAR(10) NOT NULL
);

CREATE Table P
(
    p_num VARCHAR(4) NOT NULL PRIMARY KEY,
    pname VARCHAR(12) NOT NULL,
    color VARCHAR(10) NOT NULL,
    weight INT(5) NOT NULL,
    city VARCHAR(10) NOT NULL
);

CREATE TABLE S
(
    s_num VARCHAR(4) PRIMARY KEY,
    s_name VARCHAR(12),
    status INT(4), 
    city VARCHAR(10)
);

CREATE TABLE SPJ
(
     s_num VARCHAR(4),
     p_num VARCHAR(4),
     j_num VARCHAR(4),
     qty INT(5),
     PRIMARY KEY (s_num,p_num,j_num),
     FOREIGN KEY (s_num) REFERENCES S(s_num) on delete CASCADE,
     FOREIGN KEY (p_num) REFERENCES P(p_num) on delete CASCADE,
     FOREIGN KEY (j_num) REFERENCES J(j_num) on delete CASCADE
);

INSERT INTO 
    J (j_num, jname, city) 
VALUES 
    ("j1",	"Sorter",	"Paris"),
    ("j2",	"Punch",	"Rome"),
    ("j3",	"Reader",	"Athens"),
    ("j4",	"Console",	"Athens"),
    ("j5",	"Collator",	"London"),
    ("j6",	"Terminal",	"Oslo"),
    ("j7",	"Tape",	    "London");

INSERT INTO
    P (p_num, pname, color, weight, city)
VALUES
    ('p1','Nut','Red',12, 'London'),
    ('p2','Bolt','Green',17, 'Paris'),
    ('p3','Screw','Blue',17, 'Rome'),
    ('p4','Screw','Red',14, 'London'),
    ('p5','Cam','Blue',12,'Paris'),
    ('p6','Cog','Red',19,'London');

INSERT INTO
    S (s_num, s_name, status, city)
VALUES
    ('s1','Smith',20,'London'),
    ('s2','Jones',10,'Paris'),
    ('s3','Blake',30,'Paris'),
    ('s4','Clark',20,'London'),
    ('s5','Adams',30,'Athens');

INSERT INTO
    SPJ (s_num, p_num, j_num, qty)
VALUES
    ('s1','p1','j1',200),
    ('s1','p1','j4',700),
    ('s2','p3','j1',400),
    ('s2','p3','j2',200),
    ('s2','p3','j3',200),
    ('s2','p3','j4',500),
    ('s2','p3','j5',600),
    ('s2','p3','j6',400),
    ('s2','p3','j7',800),
    ('s2','p5','j2',100),
    ('s3','p3','j1',200),
    ('s3','p4','j2',500),
    ('s4','p6','j3',300),
    ('s4','p6','j7',300),
    ('s5','p1','j4',100),
    ('s5','p2','j2',200),
    ('s5','p2','j4',100),
    ('s5','p3','j4',200),
    ('s5','p4','j4',800),
    ('s5','p5','j4',400),
    ('s5','p5','j5',500),
    ('s5','p5','j7',100),
    ('s5','p6','j2',200),
    ('s5','p6','j4',500);
