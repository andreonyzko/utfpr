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
  Valor NUMERIC(8,2) NOT NULL,
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
INSERT INTO Corrida VALUES ('1755', 'DAE6534', '2003-02-15', 15.0);
INSERT INTO Corrida VALUES ('1780', 'JDM8776', '2003-02-18', 20.0);
INSERT INTO Corrida VALUES ('1755', 'DKL7878', '2003-02-16', 10.0);
INSERT INTO Corrida VALUES ('1780', 'DKL4598', '2003-02-17', 30.0);
INSERT INTO Corrida VALUES ('1532', 'DKL4598', '2003-02-18', 15.0);
INSERT INTO Corrida VALUES ('1780', 'DAE6534', '2003-02-16', 40.0);
INSERT INTO Corrida VALUES ('1755', 'DAE6534', '2003-02-18', 20.0);
INSERT INTO Corrida VALUES ('1532', 'DKL4598', '2003-02-20', 15.0);

-- Liste o nome dos clientes e as datas em que solicitaram corridas.
SELECT cliente.nome, corrida.DataPedido FROM corrida INNER JOIN cliente ON cliente.cliid = corrida.cliid;

-- Exiba os modelos dos táxis que foram utilizados em corridas, sem repetir valores (usar distinct).
SELECT DISTINCT(taxi.modelo) FROM taxi JOIN corrida ON taxi.placa = corrida.placa;

-- Liste o nome dos clientes que solicitaram corridas em táxis da marca "Ford".
SELECT cliente.nome FROM cliente JOIN corrida ON cliente.cliid = corrida.cliid JOIN taxi ON corrida.placa = taxi.placa WHERE taxi.marca = 'Ford' ORDER BY cliente.nome;

-- Recupere a quantidade total de corridas realizadas por cada cliente, exibindo o nome do cliente e o número de corridas.
SELECT cliente.nome, COUNT(corrida.cliid) AS TotalCorridas FROM cliente JOIN corrida ON cliente.cliid = corrida.cliid GROUP BY 1

-- Liste os clientes que solicitaram mais de duas corridas, exibindo o nome e a quantidade de corridas.
SELECT cliente.nome, COUNT(corrida.cliid) AS TotalCorridas FROM cliente JOIN corrida ON cliente.cliid = corrida.cliid GROUP BY 1 HAVING COUNT(2) > 2;

-- Mostre a marca e modelo do táxi mais utilizado em corridas.
SELECT taxi.marca, taxi.modelo, COUNT(corrida.placa) as TotalCorridas FROM corrida JOIN taxi on corrida.placa = taxi.placa GROUP BY 1, 2  ORDER BY COUNT(corrida.placa) DESC LIMIT 1;

-- Exiba a placa dos táxis que nunca foram utilizados em corridas.
SELECT placa FROM taxi WHERE placa NOT IN (SELECT DISTINCT(placa) FROM corrida);

-- Liste o nome dos clientes e o valor total gasto por cada um em corridas.
SELECT cliente.nome, SUM(corrida.valor) AS TotalGasto FROM cliente JOIN corrida ON cliente.cliid = corrida.cliid GROUP BY 1;

-- Liste a marca e o modelo do táxi que gerou a maior receita em corridas.
SELECT taxi.marca, taxi.modelo, SUM(corrida.valor) as Receita FROM corrida JOIN taxi ON corrida.placa = taxi.placa group BY 1,2 ORDER BY SUM(corrida.valor) DESC LIMIT 1;

-- Liste os clientes que fizeram pelo menos uma corrida com valor acima de 30.00.
SELECT cliente.nome FROM cliente JOIN corrida ON cliente.cliid = corrida.cliid WHERE corrida.valor >= 30 GROUP BY 1;