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

-- Crie uma view chamada TotalPorCliente que mostre, para cada cliente que já realizou corridas, o nome do cliente e o valor total que ele gastou em todas as corridas.
CREATE VIEW TotalPorCliente as select cliente.nome, sum(corrida.valor) as TotalGasto FROM cliente  JOIN corrida ON cliente.cliid = corrida.cliid GROUP BY 1;

-- Crie uma view chamada CorridasPorTaxi que mostre o número total de corridas realizadas por cada táxi.
CREATE VIEW CorridasPorTaxi AS SELECT placa, COUNT(placa) as QuantidadeCorridas FROM corrida GROUP BY 1;

-- Crie uma view chamada ClientesSemCorrida que mostre os nomes dos clientes que nunca fizeram nenhuma corrida.
CREATE VIEW ClientesSemCorrida AS SELECT cliente.nome FROM cliente LEFT JOIN corrida ON cliente.cliid = corrida.cliid WHERE corrida.cliid is NULL;