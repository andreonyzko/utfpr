DROP TABLE IF EXISTS Taxi;
DROP TABLE IF EXISTS Cliente;
DROP TABLE IF EXISTS Corrida;

CREATE TABLE Taxi (
  Placa VARCHAR(7) NOT NULL,
  Marca VARCHAR(30) NOT NULL,
  Modelo VARCHAR(30) NOT NULL,
  AnoFab INTEGER,
  Licenca VARCHAR(9),
  PRIMARY KEY(Placa)
);

CREATE TABLE Cliente (
  CliId VARCHAR(4) NOT NULL,
  Nome VARCHAR(80) NOT NULL,
  CPF VARCHAR(14) NOT NULL,
  PRIMARY KEY(CliId)
);

CREATE TABLE Corrida (
  CliId VARCHAR(4) NOT NULL,
  Placa VARCHAR(7) NOT NULL,
  DataPedido DATE NOT NULL,
  PRIMARY KEY(CliId, Placa, DataPedido),
  FOREIGN KEY(CliId)
    REFERENCES Cliente(CliId)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION,
  FOREIGN KEY(Placa)
    REFERENCES Taxi(Placa)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);

INSERT INTO Cliente VALUES ('1532', 'Asdrúbal', '448.754.253-65');
INSERT INTO Cliente VALUES ('1755', 'Doriana', '567.387.387-44');
INSERT INTO Cliente VALUES ('1780', 'Quincas', '546.373.762-02');
INSERT INTO Cliente VALUES ('1888', 'Melissa', '123.456.789-10');
INSERT INTO Taxi VALUES ('DAE6534', 'Ford', 'Fiesta', 1999, 'MN572345');
INSERT INTO Taxi VALUES ('DKL4598', 'Wolkswagen', 'Gol', 2001, 'AU876543');
INSERT INTO Taxi VALUES ('DKL7878', 'Ford', 'Fiesta', 2001, 'OP102938');
INSERT INTO Taxi VALUES ('JDM8776', 'Wolkswagen', 'Santana', 2002, 'QM365923');
INSERT INTO Taxi VALUES ('JJM3692', 'Chevrolet', 'Corsa', 1999, 'UU335577');
INSERT INTO Corrida VALUES ('1755', 'DAE6534', '2003-02-15');
INSERT INTO Corrida VALUES ('1780', 'JDM8776', '2003-02-18');
INSERT INTO Corrida VALUES ('1755', 'DKL7878', '2003-02-16');
INSERT INTO Corrida VALUES ('1780', 'DKL4598', '2003-02-17');
INSERT INTO Corrida VALUES ('1532', 'DKL4598', '2003-02-18');
INSERT INTO Corrida VALUES ('1780', 'DAE6534', '2003-02-16');
INSERT INTO Corrida VALUES ('1755', 'DAE6534', '2003-02-18');
INSERT INTO Corrida VALUES ('1532', 'DKL4598', '2003-02-20');

-- Crie um comando SQL para listar todos os registros da tabela taxi.
SELECT * FROM taxi;

-- Crie um comando SQL para listar Marca e Modelo dos Taxis disponíveis.
SELECT marca, modelo FROM taxi;

-- Crie um comando SQL para listar Taxis fabricados depois do ano 2000.
SELECT * FROM taxi WHERE anofab > 2000;

-- Crie um comando SQL para listar Placas que comecem com DK.
SELECT placa FROM taxi WHERE placa LIKE 'DK%';

-- Crie um comando SQL para listar Placas com 7 na última posição.
SELECT placa FROM taxi WHERE placa LIKE '%7_';

-- Crie um comando SQL para listar Corridas que aconteceram depois do dia 17/02/2003.
SELECT * FROM corrida WHERE datapedido > '2003-02-17';

-- Crie um comando SQL para listar Corridas que aconteceram entre dia 17/02/2003 e 18/02/2003.
SELECT * FROM corrida WHERE datapedido BETWEEN '2003-02-17' and '2003-02-18';

-- Crie um comando SQL para listar Corridas com CliId menor que 1770.
SELECT * FROM corrida WHERE cliid < 1770;

-- Crie um comando SQL para listar Corridas em que a Placa termine com 8 e que a DataPedido seja maior que 17/02/2003.
SELECT * FROM corrida WHERE placa LIKE '%8' AND datapedido > '2003-02-17';

-- Crie um comando SQL para criar o produto cartesiano entre Clientes e Corridas.
SELECT * FROM cliente CROSS JOIN corrida;